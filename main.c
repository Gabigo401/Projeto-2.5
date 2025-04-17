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

void escreveArquivo(){

}

void leArquivo(const char *nome_arquivo, Cliente1 *cliente, transacao historico_transacoes1[], int *total_Transacoes1){  //usando ponteiro num char constante e acessando a struct do cliente1 e de transacao usando um vetor, alem disso, criando um int com ponteiro
	FILE *arquivo = fopen(nome_arquivo, "r");  //aqui o arquivo como ponteiro usando o fopen e o nome dele e uso a ação de ler 'r'
  if (arquivo == NULL) {  //um if para verificar se o arquivo foi aberto
    printf("Erro ao abrir o arquivo %s!\n", nome_arquivo);
    return;
  }
}


int main(){
    return 0;
}