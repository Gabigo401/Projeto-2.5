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
  fscanf(arquivo, "%s", cliente->nome);   //fscanf para ler o nome que esta salvo no arquivo
  fscanf(arquivo, "%lld", &cliente->cpf); //fscanf para ler o cpf
  fscanf(arquivo, "%lld", &cliente->senha);  //para ler a senha
  fscanf(arquivo, "%f", &cliente->reais);  //o saldo em reais
  fscanf(arquivo, "%f", &cliente->bitcoin);  //o saldo em bitcoins
  fscanf(arquivo, "%f", &cliente->etherium); //o saldo em etherium
  fscanf(arquivo, "%f", &cliente->ripple);  //o saldo em ripple
}


int main(){
    return 0;
}