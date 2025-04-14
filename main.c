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
		switch(escolher) {  //switch case para cada uma das 3 opções possiveis
			case 1:
				if(quantos <= cliente ->bitcoin){  //verifica se a  quantidade de moedas desejada para venda e menor que a quantidade que esta armazena na struct do cliente
					quantos_iniciais = quantos;    //faz a variavel quantos_iniciais pegar o mesmo valor da variavel quantos
					quantos = quantos-(quantos * tax_venda_bit);    //a variavel quantos e diminuida fazendo uma subtração do valor vezes a taxa de venda do bitcoin
					valor_recebido = quantos * criptos[0].cotacao;   //guarda na variavel valor_recebido a quantidade de moedas vendidas vezes a cotação do bitcoin
					cliente ->bitcoin -= quantos;   //acessa a struct do cliente e diminui os valores de bitcoin que estão armazenados e diminui pela quantidade que foi digitada para ser vendida
					cliente ->reais += quantos * criptos[0].cotacao; //acessa o valor de reais que esta na struct do cliente e soma com a  quantidade de moedas que foi escolhida para venda que foi multiplicada pelo valor da cotação da moeda
				}else printf("Quantidade desejada e insuficiente.\n");  //mensagem se o valor escolhido para venda for maior que o valor ns struct do cliente
				break;
			case 2:
				if(quantos <= cliente ->etherium){   //verificação de a quantidade escolhida para venda e menor que a quantidade que esta na struct do cliente
					quantos_iniciais = quantos;  //a variavel quantosiniciais fica com o mesmo valor de quanto
					quantos = quantos-(quantos * tax_venda_ethe);  //a variavel quantos e subtraida com o valor escolhido para venda multiplicada pela taxa de venda da moeda
					valor_recebido = quantos * criptos[1].cotacao;  //a variavel velorrecebido recebe o valor da variavel quantos que foi multiplicada pela cotação do etherium
					cliente ->etherium -= quantos;   //acessa os valores de etherium do cliente e  subtrai ela com o valor que foi escolhido para venda
					cliente ->reais += quantos * criptos[1].cotacao; //acessa o valor de reais do cliente se soma com o valor que foi recebido pela venda que seria a quantidade escolhida para venda multiplicado pela cotação da moeda
					
				}else printf("Quantidade desejada e insuficiente.\n");
				break;
			case 3:
				if(quantos <= cliente ->ripple){  //veriffica se a quantidade escolhida para venda e menor que a quantidade que tem no struct do cliente
					quantos_iniciais = quantos;  //as duas variaveis ficam com os valores iguais
					quantos = quantos-(quantos * tax_venda_rpl);   //a variavel  quantos e subtraida com o valor escolhida para venda multiplicada pela taxa de venda da moeda
					valor_recebido = quantos * criptos[2].cotacao;   //a variavel valor_recebido recebe o valor resultante da multiplicação entre a variavel quantos e a cotação da moeda escolhida
					cliente ->ripple -= quantos;  //acessa os valores de ripple do cliente e subtrai ela com o valor que foi escolhido para venda
					cliente ->reais += quantos * criptos[2].cotacao;   //acessa os valores de reais do cliente e soma com os valores resultante da multiplicação entre a variavel quanto e a cotação da moeda escolhida
					
				}else printf("Quantidade desejada e insuficiente.\n");  //else se a quantidade escolhida para venda e maior que a armazenada na struct
				break;
			default:
				printf("Criptomoeda invalida.\n"); //aparece isso se a moeda escolhida não esta cadastrada
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