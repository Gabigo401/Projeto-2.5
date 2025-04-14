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

	printf("Digite a quantidade desejada para vender: \n");
	scanf("%f", &quantos);  //armazena o valor de criptomoedas que foi escolhida para vendas na variavel quantos
	
	printf("Digite a senha para validar a operação:\n");
	scanf("%lld", &senhaInput);   //armazena a senha digitada para validar e continuar a compra
	
	if(senhaInput == cliente ->senha){  //compara a senha digitada com a senha que esta armazenada na struct do cliente
        printf("Voce deseja confirmar a compra? (S/N): ");
        scanf(" %c", &confirmacao);   //pede a confirmação do usuario para finalizar a transação

        if(confirmacao != 'S' && confirmacao != 's') {   // se o pedido de confirmação for positivo a transação e concluida e aparece o resumo, se for negativa a operação e cancelada e volta pro menu do programa
            printf("Compra cancelada.\n");
            return;
        }
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