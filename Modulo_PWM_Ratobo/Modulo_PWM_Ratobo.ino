//Desenvolvido por Paulo Maia e Marcelo Kito

#include<stdlib.h>
#include <SoftwareSerial.h>
SoftwareSerial Bluetooth(6,7);

//Montagem:

#define IN1 2
#define IN2 4
#define PWME 3

#define IN3 8
#define IN4 12
#define PWMD 9

/*
int RED = 6;
int GREEN = 10
int BLUE = 11;
*/

//===============================SETUP==============
void setup() {

  //Configurando serial para testes
  Serial.begin(115200);
  Serial.write("TESTE: ");
  Bluetooth.begin(9600);

  //Setando pinos como output
  pinMode(PWMD, OUTPUT);
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(PWME, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);
}
//=============================FUNÇÕES=============


//******************************************************* RECEBE COMANDO ***************************************************
void recebeMensagem(){
  int comando;
  char* msg = "";//String que recebe as informações enviadas pelo app pelo bluetooth
  int j =0; 
  if (Bluetooth.available()>0){
    j=0;
    Serial.write("Bluetooth falou algo: ");
    while(Bluetooth.available()){
      delay(10);
      //Serial.write(Bluetooth.read());
      msg[j] = (char)Bluetooth.read();
      j++;
    }
    Serial.write(msg);
    comando = atoi(msg);
    Serial.write(comando);
    //trataMensagem(comando); // comando está formado e será tratado
  }
}

//**********************************************************TRATA COMANDO ***************************************************

void trataMensagem(int comando){
  Serial.write("Comando recebido:");
  Serial.write(comando);

  //traduzir numero para byte
  char* comandoByte;
  itoa(comando,comandoByte, 2); // converte numero em cadeia de caracteres binária 

  //verificando que tipo de comando será pelos dois primeiros bits

  //Caso 10: Movimentação Básica
  if(comandoByte[0]=='1' && comandoByte[1]=='0'){
    //Lendo 3 bits para motor esquerda e 3 bits para motor direito
    int ME, MD;
    ME=4*(int)comandoByte[2] + 2*(int)comandoByte[3] + 1*(int)comandoByte[4];
    MD=4*(int)comandoByte[5] + 2*(int)comandoByte[6] + 1*(int)comandoByte[7];

    //Tratando motor direito

    switch (MD) {
      
      case 0:
        //Reverse fraco
        digitalWrite(IN3, LOW);
        digitalWrite(IN4, HIGH);
        analogWrite(PWMD, 40);
      break;
      
      case 1:
        //Reverse forte
        digitalWrite(IN3, LOW);
        digitalWrite(IN4, HIGH);
        analogWrite(PWMD, 255);
      break;
      
       case 2:
       //Parado
        digitalWrite(IN3, LOW);
        digitalWrite(IN4, LOW);
        analogWrite(PWMD, 0);
      break;
      
       case 3:
       //Forward fraco
        digitalWrite(IN3, HIGH);
        digitalWrite(IN4, LOW);
        analogWrite(PWMD, 20);
      break;
      
       case 4:
        //Forward Moderado Fraco
        digitalWrite(IN3, HIGH);
        digitalWrite(IN4, LOW);
        analogWrite(PWMD, 70);
      break;
      
       case 5:
        //Forward Moderado Forte
        digitalWrite(IN3, HIGH);
        digitalWrite(IN4, LOW);
        analogWrite(PWMD, 150);
      break;
      
       case 6:
        //Forward Forte
        digitalWrite(IN3, HIGH);
        digitalWrite(IN4, LOW);
        analogWrite(PWMD, 255);
      break;
      
       case 7:
       //Nada
      break; 
    }


    //Tratando Motor Esquerdo
    switch (ME) {
      
      case 0:
        //Reverse fraco
        digitalWrite(IN1, LOW);
        digitalWrite(IN2, HIGH);
        analogWrite(PWME, 40);
      break;
      
      case 1:
        //Reverse forte
        digitalWrite(IN1, LOW);
        digitalWrite(IN2, HIGH);
        analogWrite(PWME, 255);
      break;
      
       case 2:
       //Parado
        digitalWrite(IN1, LOW);
        digitalWrite(IN2, LOW);
        analogWrite(PWME, 0);
      break;
      
       case 3:
       //Forward fraco
        digitalWrite(IN1, HIGH);
        digitalWrite(IN2, LOW);
        analogWrite(PWME, 20);
      break;
      
       case 4:
        //Forward Moderado Fraco
        digitalWrite(IN1, HIGH);
        digitalWrite(IN2, LOW);
        analogWrite(PWMD, 70);
      break;
      
       case 5:
        //Forward Moderado Forte
        digitalWrite(IN1, HIGH);
        digitalWrite(IN2, LOW);
        analogWrite(PWME, 150);
      break;
      
       case 6:
        //Forward Forte
        digitalWrite(IN1, HIGH);
        digitalWrite(IN2, LOW);
        analogWrite(PWME, 255);
      break;
      
       case 7:
       //Nada
      break;
      
    }
   
  }

  //&&&&&&&&&&&&&&&& Fim Tratamento de movimento básico &&&&&&&&&&&&&&&&&&&&& 
}


//===============================LOOP==============
void loop() {
  recebeMensagem();
  
}






//==========================================================================================================================================
/*                        EQUIPE DE PESQUISA CARROSSEL CAIPIRA        2018
 *                        


*/
//==========================================================================================================================================


