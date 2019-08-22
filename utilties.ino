// .___        __                             .__          
// |   | _____/  |_  ___________  ____ _____  |  |   ______
// |   |/    \   __\/ __ \_  __ \/    \\__  \ |  |  /  ___/
// |   |   |  \  | \  ___/|  | \/   |  \/ __ \|  |__\___ \ 
// |___|___|  /__|  \___  >__|  |___|  (____  /____/____  >
//          \/          \/           \/     \/          \/ 
// 

bool flying = false;

void setup() {
  pinMode(4, OUTPUT);
  pinMode(5, OUTPUT);
  pinMode(6, OUTPUT);
  pinMode(7, OUTPUT);
  pinMode(8, OUTPUT);
  pinMode(12, INPUT);
}

void loop() {
  if ( buttonIsPressed() ) startNavigationSequence();
  else cancelNavigationSequence();
  if (flying) {
    executeFlightPlan();
    endTurn();
  }
}

bool buttonIsPressed() {
  return digitalRead(12) == HIGH;
}

void startNavigationSequence() {
  flying = true;
}

void cancelNavigationSequence() {
  flying = false;
}

void turnLeft() {
  analogWrite(5, 25);
  delay(1000);
  analogWrite(5, 0);
  delay(1000);
}

void turnRight() {
  analogWrite(6, 25);
  delay(1000);
  analogWrite(6, 0);
  delay(1000);
}

void fireThrusters() {
  for (int i = 4; i <= 8; ++i) digitalWrite(i, HIGH);
  delay(1000);
  for (int i = 4; i <= 8; ++i) digitalWrite(i, LOW);
  delay(1000);
}

void endTurn() {
  for (int i = 0; i < 10; ++i) {
    digitalWrite(4, HIGH);
    delay(10);
    digitalWrite(4, LOW);
    delay(10);
    digitalWrite(5, HIGH);
    delay(10);
     digitalWrite(5, LOW);
    delay(10);
    digitalWrite(6, HIGH);
    delay(10);
    digitalWrite(6, LOW);
    delay(10);
    digitalWrite(7, HIGH);
    delay(10);
    digitalWrite(7, LOW);
    delay(10);
    digitalWrite(8, HIGH);
    delay(10);
    digitalWrite(8, LOW);
    delay(10);
  }
  delay(1000);
}

