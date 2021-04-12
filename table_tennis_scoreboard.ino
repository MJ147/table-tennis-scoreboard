#define numberOfDisplays 2
#define digitsInDisplay 2
#define registerOutputs digitsInDisplay * 9

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
Display display2;

Display displays[numberOfDisplays] = {display1, display2};

void setup(){
  	setupDisplay(0, 5, 6, 7, 2);
  	setupDisplay(1, 8, 9, 10, 3);
  
  showNumber(0, 0);
  showNumber(1, 0);
}

void setupDisplay(int displayNumber, int SER, int RCLK, int SRCLK, int buttonPin) {
	displays[displayNumber].SER = SER;
    displays[displayNumber].RCLK = RCLK;
    displays[displayNumber].SRCLK = SRCLK;
    displays[displayNumber].button.pin = buttonPin;
     
	pinMode(displays[displayNumber].button.pin, INPUT_PULLUP); // Button
	pinMode(displays[displayNumber].SER, OUTPUT);
	pinMode(displays[displayNumber].RCLK, OUTPUT);
	pinMode(displays[displayNumber].SRCLK, OUTPUT);
	clearRegister(displayNumber);
	saveRegister(displayNumber);
}

void clearRegister(int displayNumber){
 	for(int i=0; i<registerOutputs; i++) {
		displays[displayNumber].registerPin[i]=LOW;
    }
}

void saveRegister(int displayNumber){
	digitalWrite(displays[displayNumber].RCLK, LOW); 
  
	for(int i=registerOutputs-1; i>=0; i--){
    	digitalWrite(displays[displayNumber].SRCLK, LOW);
    	digitalWrite(displays[displayNumber].SER, displays[displayNumber].registerPin[i]);
    	digitalWrite(displays[displayNumber].SRCLK, HIGH); 
 	}
  	digitalWrite(displays[displayNumber].RCLK, HIGH); 
}

void setPin(int displayNumber, int pinIdx, int value){
	displays[displayNumber].registerPin[pinIdx]=value;
}

void loop(){
	moveCounterOnButtonPress(0);  
 	moveCounterOnButtonPress(1);  
}

void moveCounterOnButtonPress(int displayNumber) {
	displays[displayNumber].button.buttonState = digitalRead(displays[displayNumber].button.pin);
  
    if (displays[displayNumber].button.buttonState != displays[displayNumber].button.lastButtonState) {
    	if (digitalRead(displays[displayNumber].button.pin) == HIGH) {
            int counter = ++displays[displayNumber].button.buttonPushCounter;
         	
        	showNumber(displayNumber, counter);
        }	
    }
  	  displays[displayNumber].button.lastButtonState = displays[displayNumber].button.buttonState;

  	
    if(isSetEnd()) {
      	displays[0].button.buttonPushCounter = 0;
      	displays[1].button.buttonPushCounter = 0;
      
    	showNumber(0, 0);  
  		showNumber(1, 0); 
    };
}

void showNumber(int displayNumber, int number) {
    if (number < 10) {
     	displayDigit(displayNumber, 0, -1);
      	displayDigit(displayNumber, 1, number);
    } else {
      	displayDigit(displayNumber, 0, firstDigit(number));
      	displayDigit(displayNumber, 1, lastDigit(number));
    }

    saveRegister(displayNumber);
  	delay(50);
}

