//   _________                                         
//  /   _____/ ____ _____    ____   ____   ___________ 
//  \_____  \_/ ___\\__  \  /    \ /    \_/ __ \_  __ \
//  /        \  \___ / __ \|   |  \   |  \  ___/|  | \/
// /_______  /\___  >____  /___|  /___|  /\___  >__|   
//         \/     \/     \/     \/     \/     \/       
// 

// Use slider A3 for intensity control.
void runScanner(int color) {
  for (int i = 0; i < 1000; ++i) {
    analogWrite(color, map(analogRead(3), 0, 1024, 0, 100));
    delay(10);
  }
  analogWrite(color, 0);
}

