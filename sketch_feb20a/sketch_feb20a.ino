// Pin assignments
const int redPin = 4;
const int greenPin = 3;
const int bluePin = 2;
const int buttonRed = 5;
const int buttonGreen = 6;
const int buttonBlue = 7;

// Function to set LED color
void setColor(int red, int green, int blue) {
    analogWrite(redPin, red);
    analogWrite(greenPin, green);
    analogWrite(bluePin, blue);
}

void setup() {
    pinMode(redPin, OUTPUT);
    pinMode(greenPin, OUTPUT);
    pinMode(bluePin, OUTPUT);
    pinMode(buttonRed, INPUT);
    pinMode(buttonGreen, INPUT);
    pinMode(buttonBlue, INPUT);
}

void loop() {
    int redPressed = digitalRead(buttonRed) == HIGH;
    int greenPressed = digitalRead(buttonGreen) == HIGH;
    int bluePressed = digitalRead(buttonBlue) == HIGH;

    if (redPressed && !greenPressed && !bluePressed) {
        setColor(255, 0, 0); // Red
    } else if (!redPressed && greenPressed && !bluePressed) {
        setColor(0, 255, 0); // Green
    } else if (!redPressed && !greenPressed && bluePressed) {
        setColor(0, 0, 255); // Blue
        setColor(0, 0, 0); // Off
    }
}
