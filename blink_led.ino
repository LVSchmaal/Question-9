// set the blink and sample frequency
#define BLINK_FREQ 10     // led blink frequency [Hz]
#define SAMPLE_FREQ 100   // sample frequency [Hz]

const float half_blink_period = (1000/(BLINK_FREQ))/2;    // sample period [millis seconds]
const float sample_period = (1000/(SAMPLE_FREQ));  // sample period [millis seconds]

unsigned long last_us_blink = 0L;
unsigned long last_us_sampling = last_us_blink;
bool led_on = false;

// the setup function runs once when you press reset or power the board
void setup() {
  Serial.begin(9600); 
  // initialize digital pin LED_BUILTIN as an output.
  pinMode(LED_BUILTIN, OUTPUT);
}

// the loop function runs over and over again forever
void loop() {
  blinking();
  sampling();
}

void blinking() {
  if ( millis () - last_us_blink > half_blink_period && led_on == false){
    digitalWrite(LED_BUILTIN, HIGH);    // turn the LED off by making the voltage LOW
    led_on = true;
    last_us_blink += half_blink_period;
  }
  
  if ( millis () - last_us_blink > half_blink_period && led_on == true){
    digitalWrite(LED_BUILTIN, LOW);    // turn the LED off by making the voltage LOW
    led_on = false;
    last_us_blink += half_blink_period;
  }
}

void sampling() {
  if ( millis () - last_us_sampling > sample_period )
  {
    //// used to copy paste serial data (time, led_state) form serial monitor ////
    // Serial.println(String(millis()) + "\t" + digitalRead(LED_BUILTIN));

    //// used for serial plotter ////
    Serial.println(digitalRead(LED_BUILTIN)); 
    last_us_sampling += sample_period;
  }
}