#include <stdio.h>






//===============================================================================================
//						SETUP
//===============================================================================================





void setup(){
	//Declarando variaveis e associando-as a um pino
	
	int ENTRADA=1,MOTORE=5, MOTORD=6;
	int RED = 9;
	int BLUE = 10;
	int GREEN = 11;
	int TENSAO25 = 3;
	
	//Definindo pinos como entrada ou saída
	pinMode(ENTRADA, INPUT);  //Entrada serial através 
	pinMode(MOTORE, OUTPUT); //Controle do motor Esquerdo
	pinMode(MOTORD, OUTPUT); //Controle do motor Direito
	pinMode(TENSAO25, OUTPUT); // Tensão 2.5V para uso no motor (como auxiliar, podendo assim rotacionar para ambos os lados com 0~5V do MOTORE E MOTORD)
	pinMode(RED, OUTPUT); //Led Vermelho
	pinMode(GREEN, OUTPUT); //Led Verde
	pinMode(BLUE, OUTPUT); //Led Azul
	
	analogwrite(TENSAO25, 127); // Colocando 2.5V no pino 3;
	
	system("cls");
	printf("\nSistema Ratobô Carrossel v1.0 inicializado!\n");
	
}



//================================================================================================
//						LOOP
//================================================================================================

void loop{
	

}



//=================================================================================================
//						FUNÇÕES
//=================================================================================================

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
		f00(comando);
	}else
		if(comando[0] == 0 && comando[1] == 1){
		f01(comando);
	}else
		if(comando[0] == 1 && comando[1] == 0){
		f10(comando);
	}else
		if(comando[0] == 1 && comando[1] == 1){
		f11(comando);
	}
	
		
}



//função 00: Movimentação e Cor de Led automático (Conforme velocidade)
void f00(char comando[8]){
	//Movimentação
	char esq[3], dir[3];
	
	esq[0] = comando[2];
	esq[1] = comando[3];
	esq[2] = comando[4];
	dir[0] = comando[5];
	dir[1] = comando[6];
	dir[2] = comando[7];
	
	int velE = (1*(esq[0]-'0')) + 2*(esq[1]-'0') + 4*(esq[2]-'0'))*17; // convertendo binario de tres bits para decimal 0 a 15 e fazendo correspondência a decimal de 0 a 255
	int velD = (1*(dir[0]-'0')) + 2*(dir[1]-'0') + 4*(dir[2]-'0'))*17;

	//Valores menores que 127 rodam num sentido, enquanto maiores rodam em outro sentido
	analogWrite(MOTORE, velE);
	analogWrite(MOTORD, velD);
	
	//Controle do LED								Variando com a velocidade de Azul até Vermelhor
	analogWrite(GREEN, 0);									//Verde sempre 0
	analogWrite(RED, abs((velE+velD)/2-127)*2);				//Vermelho sobe com a velocidade média dos motores
	analogWrite(BLUE, abs(127-(velE+velD)/2)*2);			//Azul diminui com a velocidade média dos motores
}

//função 01: Determina cor do LED
void f01(char comando[8]){
	int r, g, b;
	char vermelho[2], verde[2], azul[2];
	
	vermelho[0] = comando[2]; 
	vermelho[1] = comando[3];
	verde[0] = comando[4];
	verde[1] = comando[5];
	azul[0] = comando[6];
	azul[1] = comando[7];
	
	r = atoi(vermelho)*85;
	g = atoi(verde)*85;
	b = atoi(blue)*85;
	
	analogWrite(RED, r);
	analogWrite(GREEN, g);
	analogWrite(BLUE, b);
	
	
}

//função 10: Movimentaçao sem mudar cor do Led
void f10(char comando[8]){
	printf("Implementar");
}

//função 11: Modo de exibição (Roda loucamente e pisca)
void f11(char comando[8]){
	digitalWrite(MOTORD, HIGH);
	digitalWrite(MOTORE,LOW);
}





//=========================================================
//						HELP
//=========================================================

/*
Conexões:

BLUETOOTH : PINO 1
MOTOR DIREITO: PINO 6
MOTOR ESQUERDO: PINO 5
LED VERMELHO: PINO 9
LED AZUL: PINO 10
LED VERDE: PINO 11
POLO AUXILIAR DO MOTOR: PINO 3







*/
