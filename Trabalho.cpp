#include <iostream>
#include <ctime>
#include "cores.h"
#include "pacote.h"
#include "rede.h"
using namespace std;

//Protótipos
void Desenha(int, char);
void WhiteSpace(int);

unsigned int rede;

int main()
{
	
	int posA, posB, velA, velB;												//Declaração de variáveis
	char cor, corA, corB;													//Declaração de variáveis
	bool oleoA, oleoB;														//Declaração de variáveis
	double VelMedA, VelMedB, pos;											//Declaração de variáveis
	
	srand(unsigned(time(NULL)));											//Gerador de sementes para rand
	
// Inicializa dados:
	posA = 0;																// - Posição
	posB = 0;																// - Posição
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

		AjustaCor(preto, branco);											//Chamada da função para alterar a cor do texto
		cout << "Passo:" << limpar << " " << passo << endl;					//Mostra o valor atual do passo na tela

		pos = posA;															//Inicialização da variável com dados em relação ao caminhão 1
		cor = corA;															//Inicialização da variável com dados em relação ao caminhão 1
		Desenha(pos, cor);													//Desenha caminhão 1
		

		velA = rand() % 10 + 1;												//Atualiza velocidade
						
		oleoA = rand() % 2;													//Atualiza estado da pista
		
		// Transmite, recebe e processa dados

		int net = 0;
		ResetarCor();
		cout << "transmitindo dados..." << endl;
		transmitir(passo, cor, posA, velA, oleoA);							//Chama a função transmitir, que acionará o empacotamento de dados e enviará para a rede
		ResetarCor();
		cout << "recebendo dados..." << endl;
		receber();															//Chama a função receber, para ler os dados da rede
		ResetarCor();
		cout << "processando dados..." << endl;
		posA = processar(rede);												//Guarda a posição de do caminhão 2 e chama a função processar
		
		AjustaCor(preto, branco);											//Chamada da função para alterar a cor do texto
		cout << "\n\nPasso:" << limpar << " " << passo << endl;				//Mostra o valor atual do passo na tela

		pos = posB;															//Atualização do valor da variável em relação ao caminhão 2
		cor = corB;															//Atualização do valor da variável em relação ao caminhão 2
		Desenha(pos, cor);													//Desenha caminhão 2
		
		velB = rand() % 10 + 1;												//Atualiza velocidade
		
		oleoB = rand() % 2;													//Atualiza estado da pista


		// Transmite, recebe e processa dados
		ResetarCor();
		cout << "transmitindo dados..." << endl;
		transmitir(passo, cor, posB, velB, oleoB);							//Chama a função transmitir, que acionará o empacotamento de dados e enviará para a rede
		ResetarCor();
		cout << "recebendo dados..." << endl;
		receber();															//Chama a função receber, para ler os dados da rede
		ResetarCor();
		cout << "processando dados..." << endl;
		posB = processar(rede);												//Guarda a posição de do caminhão 2 e chama a função processar
				

		system("pause");													//Aguarda pressionamento de tecla
			

			passo = passo + 1;
	} while (posA <= 100 && posB <= 100);
	
	system("cls");															//Limpa tela

	pos = posA;																//Atualização do valor da variável em relação ao caminhão 1
	cor = corA;																//Atualização do valor da variável em relação ao caminhão 1
	Desenha(pos, cor);														//Desenha o caminhão 1
	
	VelMedA = pos / passo;													//Atribui um valor para a variável

	pos = posB;																//Atualização do valor da variável em relação ao caminhão 2
	cor = corB;																//Atualização do valor da variável em relação ao caminhão 2
	Desenha(pos, cor);														//Desenha o caminhão 2
	
	VelMedB = pos / passo;													//Atribui um valor para a variável
	
	
	AjustaCor(preto, branco);												//Chamada da função para alterar a cor do texto
	cout << "Passo:" << limpar << " " << passo <<  "\n" << endl;			//Mostra o valor atual do passo na tela

	AjustaCor(preto, corA);
	cout << left; cout.width(4); cout << "pos:";							//Mostra a posição atual do caminhão
	AjustaCor(corA, preto); 
	cout << " ";
	cout.width(8); cout << posA ;
	AjustaCor(preto, corA);
	cout << right; cout.width(6); cout << "vel med:";						//Mostra a velocidade média do caminhão
	AjustaCor(corA, preto);
	cout << fixed;
	cout.precision(2);														//Trava a exibição dos resultados com 2 casa após a virgula
	cout << " " << VelMedA  << endl;										//Exibe resultados

	AjustaCor(preto, corB);
	cout << left; cout.width(4); cout << "pos:";							//Mostra a posição atual do caminhão
	AjustaCor(corB, preto);
	cout << " ";
	cout.width(8); cout << posB;
	AjustaCor(preto, corB);	
	cout << right; cout.width(6); cout << "vel med:";						//Mostra a velocidade média do caminhão
	AjustaCor(corB, preto);
	cout << " " << VelMedB <<  endl;										//Exibe resultados
	return 0;
}

void Desenha(int pos,char cor)												 //Função para desenhar o caminhão do jogador 1
{
	ResetarCor();
	{AjustaCor(cor, preto);
	system("chcp 850 > nul");
	
	cout << "\n";
	WhiteSpace(pos);
	cout << "\xDB\xDB\xDB\xDB\xDB\xDB \xDB\xDC\xDC\t\n";					//Desenha o caminhão
	WhiteSpace(pos);
	cout << "\xDFOO\xDF\xDF\xDF\xDF\xDFO\xDF\t\n";							//Desenha o caminhão
	 }

	cout << "----------------------------------------------------------------------------------------------------|------------------";	//Desenha a pista
	cout << "                                                                                                     100\n";

}
void WhiteSpace(int qtd)
{
	while (qtd -- > 0) cout << ' ';											//Cria espaços em branco
}




