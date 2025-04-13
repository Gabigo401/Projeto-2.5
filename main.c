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

void CompraCriptoCliente(Cliente1 *cliente){
    char confirmacao;   //char que vai receber a confirmação do usuario
	float tax_compra_bit = 0.02;   //float que guarda a taxa de compra do bitcoin
	float tax_compra_ethe = 0.01;  //float que guarda a taxa de compra de etherium
	float tax_compra_rpl = 0.01;  //float que guarda a taxa de compra de ripple
	__int64 senhaInput;  //int que guarda a senha recebida
	int escolher;  //int que guarda o numero da opção que foi escolhida pelo usuario entre as três moedas
	float valor;   //float que guarda o valor digitado pelo usuario de quantos reais ele quer gastar na compra
	printf("\n Escolha a criptomoeda que deseja comprar:\n");  //apresentação das 3 criptomoedas e o numero de suas opções
	printf("1 - Bitcoins:\n");
	printf("2 - Ethereum:\n");
	printf("3 - Ripple:\n");
	scanf("%d", &escolher);  //scanf que recebe o numero escolhido e guarda no endereço da variavel 'escolher'
	
	printf("Digite o  valor que deseja gastar na compra: \n");
	scanf("%f", &valor);  //scanf que guarda o  valor que se deseja gastar na compra de alguma criptomoeda no endereço da variavel 'valor'
	
	printf("Digite a senha para validar a compra:\n");
	scanf("%lld", &senhaInput);  //scanf que recebe a senha digitada pelo usuario e guarda no endereço da variavel senha
	
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
    return 0;
}