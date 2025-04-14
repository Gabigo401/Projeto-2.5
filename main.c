#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>


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

void atl_cot_cripto(){

}

void mostrar_cots(Cripto criptos[], int qtd){  //acessa a struct cripto e cria uma variavel int chamada qtd
	int i;  //cria uma variavel int chamada i
	printf("Cotações:\n");
	for(i = 0; i < qtd; i++){   //laço de repetição para ler todos os valores da struct
		printf("%s: R$ %.2f\n", criptos[i].nome, criptos[i].cotacao);  //printf para mostrar todos os valores da struct
	}
}

void escreveArquivo(){

}

void leArquivo(){

}


int main(){
    return 0;
}