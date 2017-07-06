#include <stdio.h>


//=========================================
//				INSTRU��ES
//=========================================

//-digitalWrite() coloca tens�o baixa ou alta em algum pino
//ex:  digitalWrite(PINO1,HIGH) coloca tens�o alta no pino1
//-setup() � chamado na iniciliza��o do programa
//-loop() � chamado sem parar pelo durante a execu��o, ap�s a execu��o
//de setup()
//

void setup(){
	//Declarando variavel
    int PINO1=1;
    
    //Declarando Pinos

	  pinMode (PINO1, OUTPUT);
	    
	//Mensagem de inicializa��o
	
	system("cls");
	printf("\nSistema inicializado!\n");
}

void loop(){

}

void setVelocidade(int velocidade, int pino){
	if(velocidade>10){
		return;
	}
	int j;
	for(j=0; j<50; j++){
		digitalWrite(pino, HIGH);
		sleep(velocidade);
		digitalWrite(pino, LOW;);
	}
	
}
