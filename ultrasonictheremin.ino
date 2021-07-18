/// Theremin
//by Jacqueline Radding
//plays notes based on how far your hand is from the sonar in the C major
const int C4freq = 262 ; // Hz for c4 note
const int G4freq = 392 ; // Hz for d4 note
const int F4freq = 349 ; // Hz for c4 note
const int E4freq = 330 ; // Hz for d4 note
const int D4freq = 294 ; // Hz for c4 note
const int A4freq = 523 ; // Hz for c5 note
const int B4freq = 523 ; // Hz for c5 note
const int C7freq = 2093 ; // Hz for c7 note
// Initialize needed local variables.
int Frequency = 0;
int FreqMultiplier = 1;
int newNoteFrequency;
int beeper = 9; // pin buzzer is on
int distance; // distance from sonar
int echoTime; // times it takes to reach sonar
int ToneNum; // this will be the distance to tone hz variable
void setup() {
 // put your setup code here, to run once:
pinMode(beeper, OUTPUT); // connected to buzzer +
//digitalWrite(Beeper, HIGH);
Serial.begin(9600);
}
void loop() {
digitalWrite(A5, LOW); // pulses the trigPin
delayMicroseconds(2); // delay
digitalWrite(A5, HIGH);//pulses trigPin
delayMicroseconds(10); //delay
digitalWrite(A5, LOW);//Pulses trigPin
MeasureDistance(); // calculates the distance
Serial.println(distance);
float handDistance = MeasureDistance( ); // creates a new variable for distance
int NoteFrequency = ConvertDistanceToFrequency(handDistance); // creates frequency
if (distance > 2 && distance < 22){ // this makes sure there is an accurate reading because arduino is not accurate
below 300 miliseconds and above 4 seconds
 tone(beeper, NoteFrequency);
 newNoteFrequency = NoteFrequency;
 if (NoteFrequency == newNoteFrequency){ // if origional sound is same as new sound
 tone(beeper,NoteFrequency); // play origional sound

 }
 else{
 tone(beeper,newNoteFrequency);// if there is a new distance, play new sound
 
 }
 }
else{
 noTone(beeper); // turns off beeper when there is no hand infront of sonar
 }

 delay(50); // small delay
}
float MeasureDistance(){ // measures distance from sonar and echotime
 echoTime = pulseIn(A4, HIGH);//recieves sound and its time
 distance = (echoTime / 74.0) / 2.0; // Convert time to inches one-way// Speed of sound is 0.0135 inches/
microsecond// or 74 microseconds per inch.
 }
int ConvertDistanceToFrequency(float Distance_inches) {
/* This function converts a distance value between 2.0 – 22.0 to the frequency
of a note between C4 (at 22.0 inches) and C7 (at 2.0 inches), with the note chosen
proportional to the distance. Only notes in the C major scale are provided. It
assumes global constants are available for the note frequencies for C4 through C5.
*/
// Initialize needed local variables.
int Frequency = 0;
int FreqMultiplier = 1;
// Map the distance value to a Tone number.
// Spanning 3 octaves (7 notes per octave) gives Tone numbers 1 - 22
int ToneNum = map(100 * distance, 200, 2200, 22, 1);
/*This algorithm works by using only the frequencies from the C4-B4 range.
These would be ToneNum 1-7. The frequencies for C5-B5 (ToneNum 8-14) are 2 X the
C4-B4 frequencies for the same musical notes (E5freq = 2 x E4freq). If you
subtract 7 from ToneNum 10 (E5), you get ToneNum 3 (E4). So ToneNum is reduced to
always be within 1-7, and a frequency multiplier scales up the note’s frequency to
the correct octave for the desired note (what it was before reducing ToneNum)*/
if (ToneNum > 21) { // If note is in the 4th octave
ToneNum = ToneNum - 21; // Drop three octaves
FreqMultiplier = 8; // Double-Double-Double the frequency
}
if (ToneNum > 14) { // If note is in the 3rd octave
ToneNum = ToneNum - 14; // Drop two octaves
FreqMultiplier = 4; // Double-Double the frequency
}
if (ToneNum > 7) { // If note is in the 2nd octave
ToneNum = ToneNum - 7; // Drop 1 octave
FreqMultiplier = 2; // Double-Double the frequency
}
// Map the ToneNum to the correct 1st octave base frequency
if (ToneNum == 1) Frequency = C4freq; // Need constants for frequencies
if (ToneNum == 2) Frequency = D4freq;
if (ToneNum == 3) Frequency = E4freq;
if (ToneNum == 4) Frequency = F4freq;
if (ToneNum == 5) Frequency = G4freq;
if (ToneNum == 6) Frequency = A4freq;
if (ToneNum == 7) Frequency = B4freq;
// Scale up the note frequency to the correct octave
Frequency = Frequency * FreqMultiplier;
return Frequency;
} 
