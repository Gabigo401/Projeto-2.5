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

  *total_Transacoes1 = 0;  //ponteiro para o total de transacoes
  while (fscanf(arquivo, "%d. Tipo: %s | Moeda: %s | Quantidade: %f",  //um while para ler as linhas do arquivo aonde estão as transações, o fscanf para ler o arquivo, o %d para ler o indice ou contador, o %s para ler a string de qual tipo, %s para ler qual moeda esta escrita e um %f para ler o valor que esta naquela linha 
                &(*total_Transacoes1), //acessar o endereço do ponteiro desse int
                historico_transacoes1[*total_Transacoes1].tipo,  //acessa e le essa parte de string
                historico_transacoes1[*total_Transacoes1].moeda,  //acessa e le a parte de qual moeda e 
                &historico_transacoes1[*total_Transacoes1].quantidade) == 4) { //acessa a parte de quantidade que e float por isso o & para o scanf conseguir ler
    (*total_Transacoes1)++; //incrementa o valor dessa variavel
  }
  fclose(arquivo);
}

void leArquivo2(const char *nome_arquivo, Cliente2 *cliente, transacao historico_transacoes2[], int *total_Transacoes2) {
	FILE *arquivo = fopen(nome_arquivo, "r");
	if (arquivo == NULL) {
	  printf("Erro ao abrir o arquivo %s!\n", nome_arquivo);
	  return;
	}
  
	fscanf(arquivo, "%s", cliente->nome);
	fscanf(arquivo, "%lld", &cliente->cpf);
	fscanf(arquivo, "%lld", &cliente->senha);
	fscanf(arquivo, "%f", &cliente->reais);
	fscanf(arquivo, "%f", &cliente->bitcoin);
	fscanf(arquivo, "%f", &cliente->etherium);
	fscanf(arquivo, "%f", &cliente->ripple);
  
	*total_Transacoes2 = 0;
	while (fscanf(arquivo, "%d. Tipo: %s | Moeda: %s | Quantidade: %f",
				  &(*total_Transacoes2),
				  historico_transacoes2[*total_Transacoes2].tipo,
				  historico_transacoes2[*total_Transacoes2].moeda,
				  &historico_transacoes2[*total_Transacoes2].quantidade) == 4) {
	  (*total_Transacoes2)++;
	}
  
	fclose(arquivo);
  }


int main(){
    return 0;
}