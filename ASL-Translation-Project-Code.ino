// ASL Translation Glove Prototype

// Flex sensor pins
const int flexPins[5] = {A0, A1, A2, A3, A6};  // Index, Middle, Ring, Pinky, Thumb
const int wristPin = A7;

// Thresholds
const int bentThreshold = 200;
const int midThreshold  = 800;

// Convert raw value to discrete state (0 = bent, 1 = mid, 2 = straight)
int getState(int value) {
  if (value < bentThreshold) return 0;
  else if (value < midThreshold) return 1;
  else return 2;
}

// Finger pattern for ASL alphabet
// Format: {Index, Middle, Ring, Pinky, Thumb, 'Letter'}
struct ASLPattern {
  int fingers[5];
  char letter;
};

// Define patterns (you will need to fine-tune based on your glove)
ASLPattern patterns[] = {
  {{0,0,0,0,2}, 'A'},  // A: all bent, thumb straight
  {{2,2,2,2,0}, 'B'},  // B: fingers straight, thumb bent
  {{1,1,1,1,1}, 'C'},  // C: all mid (curved)
  {{2,0,0,0,0}, 'D'},  // D: index straight, rest bent
  {{0,0,0,0,0}, 'E'},  // E: all bent
  {{2,2,0,0,2}, 'F'},  // F: thumb + index make circle, others straight
  {{2,2,0,0,0}, 'G'},  
  {{2,2,0,0,0}, 'H'},  
  {{0,0,0,2,0}, 'I'},  
  {{2,0,0,0,2}, 'K'},  
  {{2,0,0,0,0}, 'L'},  
  {{0,0,0,0,0}, 'M'},  // adjust for overlapping fingers
  {{0,0,0,0,0}, 'N'},  
  {{1,1,1,1,1}, 'O'},  
  {{2,2,0,0,2}, 'P'},  
  {{2,0,0,0,0}, 'Q'},  
  {{2,2,0,0,0}, 'R'},  
  {{0,0,0,0,0}, 'S'},  
  {{0,0,0,0,2}, 'T'},  
  {{2,2,0,0,0}, 'U'},  
  {{2,2,0,0,0}, 'V'},  
  {{2,2,2,0,0}, 'W'},  
  {{0,2,0,0,0}, 'X'},  
  {{0,0,0,2,2}, 'Y'},  
  {{2,0,2,0,0}, 'Z'}   // Z: tricky, usually motion-based
};

const int numPatterns = sizeof(patterns)/sizeof(patterns[0]);

void setup() {
  Serial.begin(9600);
}

void loop() {
  // Read sensors
  int values[5];
  int states[5];
  for (int i = 0; i < 5; i++) {
    values[i] = analogRead(flexPins[i]);
    states[i] = getState(values[i]);
  }
  
  // Match against patterns
  char detected = '?';
  for (int i = 0; i < numPatterns; i++) {
    bool match = true;
    for (int f = 0; f < 5; f++) {
      if (patterns[i].fingers[f] != states[f]) {
        match = false;
        break;
      }
    }
    if (match) {
      detected = patterns[i].letter;
      break;
    }
  }

  // Print result
  if (detected != '?') {
    Serial.println(detected);
  } else {
    Serial.println("Unknown");
  }

  delay(500);
}
