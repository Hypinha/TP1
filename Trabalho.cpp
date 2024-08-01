#include <iostream>
#include <ctime>
#include "cores.h"
#include "pacote.h"
#include "rede.h"
using namespace std;

//Prot�tipos
void Desenha(int, char);
void WhiteSpace(int);

unsigned int rede;

int main()
{
	
	int posA, posB, velA, velB;												//Declara��o de vari�veis
	char cor, corA, corB;													//Declara��o de vari�veis
	bool oleoA, oleoB;														//Declara��o de vari�veis
	double VelMedA, VelMedB, pos;											//Declara��o de vari�veis
	
	srand(unsigned(time(NULL)));											//Gerador de sementes para rand
	
// Inicializa dados:
	posA = 0;																// - Posi��o
	posB = 0;																// - Posi��o
	velA = 0;																// - Velocidade
	velB = 0;																// - Velocidade
	corA = azul;															// - Cores
	corB = vermelho;														// - Cores
	oleoA = 0;																// - Estado da pista
	oleoB = 0;																// - Estado da pista

// --------------------
	
	
	
	int passo = 0;
	do
	{
		system("cls");														// Limpa tela

		AjustaCor(preto, branco);											//Chamada da fun��o para alterar a cor do texto
		cout << "Passo:" << limpar << " " << passo << endl;					//Mostra o valor atual do passo na tela

		pos = posA;															//Inicializa��o da vari�vel com dados em rela��o ao caminh�o 1
		cor = corA;															//Inicializa��o da vari�vel com dados em rela��o ao caminh�o 1
		Desenha(pos, cor);													//Desenha caminh�o 1
		

		velA = rand() % 10 + 1;												//Atualiza velocidade
						
		oleoA = rand() % 2;													//Atualiza estado da pista
		
		// Transmite, recebe e processa dados

		int net = 0;
		ResetarCor();
		cout << "transmitindo dados..." << endl;
		transmitir(passo, cor, posA, velA, oleoA);							//Chama a fun��o transmitir, que acionar� o empacotamento de dados e enviar� para a rede
		ResetarCor();
		cout << "recebendo dados..." << endl;
		receber();															//Chama a fun��o receber, para ler os dados da rede
		ResetarCor();
		cout << "processando dados..." << endl;
		posA = processar(rede);												//Guarda a posi��o de do caminh�o 2 e chama a fun��o processar
		
		AjustaCor(preto, branco);											//Chamada da fun��o para alterar a cor do texto
		cout << "\n\nPasso:" << limpar << " " << passo << endl;				//Mostra o valor atual do passo na tela

		pos = posB;															//Atualiza��o do valor da vari�vel em rela��o ao caminh�o 2
		cor = corB;															//Atualiza��o do valor da vari�vel em rela��o ao caminh�o 2
		Desenha(pos, cor);													//Desenha caminh�o 2
		
		velB = rand() % 10 + 1;												//Atualiza velocidade
		
		oleoB = rand() % 2;													//Atualiza estado da pista


		// Transmite, recebe e processa dados
		ResetarCor();
		cout << "transmitindo dados..." << endl;
		transmitir(passo, cor, posB, velB, oleoB);							//Chama a fun��o transmitir, que acionar� o empacotamento de dados e enviar� para a rede
		ResetarCor();
		cout << "recebendo dados..." << endl;
		receber();															//Chama a fun��o receber, para ler os dados da rede
		ResetarCor();
		cout << "processando dados..." << endl;
		posB = processar(rede);												//Guarda a posi��o de do caminh�o 2 e chama a fun��o processar
				

		system("pause");													//Aguarda pressionamento de tecla
			

			passo = passo + 1;
	} while (posA <= 100 && posB <= 100);
	
	system("cls");															//Limpa tela

	pos = posA;																//Atualiza��o do valor da vari�vel em rela��o ao caminh�o 1
	cor = corA;																//Atualiza��o do valor da vari�vel em rela��o ao caminh�o 1
	Desenha(pos, cor);														//Desenha o caminh�o 1
	
	VelMedA = pos / passo;													//Atribui um valor para a vari�vel

	pos = posB;																//Atualiza��o do valor da vari�vel em rela��o ao caminh�o 2
	cor = corB;																//Atualiza��o do valor da vari�vel em rela��o ao caminh�o 2
	Desenha(pos, cor);														//Desenha o caminh�o 2
	
	VelMedB = pos / passo;													//Atribui um valor para a vari�vel
	
	
	AjustaCor(preto, branco);												//Chamada da fun��o para alterar a cor do texto
	cout << "Passo:" << limpar << " " << passo <<  "\n" << endl;			//Mostra o valor atual do passo na tela

	AjustaCor(preto, corA);
	cout << left; cout.width(4); cout << "pos:";							//Mostra a posi��o atual do caminh�o
	AjustaCor(corA, preto); 
	cout << " ";
	cout.width(8); cout << posA ;
	AjustaCor(preto, corA);
	cout << right; cout.width(6); cout << "vel med:";						//Mostra a velocidade m�dia do caminh�o
	AjustaCor(corA, preto);
	cout << fixed;
	cout.precision(2);														//Trava a exibi��o dos resultados com 2 casa ap�s a virgula
	cout << " " << VelMedA  << endl;										//Exibe resultados

	AjustaCor(preto, corB);
	cout << left; cout.width(4); cout << "pos:";							//Mostra a posi��o atual do caminh�o
	AjustaCor(corB, preto);
	cout << " ";
	cout.width(8); cout << posB;
	AjustaCor(preto, corB);	
	cout << right; cout.width(6); cout << "vel med:";						//Mostra a velocidade m�dia do caminh�o
	AjustaCor(corB, preto);
	cout << " " << VelMedB <<  endl;										//Exibe resultados
	return 0;
}

void Desenha(int pos,char cor)												 //Fun��o para desenhar o caminh�o do jogador 1
{
	ResetarCor();
	{AjustaCor(cor, preto);
	system("chcp 850 > nul");
	
	cout << "\n";
	WhiteSpace(pos);
	cout << "\xDB\xDB\xDB\xDB\xDB\xDB \xDB\xDC\xDC\t\n";					//Desenha o caminh�o
	WhiteSpace(pos);
	cout << "\xDFOO\xDF\xDF\xDF\xDF\xDFO\xDF\t\n";							//Desenha o caminh�o
	 }

	cout << "----------------------------------------------------------------------------------------------------|------------------";	//Desenha a pista
	cout << "                                                                                                     100\n";

}
void WhiteSpace(int qtd)
{
	while (qtd -- > 0) cout << ' ';											//Cria espa�os em branco
}




