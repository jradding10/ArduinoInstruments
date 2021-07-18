// Star wars intro
//by Jacqueline Radding
//plays the first few notes of star wars intro song
const int Beeper = 9 ; // Digital Pin 9
const int quarterNote = 500 ; // msec for quarter note
const int C4freq = 262 ; // Hz for c4 note
const int G4freq = 392 ; // Hz for d4 note
const int F4freq = 349 ; // Hz for c4 note
const int E4freq = 330 ; // Hz for d4 note
const int D4freq = 294 ; // Hz for c4 note
const int C5freq = 523 ; // Hz for c5 note
void setup() {
 // put your setup code here, to run once:
 //plays all of the notes
tone(Beeper, C4freq, 2*quarterNote); // Output C4 for a half note
delay(2*quarterNote); // Wait for a half note to finish
tone(Beeper, G4freq, 4*quarterNote); // Output G4 for a half no
delay(4*quarterNote); // Wait for a note to finish
tone(Beeper, F4freq, quarterNote); // Output F4 for a half note
delay(quarterNote); // Wait for a .25 note to finish
tone(Beeper, E4freq, .5*quarterNote); // Output E4 for a half note
delay(0.5*quarterNote); // Wait for a 1/8 note to finish
tone(Beeper, D4freq, .5*quarterNote); // Output D4 for a half note
delay(0.5*quarterNote); // Wait for a 1/8 note to finish
tone(Beeper, C5freq, 2*quarterNote); // Output C5 for a half note
delay(2*quarterNote); // Wait for a half note to finish
tone(Beeper, G4freq, 4*quarterNote); // Output G4 for a half note
delay(4*quarterNote); // Wait for a note to finish
}
void loop() {
 // put your main code here, to run repeatedly:
}
