#include <SoftwareSerial.h> //INCLUSÃO DE BIBLIOTECA SERIAL
#include <AFMotor.h> //INCLUSÃO DE BIBLIOTECA MOTORES
 
const int pinoRX = 2; //PINO DIGITAL 2 (RX)
const int pinoTX = 3; //PINO DIGITAL 3 (TX)
int dadoBluetooth = 0; //VARIÁVEL QUE ARMAZENA O VALOR ENVIADO PELO BLUETOOTH   
 
SoftwareSerial bluetooth(pinoRX, pinoTX); //PINOS QUE EMULAM A SERIAL, ONDE
//O PINO 2 É O RX E O PINO 3 É O TX

AF_DCMotor motorBB(4); //DEFINE A SAIDA M4 PARA O MOTOR DE BB 
AF_DCMotor motorBE(3); // DEFINE A SAIDA M2 PARA O MOTOR DE BE 
 
void setup(){
  Serial.begin(19200); //INICIALIZA A SERIAL
  bluetooth.begin(9600); //INICIALIZA A SERIAL DO BLUETOOTH
  motorBB.run(RELEASE);
  motorBE.run(RELEASE); 
  //delay(100); //INTERVALO DE 100 MILISSEGUNDOS
  
}
 
void loop(){
  if(bluetooth.available()){ //SE O BLUETOOTH ESTIVER HABILITADO, FAZ
       dadoBluetooth = bluetooth.read(); //VARIÁVEL RECEBE O VALOR ENVIADO PELO BLUETOOTH
       if(dadoBluetooth != 83){
        Serial.println(dadoBluetooth);
       }
    if(dadoBluetooth == 'U'){ //SETA PARA CIMA
      motorBB.run(FORWARD);
      motorBE.run(FORWARD);
      motorBB.setSpeed(254);
      motorBE.setSpeed(254);
      Serial.println("FRENTE"); 
    }  

    else if(dadoBluetooth == 'R'){ //SETA PARA DIREITA
      motorBB.run(FORWARD);
      motorBE.run(RELEASE);
      motorBB.setSpeed(254);
      motorBE.setSpeed(0);
      Serial.println("DIREITA");
    }

    else if(dadoBluetooth == 'D'){ //SETA PARA BAIXO
      motorBB.run(BACKWARD);
      motorBE.run(BACKWARD);
      motorBB.setSpeed(180);
      motorBE.setSpeed(180);
      Serial.println("DANDO RÉ");
    }

    else if(dadoBluetooth == 'L'){ //SETA PARA ESQUERDA
      motorBB.run(RELEASE);
      motorBE.run(FORWARD);
      motorBB.setSpeed(0);
      motorBE.setSpeed(254);
      Serial.println("ESQUERDA");
    }
    
    else if(dadoBluetooth == ' '){
      motorBB.setSpeed(0);
      motorBE.setSpeed(0);
      Serial.println("PARADO");
    }
  }
  //delay(200);
}