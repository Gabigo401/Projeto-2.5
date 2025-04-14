#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

typedef struct { //struct para guardar algumas funções ddas transações realizadas
	char tipo[10];
	char moeda[10];
	float quantidade;
}transacao;

void ExibirMenu(){

}

void Carteira(){

}

void RegistrarTransacao(transacao historico[], int *total, const char *tipo, const char *moeda, float quantidade){ //chamando a struct transacao e criando variaveis para os parametros ja criados na struct
	if (*total < 100) { //se  a variavel total for menor que 100 
        strcpy(historico[*total].tipo, tipo);  //usando strcpy para copiar os valores da string para essa variavel
        strcpy(historico[*total].moeda, moeda); //strcpy para copiar os valores da string nessa variavel
        historico[*total].quantidade = quantidade; //pegando a variavel historico e salvando nela as transações ja feitar
        (*total)++;  //incrementando +1 para nunca salva na mesma linha 
    }
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

void mostrar_cots(){

}

void escreveArquivo(){

}

void leArquivo(){

}


int main(){
    transacao historico_transacoes1[100];  //pegando a struct transacao e adicionando uma variavei int para os total e colocando um limite para o historico
    int total_transacoes1 = 0;

    transacao historico_transacoes2[100];  //para o cliente 2
    int total_transacoes2 = 0;


    return 0;
}