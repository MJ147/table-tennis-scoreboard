#define shiftRegister 2
#define numbers shiftRegister * 14
int SER=5; 
int RCLK=6;
int SRCLK=7; 
int registerPin[numbers];

void setup(){
	pinMode(SER, OUTPUT);
	pinMode(RCLK, OUTPUT);
	pinMode(SRCLK, OUTPUT);
	clearRegister();
	saveRegister();
}

void clearRegister(){
	for(int i=0; i<numbers; i++)
		registerPin[i]=LOW;
}
void saveRegister(){
	digitalWrite(RCLK, LOW); 
	for(int i=numbers-1; i>=0; i--){
    	digitalWrite(SRCLK, LOW);
    	digitalWrite(SER, registerPin[i]);
    	digitalWrite(SRCLK, HIGH); 
 	}
  	digitalWrite(RCLK, HIGH); 
}

void setPin(int pinIdx, int value){
	registerPin[pinIdx]=value;
}

void loop(){
	int i;

	for(i=0;i<numbers;i++){
    	displayDigit(0, i);
    	displayDigit(1, i);
    	saveRegister();
    	delay(1000);
	}
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