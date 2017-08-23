#include <stdio.h>






//=========================================================
//						SETUP
//=========================================================

void setup(){
	//Declarando variaveis e associando-as a um pino
	
	int PINO1=1,PINO5=5, PINO6=6;
	
	//Definindo pinos como entrada ou saída
	pinMode (PIN1, INPUT);  //Entrada serial através 
	pinMode (PIN5, OUTPUT); //Controle do motor Esquerdo
	pinMode (PIN6, OUTPUT); //Controle do motor Direito
	
	system("cls");
	printf("\nSistema Ratobô Carrossel v1.0 inicializado!\n");
	
}



//=========================================================
//						LOOP
//=========================================================

void loop{
	

}



//=========================================================
//						FUNÇÕES
//=========================================================

//Chamado toda vez - determina qual função deve ser chamada segundo o byte recebido via bluetooth
void receberComando(){
	int byte;
	
	//Receber aqui byte pelo bluetooth
	//--
	//--
	//--
	
	char comando[];
	itoa(byte, comando, 10);
	
	//Determinando função recebida
	if(comando[0] == 0 && comando[1] == 0){
		modo0(comando);
	}
	
		
}



//função 00: Movimentação e Cor de Led automático (Conforme velocidade)
void f00(char comando[8]){
	printf("Implementar");
}

//função 01: Determina cor do LED
void f01(char comando[8]){
	printf("Implementar");
}

//função 10: Movimentaçao sem mudar cor do Led
void f10(char comando[8]){
	printf("Implementar");
}

//função 11: Modo de exibição (Roda loucamente e pisca)
void f11(char comando[8]){
	printf("Implementar");
}





//=========================================================
//						HELP
//=========================================================

/*









*/
