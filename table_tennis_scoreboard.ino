#define numberOfDisplays 2
#define digitsInDisplay 2
#define registerOutputs digitsInDisplay * 8

class Button {
    public:
  	int pin;
    int buttonPushCounter = 0;   // counter for the number of button presses
    int buttonState = 0;         // current state of the button
    int lastButtonState = 0;     // previous state of the button
};

class Display {
  	public: 
  	Button button;
	int SER;
  	int RCLK;
    int SRCLK;
 	int registerPin[registerOutputs];
};

Display display1;

void setup(){
    display1.SER = 5;
    display1.RCLK = 6;
    display1.SRCLK = 7;
    display1.button.pin = 2;
	  
  
	pinMode(display1.button.pin, INPUT_PULLUP); // Button
	pinMode(display1.SER, OUTPUT);
	pinMode(display1.RCLK, OUTPUT);
	pinMode(display1.SRCLK, OUTPUT);
	clearRegister();
	saveRegister();
}

void clearRegister(){
	for(int i=0; i<registerOutputs; i++)
		display1.registerPin[i]=LOW;
}
void saveRegister(){
	digitalWrite(display1.RCLK, LOW); 
  
	for(int i=registerOutputs-1; i>=0; i--){
    	digitalWrite(display1.SRCLK, LOW);
    	digitalWrite(display1.SER, display1.registerPin[i]);
    	digitalWrite(display1.SRCLK, HIGH); 
 	}
  	digitalWrite(display1.RCLK, HIGH); 
}

void setPin(int pinIdx, int value){
	display1.registerPin[pinIdx]=value;
}

void loop(){
    display1.button.buttonState = digitalRead(display1.button.pin);
  
    if (display1.button.buttonState != display1.button.lastButtonState) {
        if (digitalRead(2) == HIGH) {
            display1.button.buttonPushCounter++;
            if (display1.button.buttonPushCounter > 11) {
                display1.button.buttonPushCounter = 0;
            }
            displayDigit(0, firstDigit(display1.button.buttonPushCounter));
            displayDigit(1, lastDigit(display1.button.buttonPushCounter));
            saveRegister();
        }	
      	delay(50);
    }
  	display1.button.lastButtonState = display1.button.buttonState;
}

int firstDigit(int n) {
  	while (n >= 10) {
        n /= 10;   
  	}
  
 	return n;
}
  

int lastDigit(int n) {
  	while (n <= 10) {
        return 0;   
  	}
  
    return (n % 10);
}

void displayDigit(int x, int digit) {
 	switch (digit) {
    	case 0:
            setPin(0 + 8*x, HIGH);
            setPin(1 + 8*x, HIGH);
            setPin(2 + 8*x, HIGH);
            setPin(3 + 8*x, HIGH);
            setPin(4 + 8*x, HIGH);
            setPin(5 + 8*x, HIGH);
            setPin(6 + 8*x, LOW);
    	break; 
    
   		case 1:
            setPin(0 + 8*x, LOW);
            setPin(1 + 8*x, HIGH);
            setPin(2 + 8*x, HIGH);
            setPin(3 + 8*x, LOW);
            setPin(4 + 8*x, LOW);
            setPin(5 + 8*x, LOW);
            setPin(6 + 8*x, LOW);
   		break; 
    
        case 2:
            setPin(0 + 8*x, HIGH);
            setPin(1 + 8*x, HIGH);
            setPin(2 + 8*x, LOW);
            setPin(3 + 8*x, HIGH);
            setPin(4 + 8*x, HIGH);
            setPin(5 + 8*x, LOW);
            setPin(6 + 8*x, HIGH);
        break; 

        case 3:
            setPin(0 + 8*x, HIGH);
            setPin(1 + 8*x, HIGH);
            setPin(2 + 8*x, HIGH);
            setPin(3 + 8*x, HIGH);
            setPin(4 + 8*x, LOW);
            setPin(5 + 8*x, LOW);
            setPin(6 + 8*x, HIGH);
        break; 

        case 4:
            setPin(0 + 8*x, LOW);
            setPin(1 + 8*x, HIGH);
            setPin(2 + 8*x, HIGH);
            setPin(3 + 8*x, LOW);
            setPin(4 + 8*x, LOW);
            setPin(5 + 8*x, HIGH);
            setPin(6 + 8*x, HIGH);
        break; 

        case 5:
            setPin(0 + 8*x, HIGH);
            setPin(1 + 8*x, LOW);
            setPin(2 + 8*x, HIGH);
            setPin(3 + 8*x, HIGH);
            setPin(4 + 8*x, LOW);
            setPin(5 + 8*x, HIGH);
            setPin(6 + 8*x, HIGH);
        break; 

        case 6:
            setPin(0 + 8*x, HIGH);
            setPin(1 + 8*x, LOW);
            setPin(2 + 8*x, HIGH);
            setPin(3 + 8*x, HIGH);
            setPin(4 + 8*x, HIGH);
            setPin(5 + 8*x, HIGH);
            setPin(6 + 8*x, HIGH);
        break;

        case 7:
            setPin(0 + 8*x, HIGH);
            setPin(1 + 8*x, HIGH);
            setPin(2 + 8*x, HIGH);
            setPin(3 + 8*x, LOW);
            setPin(4 + 8*x, LOW);
            setPin(5 + 8*x, LOW);
            setPin(6 + 8*x, LOW);
        break;

        case 8:
            setPin(0 + 8*x, HIGH);
            setPin(1 + 8*x, HIGH);
            setPin(2 + 8*x, HIGH);
            setPin(3 + 8*x, HIGH);
            setPin(4 + 8*x, HIGH);
            setPin(5 + 8*x, HIGH);
            setPin(6 + 8*x, HIGH);
        break;

        case 9:
            setPin(0 + 8*x, HIGH);
            setPin(1 + 8*x, HIGH);
            setPin(2 + 8*x, HIGH);
            setPin(3 + 8*x, HIGH);
            setPin(4 + 8*x, LOW);
            setPin(5 + 8*x, HIGH);
            setPin(6 + 8*x, HIGH);
        break;

        default:
            setPin(0 + 8*x, LOW);
            setPin(1 + 8*x, LOW);
            setPin(2 + 8*x, LOW);
            setPin(3 + 8*x, LOW);
            setPin(4 + 8*x, LOW);
            setPin(5 + 8*x, LOW);
            setPin(6 + 8*x, LOW);
        break;
  }
}