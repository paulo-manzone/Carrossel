#include <stdio.h>






//=========================================================
//						SETUP
//=========================================================





void setup(){
	//Declarando variaveis e associando-as a um pino
	
	int ENTRADA=1,MOTORE=5, MOTORD=6;
	int RED = 9;
	int BLUE = 10;
	int GREEN = 11;
	
	//Definindo pinos como entrada ou sa�da
	pinMode(ENTRADA, INPUT);  //Entrada serial atrav�s 
	pinMode(MOTORE, OUTPUT); //Controle do motor Esquerdo
	pinMode(MOTORD, OUTPUT); //Controle do motor Direito
	pinMode(RED, OUTPUT); //Led Vermelho
	pinMode(GREEN, OUTPUT); //Led Verde
	pinMode(BLUE, OUTPUT); //Led Azul
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
		
	analogWrite(MOTORE, atoi(esq));
	analogWrite(MOTORD, atoi(dir));
	
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
	digitalWrite(MOTORD, HIGH);
	digitalWrite(MOTORE,LOW);
}





//=========================================================
//						HELP
//=========================================================

/*
Conex�es:

BLUETOOTH : PINO 1
MOTOR DIREITO: PINO 6
MOTOR ESQUERDO: PINO 5
LED VERMELHO: PINO 9
LED AZUL: PINO 10
LED VERDE: PINO 11







*/
