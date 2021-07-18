// Arduino Keyboard
//by Jacqueline Radding
//plays a note when a button is pressed
const int Ckey = 6 ; // Pin for S1 acting as C4 key
const int Dkey = 5 ; // Pin for S2 acting as C4 key
const int Ekey = 4 ; // Pin for S3 acting as C4 key
const int Fkey = 3 ; // Pin for S4 acting as C4 key
const int Gkey = 2 ; // Pin for S5 acting as C4 key
int reading;
//bool f; // this is the true or false value
const int Beeper = 9 ; // Digital Pin 9 for buzzer
const int quarterNote = 500 ; // msec for quarter note
const int C4freq = 262 ; // Hz for c4 note
const int G4freq = 392 ; // Hz for d4 note
const int F4freq = 349 ; // Hz for c4 note
const int E4freq = 330 ; // Hz for d4 note
const int D4freq = 294 ; // Hz for c4 note
const int A4freq = 523 ; // Hz for c5 note
const int B4freq = 523 ; // Hz for c5 note
void setup() {
 // put your setup code here, to run once:
pinMode(Beeper, OUTPUT); // connected to buzzer +
pinMode(Ckey, INPUT_PULLUP); // s1 button
pinMode(Dkey, INPUT_PULLUP); // s2 button
pinMode(Ekey, INPUT_PULLUP); // s3 button
pinMode(Fkey, INPUT_PULLUP); // s4 button
pinMode(Gkey, INPUT_PULLUP); // s5 button
}
void loop() {
reading = digitalRead(Ckey); // gets an accurate reading of the Ckey pin/ button status
 if (KeyPressed(Ckey)){
 tone(Beeper, C4freq);
 delay(quarterNote); // delay so can user play a quarter note at least

 }
 reading = digitalRead(Dkey); // reads pin too see if button pressed
 if (KeyPressed(Dkey)){ // sees if button pressed
 tone(Beeper, D4freq, quarterNote); // plays sound
 delay(quarterNote); // delay so can user play a quarter note at least
 }
 reading = digitalRead(Ekey); // reads pin
 if (KeyPressed(Ekey)){ // sees if button pressed
 tone(Beeper, E4freq);// plays sound
 delay(quarterNote); // delay so can user play a quarter note at least

 }
 reading = digitalRead(Fkey); // reads pin
 if (KeyPressed(Fkey)){ // is button pressed?
 tone(Beeper, F4freq);// note sound
 delay(quarterNote); // delay so can user play a quarter note at least

 }
 reading = digitalRead(Gkey); // read the button
 if (KeyPressed(Gkey)){ // if button pressed
 tone(Beeper, G4freq, quarterNote);
 delay(quarterNote); // so button can put a note in

 }
 else
 {
 noTone(Beeper); // turns off tone if button not pressed
 }

 }

bool KeyPressed(int key){ // this displays true if button pressed
 reading == digitalRead(key); // to double check digital reading
if (reading == 1){ // if not pressed
 return false;
 }
else { // if pressed
 return true; // if button pressed
 }
}
