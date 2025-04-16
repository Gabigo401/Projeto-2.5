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

void mostrar_cots(){

}

void escreveArquivo(const char *nome_arquivo, Cliente1 *cliente, Cripto criptos[], int qtdCriptos, transacao historico[], int totalTransacoes){ //crio um ponteiro com uma string constante e um ponteiro para a struct cliente1, um vetor da struct cripto e uma função int para percorrer o vetor sem sair do limite e um vetor pra struct transação junto com um int para o maximo de transações
    FILE *arquivo = fopen(nome_arquivo, "w"); //criei um ponteiro para o arquivo e abro ele com o fopen e dentro dela dou um nome e a ação desejada, a letra 'W' significa write que seria que eu vou abrir o arquivo e escrever nele
    if (arquivo == NULL) { //um if para confirmar se o arquivo foi aberto
        perror("Erro ao abrir o arquivo");  //mensagem se ocorre um erro na abertura
        return;
    }
}

void leArquivo(){

}


int main(){
    return 0;
}