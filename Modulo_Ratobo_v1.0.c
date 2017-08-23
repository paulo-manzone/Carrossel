#include <stdio.h>






//=========================================================
//						SETUP
//=========================================================

void setup(){
	//Declarando variaveis e associando-as a um pino
	
	int PINO1=1,PINO5=5, PINO6=6;
	
	//Definindo pinos como entrada ou sa�da
	pinMode (PINO1, INPUT);  //Entrada serial atrav�s 
	pinMode (PINO5, OUTPUT); //Controle do motor Esquerdo
	pinMode (PINO6, OUTPUT); //Controle do motor Direito
	
	system("cls");
	printf("\nSistema Ratob� Carrossel v1.0 inicializado!\n");
	
}



//=========================================================
//						LOOP
//=========================================================

void loop{
	

}



//=========================================================
//						FUN��ES
//=========================================================

//Chamado toda vez - determina qual fun��o deve ser chamada segundo o byte recebido via bluetooth
void receberComando(){
	int byte;
	
	//Receber aqui byte pelo bluetooth
	//--
	//--
	//--
	
	char comando[];
	itoa(byte, comando, 10);
	
	//Determinando fun��o recebida
	if(comando[0] == 0 && comando[1] == 0){
		modo0(comando);
	}
	
		
}



//fun��o 00: Movimenta��o e Cor de Led autom�tico (Conforme velocidade)
void f00(char comando[8]){
	//Movimenta��o
	char esq[3], dir[3];
	
	esq[0] = comando[2];
	esq[1] = comando[3];
	esq[2] = comando[4];
	dir[0] = comando[5];
	dir[1] = comando[6];
	dir[2] = comando[7];
		
	analogWrite(PINO5, atoi(esq));
	analogWrite(PINO6, atoi(dir));
	
	//Controle do LED
	
	
}

//fun��o 01: Determina cor do LED
void f01(char comando[8]){
	printf("Implementar");
}

//fun��o 10: Movimenta�ao sem mudar cor do Led
void f10(char comando[8]){
	printf("Implementar");
}

//fun��o 11: Modo de exibi��o (Roda loucamente e pisca)
void f11(char comando[8]){
	digitalWrite(PINO5, HIGH);
	digitalWrite(PINO6,LOW);
}





//=========================================================
//						HELP
//=========================================================

/*









*/
