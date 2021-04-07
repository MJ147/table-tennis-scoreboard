#define ileScalakow 1
#define ilePinow ileScalakow * 10
int SER=5; 
int RCLK=6;
int SRCLK=7; 
int rejestr[ilePinow];

void setup(){
  pinMode(SER, OUTPUT);
  pinMode(RCLK, OUTPUT);
  pinMode(SRCLK, OUTPUT);
  czyscRejestr();
  zapiszRejestr();
}
void czyscRejestr(){
  for(int i=0; i<ilePinow; i++)
    rejestr[i]=LOW;
}
void zapiszRejestr(){
  digitalWrite(RCLK, LOW); 
  for(int i=ilePinow-1; i>=0; i--){
    digitalWrite(SRCLK, LOW);
    digitalWrite(SER, rejestr[i]);
    digitalWrite(SRCLK, HIGH); 
  }
  digitalWrite(RCLK, HIGH); 
}
void ustawPin(int ktory, int wartosc){
  rejestr[ktory]=wartosc;
}

void loop(){
  int i;

   for(i=0;i<ilePinow;i++){
    wyswietlacz(i);
    zapiszRejestr();
    delay(1000);
	}
}

void wyswietlacz(int cyfra) {
  //Instrukcja switch ustawia odpowiednie stany na wyjsciach
  //w zaleznosci od podanej cyfry
  switch (cyfra) {
    case 0:
        ustawPin(0, HIGH);
        ustawPin(1, HIGH);
        ustawPin(2, HIGH);
        ustawPin(3, HIGH);
        ustawPin(4, HIGH);
        ustawPin(5, HIGH);
        ustawPin(6, LOW);
    break; 
    
    case 1:
        ustawPin(0, LOW);
        ustawPin(1, HIGH);
        ustawPin(2, HIGH);
        ustawPin(3, LOW);
        ustawPin(4, LOW);
        ustawPin(5, LOW);
        ustawPin(6, LOW);
    break; 
    
    case 2:
        ustawPin(0, HIGH);
        ustawPin(1, HIGH);
        ustawPin(2, LOW);
        ustawPin(3, HIGH);
        ustawPin(4, HIGH);
        ustawPin(5, LOW);
        ustawPin(6, HIGH);
    break; 
    
    case 3:
        ustawPin(0, HIGH);
        ustawPin(1, HIGH);
        ustawPin(2, HIGH);
        ustawPin(3, HIGH);
        ustawPin(4, LOW);
        ustawPin(5, LOW);
        ustawPin(6, HIGH);
    break; 
    
    case 4:
        ustawPin(0, LOW);
        ustawPin(1, HIGH);
        ustawPin(2, HIGH);
        ustawPin(3, LOW);
        ustawPin(4, LOW);
        ustawPin(5, HIGH);
        ustawPin(6, HIGH);
    break; 
    
    case 5:
        ustawPin(0, HIGH);
        ustawPin(1, LOW);
        ustawPin(2, HIGH);
        ustawPin(3, HIGH);
        ustawPin(4, LOW);
        ustawPin(5, HIGH);
        ustawPin(6, HIGH);
    break; 
    
    case 6:
        ustawPin(0, HIGH);
        ustawPin(1, LOW);
        ustawPin(2, HIGH);
        ustawPin(3, HIGH);
        ustawPin(4, HIGH);
        ustawPin(5, HIGH);
        ustawPin(6, HIGH);
    break;
   
    case 7:
        ustawPin(0, HIGH);
        ustawPin(1, HIGH);
        ustawPin(2, HIGH);
        ustawPin(3, LOW);
        ustawPin(4, LOW);
        ustawPin(5, LOW);
        ustawPin(6, LOW);
    break;
    
    case 8:
        ustawPin(0, HIGH);
        ustawPin(1, HIGH);
        ustawPin(2, HIGH);
        ustawPin(3, HIGH);
        ustawPin(4, HIGH);
        ustawPin(5, HIGH);
        ustawPin(6, HIGH);
    break;
    
    case 9:
        ustawPin(0, HIGH);
        ustawPin(1, HIGH);
        ustawPin(2, HIGH);
        ustawPin(3, HIGH);
        ustawPin(4, LOW);
        ustawPin(5, HIGH);
        ustawPin(6, HIGH);
    break;
    
    default:
        ustawPin(0, LOW);
        ustawPin(1, LOW);
        ustawPin(2, LOW);
        ustawPin(3, LOW);
        ustawPin(4, LOW);
        ustawPin(5, LOW);
        ustawPin(6, LOW);
    break;
  }
}