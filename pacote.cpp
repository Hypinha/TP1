#include <iostream>
#include "pacote.h"
using namespace std;

//corpo das funções
unsigned int empacotar(unsigned int infoA, unsigned int infoB, unsigned int infoC, unsigned int infoD, unsigned int infoE)  //empacota os 5 dados em um número de 32 bits
{
	unsigned int resultado = 0;										//Inicializa a variavel
		resultado = infoA;											//coloca o valor do primeiro dado em resultado
		resultado = (resultado << 8);								//move o valor 8 bits para o lado
		resultado = (resultado | infoB);							//coloca o valor do segundo dado em resultado
		resultado = (resultado << 7);								//move o valor 7 bits para o lado
		resultado = (resultado | infoC);							//coloca o valor do terceiro dado em resultado
		resultado = (resultado << 4);								//move o valor 4 bits para o lado
		resultado = (resultado | infoD);							//coloca o valor do quarto dado em resultado
		resultado = (resultado << 1);								//move o valor 1 bit para o lado
		resultado = (resultado | infoE);							//coloca o valor do quinto dado em resultado
		resultado = (resultado << 4);								//move o valor 4 bits para o lado
		return resultado;
}
unsigned int funcpasso(unsigned int resultado)					//desempacota o passo
{
	unsigned int resul = 0;
		resul = resultado >> 24;			
		return resul;
}
unsigned int funccor(unsigned int resultado)					//desempacota a cor
{
	unsigned int resul = 0;
	resultado = (resultado << 8);
	resultado = (resultado >> 24);
	resul = resultado;
	return resul;
}
unsigned int funcpos(unsigned int resultado)					//desempacota a posição
{
	unsigned int resul;
	resultado = (resultado << 16);
	resultado = (resultado >> 25);
	resul = resultado;
	return resul;
}
unsigned int funcvel(unsigned int resultado)					//desempacota a velocidade
{
	unsigned int resul = 0;
	resultado = (resultado << 23);
	resultado = (resultado >> 28);
	resul = resultado;
	return resul;
}
unsigned int funcpista(unsigned int resultado)					//desempacota o estado da pista
{
	unsigned int resul;
	resultado = (resultado << 27);
	resultado = (resultado >> 31);
	resul = resultado;
	return resul;
}