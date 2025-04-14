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

void VendaCriptoCliente1(Cliente1 *cliente){
	char confirmacao;   //char de que vai ser usado para receber a confirmação do cliente
	float tax_venda_bit = 0.03;   //float mostrando a taxa de venda do bitcoin
	float tax_venda_ethe = 0.02;  //float mostrando a taxa de venda do etherium
	float tax_venda_rpl = 0.01;   // float mostrando a taxa de vende do ripple
	float quantos, quantos_iniciais, valor_recebido;   //float que vai armazenar a quantidade de criptomoedas que deseja vender, a quantidade que foi escolhida antes de passar pela taxação e a quantidade de dinheiro recebido pela venda
	__int64 senhaInput;    //int que vai guardar a senha pra validação da transação
	int escolher;   //int que vai guardar o numero da opção de criptomoeda escolhida
	printf("\n Escolha a criptomoeda para vender:\n");
	printf("1- Bitcoin\n");
	printf("2- Etherium\n");
	printf("3- Ripple\n");
	scanf("%d", &escolher);  //guarda o numero escolhido na variavel escolher
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