boolean isSetEnd() {
	int counter1 = displays[0].button.buttonPushCounter;
	int counter2 = displays[1].button.buttonPushCounter;
      
  	if ((counter1 > 10 || counter2 > 10) && abs(counter1 - counter2) > 1) {
      delay(3000);
        return true;
    }
    
 	return false;
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

void displayDigit(int y, int x, int digit) {
 	switch (digit) {
    	case 0:
            setPin(y, 0 + 8*x, HIGH);
            setPin(y, 1 + 8*x, HIGH);
            setPin(y, 2 + 8*x, HIGH);
            setPin(y, 3 + 8*x, HIGH);
            setPin(y, 4 + 8*x, HIGH);
            setPin(y, 5 + 8*x, HIGH);
            setPin(y, 6 + 8*x, LOW);
    	break; 
    
   		case 1:
            setPin(y, 0 + 8*x, LOW);
            setPin(y, 1 + 8*x, HIGH);
            setPin(y, 2 + 8*x, HIGH);
            setPin(y, 3 + 8*x, LOW);
            setPin(y, 4 + 8*x, LOW);
            setPin(y, 5 + 8*x, LOW);
            setPin(y, 6 + 8*x, LOW);
   		break; 
    
        case 2:
            setPin(y, 0 + 8*x, HIGH);
            setPin(y, 1 + 8*x, HIGH);
            setPin(y, 2 + 8*x, LOW);
            setPin(y, 3 + 8*x, HIGH);
            setPin(y, 4 + 8*x, HIGH);
            setPin(y, 5 + 8*x, LOW);
            setPin(y, 6 + 8*x, HIGH);
        break; 

        case 3:
            setPin(y, 0 + 8*x, HIGH);
            setPin(y, 1 + 8*x, HIGH);
            setPin(y, 2 + 8*x, HIGH);
            setPin(y, 3 + 8*x, HIGH);
            setPin(y, 4 + 8*x, LOW);
            setPin(y, 5 + 8*x, LOW);
            setPin(y, 6 + 8*x, HIGH);
        break;

        case 4:
            setPin(y, 0 + 8*x, LOW);
            setPin(y, 1 + 8*x, HIGH);
            setPin(y, 2 + 8*x, HIGH);
            setPin(y, 3 + 8*x, LOW);
            setPin(y, 4 + 8*x, LOW);
            setPin(y, 5 + 8*x, HIGH);
            setPin(y, 6 + 8*x, HIGH);
        break; 

        case 5:
            setPin(y, 0 + 8*x, HIGH);
            setPin(y, 1 + 8*x, LOW);
            setPin(y, 2 + 8*x, HIGH);
            setPin(y, 3 + 8*x, HIGH);
            setPin(y, 4 + 8*x, LOW);
            setPin(y, 5 + 8*x, HIGH);
            setPin(y, 6 + 8*x, HIGH);
        break; 

        case 6:
            setPin(y, 0 + 8*x, HIGH);
            setPin(y, 1 + 8*x, LOW);
            setPin(y, 2 + 8*x, HIGH);
            setPin(y, 3 + 8*x, HIGH);
            setPin(y, 4 + 8*x, HIGH);
            setPin(y, 5 + 8*x, HIGH);
            setPin(y, 6 + 8*x, HIGH);
        break;

        case 7:
            setPin(y, 0 + 8*x, HIGH);
            setPin(y, 1 + 8*x, HIGH);
            setPin(y, 2 + 8*x, HIGH);
            setPin(y, 3 + 8*x, LOW);
            setPin(y, 4 + 8*x, LOW);
            setPin(y, 5 + 8*x, LOW);
            setPin(y, 6 + 8*x, LOW);
        break;

        case 8:
            setPin(y, 0 + 8*x, HIGH);
            setPin(y, 1 + 8*x, HIGH);
            setPin(y, 2 + 8*x, HIGH);
            setPin(y, 3 + 8*x, HIGH);
            setPin(y, 4 + 8*x, HIGH);
            setPin(y, 5 + 8*x, HIGH);
            setPin(y, 6 + 8*x, HIGH);
        break;

        case 9:
            setPin(y, 0 + 8*x, HIGH);
            setPin(y, 1 + 8*x, HIGH);
            setPin(y, 2 + 8*x, HIGH);
            setPin(y, 3 + 8*x, HIGH);
            setPin(y, 4 + 8*x, LOW);
            setPin(y, 5 + 8*x, HIGH);
            setPin(y, 6 + 8*x, HIGH);
        break;

        default:
            setPin(y, 0 + 8*x, LOW);
            setPin(y, 1 + 8*x, LOW);
            setPin(y, 2 + 8*x, LOW);
            setPin(y, 3 + 8*x, LOW);
            setPin(y, 4 + 8*x, LOW);
            setPin(y, 5 + 8*x, LOW);
            setPin(y, 6 + 8*x, LOW);
        break;
  }
}