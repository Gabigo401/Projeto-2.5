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

	if(senhaInput == cliente ->senha){  //verifica se a  senha e igual a senha da struct cliente1 se for igual ele continua o programa
	    printf("Voce deseja confirmar a compra? (S/N): ");
        scanf(" %c", &confirmacao);  //scanf que recebe e armazena a resposta do usuario  se ele deseja confirmar a compra ou não

        if(confirmacao != 'S' && confirmacao != 's') {     //if que verifica se a resposta do usuario, se for sim a operação e feita e o programa volta pro menu mas se for não ele cancela a operação e volta pro menu
            printf("Compra cancelada.\n");
            return;    //return pro menu se a compra for cancelada
        }
		if(valor > 0 && valor <= cliente->reais){    //verifica se o valor digitado e maior que zero e se ele e menor que o dinheiro armazena na struct do cliente
			switch(escolher){   //switch case para a variavel de escolher, ela so e apresenta se todos os ifs anteriores forem passado
				case 1:  //se a opção for 1
					valor = valor +(valor * tax_compra_bit);   //atualiza a variavel 'valor', fazendo a multiplicação dela com a taxa do bitcoin e somando com o valor digitado inicialmente
					cliente ->bitcoin  += valor/criptos[0].cotacao;   //atualiza a struct do cliente aonde esta armazenado os valores do bitcoin e soma esses valores com o valor gasto na compra que foi divido com o valor da cotação do bitcoin
					break;  //apos a operação sai dessa opção e vai pro resumo
				case 2:
					valor = valor +(valor * tax_compra_ethe);  //atualiza o valor gasto fazendo uma soma do valor gasto mais o valor vezes a taxa de compra do etherium
					cliente ->etherium += valor/criptos[1].cotacao;  //atualiza a struct do cliente somando os valores de etherium ja armazenados com o valor recebido de etherium apos a compra, aonde o valor gasto e dividio pela cotação do etherium
					break;  //sai do switch
				case 3:
					valor = valor +(valor* tax_compra_rpl);   //atualiza a variavel valor fazendo a multiplicação dela com a taxa do ripple e somando com o valor digitado
					cliente ->ripple += valor/criptos[2].cotacao; //atualiza a struct do cliente e soma os valores de ripple guardados com os valores de variavel 'valor' que foi dividia pela cotação do ripple
					break; //sai do switch
				default:     //se for alguma outra opção alem dessas 3 fala que a moeda não existe e sai do programa
					printf("Criptomoeda não encontrada.\n");
					return;
			}
	
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