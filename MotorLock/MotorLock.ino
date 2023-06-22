#include <Keypad.h>
#include <Wire.h>
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27, 20, 4);

const byte ROWS = 4;
const byte COLS = 4;
char keys[ROWS][COLS] = {
  { '1', '2', '3', 'A' },
  { '4', '5', '6', 'B' },
  { '7', '8', '9', 'C' },
  { '*', '0', '#', 'D' }
};
byte rowPins[ROWS] = { 9, 8, 7, 6 };  
byte colPins[COLS] = { 5, 4, 3, 2 };  
Keypad keypad = Keypad(makeKeymap(keys), rowPins, colPins, ROWS, COLS);

#define lock 10
#define enter 11
#define open_relayModule 12
bool isEnter = false;
bool lockIt = false;
bool isOpen = false;
int i = 0;
char pass[16];
const char correct_pass[] = "1234";  // you can change it but don't forget to change what i equals in 

void locked();
void pressedKey();
void check();

void setup() {
  Serial.begin(9600);


  pinMode(lock, INPUT);
  pinMode(enter, INPUT);
  pinMode(open_relayModule, OUTPUT);
  digitalWrite(open_relayModule, LOW);// in the beginning motor is OFF

  lcd.begin(16, 2);
  lcd.backlight();
  lcd.setCursor(0, 0);
  lcd.print("Enter password:");
  lcd.setCursor(0, 1);
}

void loop() {

  lockIt = digitalRead(lock);
  isEnter = digitalRead(enter);
  if (lockIt) locked();

  char key = keypad.getKey();
  if (key && !isOpen) pressedKey(key);
  if (isEnter) check();
}
 
void pressedKey(char key)
{
  lcd.print(key);
  delay(300);
  lcd.setCursor(i, 1);
  lcd.print('*');
  pass[i] = key;
  i++;
}

void locked()
{
  lcd.clear();
  i = 0;
  strcpy(pass, "");
  lcd.setCursor(0, 0);
  lcd.print("Enter password:");
  lcd.setCursor(0, 1);
  digitalWrite(open_relayModule, LOW); // motor is OFF
  isOpen = false;
  delay(500);
}

void check()
{
  if(i==4 && (!strcmp(correct_pass, pass)))
  {
    lcd.clear();
    lcd.setCursor(1,0);
    lcd.print("Access granted");
    digitalWrite(open_relayModule, HIGH); // motor is ON
    delay(1000);
    lcd.setCursor(1,1);
    lcd.print("Motor is ON");
    isOpen = true;
  }
  else
  {
    lcd.clear();
    lcd.setCursor(1,0);
    lcd.print("Access denied");
    delay(1500);
    locked();
  }
}
