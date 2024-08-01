#include <iostream>
#include "pacote.h"
#include "rede.h"
#include "cores.h"
using namespace std;

unsigned int net;

void transmitir(unsigned int passo, unsigned int cor, unsigned int pos, unsigned int vel, unsigned int oleo)  //chama a fun��o de empacotar e utiliza dela para enviar os dados para a rede
{
	unsigned int rede;
	net = empacotar(passo, cor, pos, vel, oleo);
	AjustaCor(preto, cor);
	cout << net << endl;
	rede = net;
}

unsigned int receber(void)																//chama as fun��es para o desempacotamento e apresenta os dados
{	
	unsigned int passo, cor, vel, pos;
	bool oleo;
	passo = funcpasso(net);
	cor = funccor(net);
	vel = funcvel(net);
	pos = funcpos(net);
	oleo = funcpista(net);

	AjustaCor(cor, preto);
	cout << left; cout.width(10); cout << "velocidade: " << vel;						//Mostra a velocidade na tela

	AjustaCor(cor, preto);
	cout << right; cout.width(15); cout << "pos: " << pos;								//Mostra a posi��o atual na tela

	AjustaCor(cor, preto);
	cout.width(14); cout << "oleo: " << oleo << endl;									//Mostra o estado da pista na tela

	
	return 0;
}

unsigned int processar(unsigned int)							//chama as fun��es de desempacotamento e processa a pr�xima posi��o
{
	unsigned int cor, vel, pos;
	bool oleo;
	cor = funccor(net);
	vel = funcvel(net);
	pos = funcpos(net);
	oleo = funcpista(net);

	pos = pos + vel - oleo;												//Calcula Pr�xima posi��o
	AjustaCor(cor, preto);
	cout << "prox pos: " << pos << endl;							//Mostra a pr�xima posi��o na tela

	return pos;
}