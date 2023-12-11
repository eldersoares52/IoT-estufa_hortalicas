// C++ code
//

#define R 8
#define G 9
#define B 10
int tmp = A0; // Sensor de temperatura
int celsius = 0;

void setup(){
  	
  	pinMode(A0, INPUT);
  	Serial.begin(9600);	
  	
  	pinMode(7, OUTPUT); //Buzzer
 	pinMode(R, OUTPUT);	//Configuração dos pinos como saída
  	pinMode(G, OUTPUT); //Configuração dos pinos como saída
  	pinMode(B, OUTPUT); //Configuração dos pinos como saída
  	pinMode(4, OUTPUT); //Configuração dos pinos como saída (motor)
}

void loop(){
  
  	 
  	celsius = map(((analogRead(A0) - 20) * 3.04), 0, 1023, -40, 125);
  
  	Serial.print(celsius);
  	Serial.print(" C, ");	
  
  	if (celsius>=50) {
    	analogWrite(R, 255); //Ligando as portas PWM com valor aleatório de duty cicle
     	analogWrite(G, 0);
      	analogWrite(B, 0);
    	tone(7, 120, 1000);
      	delay(2000);	//Espera 200ms até atualizar o LED com novos valores aleatórios 	
  	
    }
  	else if (celsius>=30) {
      	digitalWrite(4, HIGH);
    }
  	else {
      noTone(7);
      digitalWrite(4, LOW); 		
    }
}


