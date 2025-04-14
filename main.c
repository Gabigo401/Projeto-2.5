#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

typedef struct {  //struct criada para as cotações
	char nome[20];
	float cotacao;
}Cripto;


void ExibirMenu(){

}

void Carteira(){

}

void RegistrarTransacao(){

}

void ExibirExtrato(){

}

void DepositoCliente(){

}

void SaqueCliente(){

}

void CompraCriptoCliente(){

}

void VendaCriptoCliente(){

}

void atl_cot_cripto(Cripto criptos[], int qtd){
	int i;  //cria uma variavel int chamada i
	for(i = 0; i<qtd; i++){  //um laço de repetição aonde o i tem que ser igual a 0 e o i menor que a variavel int qtd  e apos isso a variavel i e incrementada, ela percorre todas as qtd de cripto e a variavel i e o indice de cada moeda começando do 0
		float variar = ((rand() % 1001) / 10000.0f)- 0.05f;  //variavel float chamada variar, no rand ele gera um numero aleatorio entre 0 e 1000 e depois divide esse numero pelo numero 10000.0f, apos isso, o valor resultante da operação anterior e subtraido pelo valor 0.05
		criptos[i].cotacao *= (1+ variar);  //assim gerando um numero -0.05 e +0.05 em outras palavras entre os valores -5% e +5%. Nessa linha o valor que esta armazenado das tres moedas na struct cotação e multiplicada pelo valor resultanto de toda conta anterior assim gerando uma nova cotação
	}
}

void mostrar_cots(){

}

void escreveArquivo(){

}

void leArquivo(){

}


int main(){

	Cripto criptos[3] = {   //adicionado valores para a struct cripto das 3 moedas
		{"Bitcoin", 150000.0},  //valores pra  bitcoin
		{"Ethereum", 8000.0},  //valores para etherium
		{"Ripple", 3.0}   //valores para ripple
		};

    return 0;
}