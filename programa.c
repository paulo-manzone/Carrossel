#include <stdio.h>


//=========================================
//				INSTRUÇÕES
//=========================================

//-digitalWrite() coloca tensão baixa ou alta em algum pino
//ex:  digitalWrite(PINO1,HIGH) coloca tensão alta no pino1
//-setup() é chamado na inicilização do programa
//-loop() é chamado sem parar pelo durante a execução, após a execução
//de setup()
//

void setup(){
	//Declarando variavel
    int PINO1=1;
    
    //Declarando Pinos

	  pinMode (PINO1, OUTPUT);
	    
	//Mensagem de inicialização
	
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
