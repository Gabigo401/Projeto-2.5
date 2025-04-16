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

void CompraCriptoCliente1(Cliente1 *cliente, Cripto criptos[], transacao historico[], int *total){ //chamando aq os structs das cotações e o de transacoes
    char confirmacao;   //char que vai receber a confirmação do usuario
	float tax_compra_bit = 0.02;   //float que guarda a taxa de compra do bitcoin
	float tax_compra_ethe = 0.01;  //float que guarda a taxa de compra de etherium
	float tax_compra_rpl = 0.01;  //float que guarda a taxa de compra de ripple
	long long senhaInput;  //long long que guarda a senha recebida
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
					RegistrarTransacao(historico, total, "Compra", "Bitcoin", valor);  //chamando a função para registrar as funções
					cliente ->bitcoin  += valor/criptos[0].cotacao;   //atualiza a struct do cliente aonde esta armazenado os valores do bitcoin e soma esses valores com o valor gasto na compra que foi divido com o valor da cotação do bitcoin
					break;  //apos a operação sai dessa opção e vai pro resumo
				case 2:
					valor = valor +(valor * tax_compra_ethe);  //atualiza o valor gasto fazendo uma soma do valor gasto mais o valor vezes a taxa de compra do etherium
					RegistrarTransacao(historico, total, "Compra", "Etherium", valor);  //chamando a função para guardar as transações
					cliente ->etherium += valor/criptos[1].cotacao;  //atualiza a struct do cliente somando os valores de etherium ja armazenados com o valor recebido de etherium apos a compra, aonde o valor gasto e dividio pela cotação do etherium
					break;  //sai do switch
				case 3:
					valor = valor +(valor* tax_compra_rpl);   //atualiza a variavel valor fazendo a multiplicação dela com a taxa do ripple e somando com o valor digitado
					RegistrarTransacao(historico, total, "Compra", "Ripple", valor);  //chamando a função para armazenar as transações
					cliente ->ripple += valor/criptos[2].cotacao; //atualiza a struct do cliente e soma os valores de ripple guardados com os valores de variavel 'valor' que foi dividia pela cotação do ripple
					break; //sai do switch
				default:     //se for alguma outra opção alem dessas 3 fala que a moeda não existe e sai do programa
					printf("Criptomoeda não encontrada.\n");
					return;
			}
			cliente ->reais -= valor; //aqui diminuimos o valor de reais que esta armazenado na struct do cliente subtraindo pela variavel de valor que ja foi somada com a taxa de compra da moeda escolhida
		    if(escolher == 1){  //aqui pegamos o numero que foi escolhido entre as 3 opções de moedas, se foi 1 aparece um resumo dessa transação apresentando alguns valores
                printf("Compra realizada com sucesso!\n");  //mensagem de exito
                printf("Valor gasto: R$ %.2f\n", valor);   //aparece o valor que foi gasto, o valor que aparece ja foi somado com o valor da taxa de compra do bitcoin
                printf("Taxa cobrada: %.0f%%\n", tax_compra_bit*100);  //aqui aparece a taxa cobrada pela compra do bitcoin
		   }
		    else if(escolher == 2){  // se o numero escolhido for 2 aparece esse resumo
			    printf("Compra realizada com sucesso!\n"); 
			    printf("Valor gasto: R$ %.2f\n", valor);   //o valor gasto pela compra do etherium que ja foi somado com a taxa de compra do etherium
			    printf("Taxa cobrada: %.0f%%\n", tax_compra_ethe*100);   //a taxa que se cobra ao comprar o etherium
		    }
		    else if(escolher == 3){  //se o numero escolhido e  3 aparece esse resumo
			    printf("Compra realizada com sucesso!\n");   
			    printf("Valor gasto: R$ %.2f\n", valor);  //o valor gasto pela compra do ripple, o valor gasto ja foi somado com a taxa de compra do ripple
			    printf("Taxa cobrada: %.0f%%\n", tax_compra_rpl*100);  //aparece a taxa de compra do ripple
		    }
		}else {
			printf("Valor e  invalido ou saldo insuficiente.\n");  //else falando se o valor escolhido pela comprae invalido se for menor que 0 ou se o saldo e insuficiente se for maior que o valor que esta armazenado na struct do cliente
		}
	}else {    //else falando que a senha digitada pelo usuario esta incorreta da senha que esta na struct do cliente 
			printf("Senha incorreta, operação cancelada.\n");
	}
}

void CompraCriptoCliente2(Cliente2 *cliente, Cripto criptos[], transacao historico[], int *total){
    char confirmacao;   
	float tax_compra_bit = 0.02;   
	float tax_compra_ethe = 0.01;  
	float tax_compra_rpl = 0.01;  
	long long senhaInput;  
	int escolher; 
	float valor;  
	printf("\n Escolha a criptomoeda que deseja comprar:\n"); 
	printf("1 - Bitcoins:\n");
	printf("2 - Ethereum:\n");
	printf("3 - Ripple:\n");
	scanf("%d", &escolher);  
	
	printf("Digite o  valor que deseja gastar na compra: \n");
	scanf("%f", &valor); 
	
	printf("Digite a senha para validar a compra:\n");
	scanf("%lld", &senhaInput); 

	if(senhaInput == cliente ->senha){  
	    printf("Voce deseja confirmar a compra? (S/N): ");
        scanf(" %c", &confirmacao);  

        if(confirmacao != 'S' && confirmacao != 's') {     
            printf("Compra cancelada.\n");
            return;  
        }
		if(valor > 0 && valor <= cliente->reais){    
			switch(escolher){   
				case 1:  
					valor = valor +(valor * tax_compra_bit);  
					cliente ->bitcoin  += valor/criptos[0].cotacao;   
					RegistrarTransacao(historico, total, "Compra", "Bitcoin", valor);
					break;  
				case 2:
					valor = valor +(valor * tax_compra_ethe); 
					cliente ->etherium += valor/criptos[1].cotacao; 
					RegistrarTransacao(historico, total, "Compra", "Etherium", valor); 
					break; 
				case 3:
					valor = valor +(valor* tax_compra_rpl);   
					cliente ->ripple += valor/criptos[2].cotacao; 
					RegistrarTransacao(historico, total, "Compra", "Ripple", valor);
					break; 
				default:     
					printf("Criptomoeda não encontrada.\n");
					return;
			}
			cliente ->reais -= valor; 
		    if(escolher == 1){  
                printf("Compra realizada com sucesso!\n");  
                printf("Valor gasto: R$ %.2f\n", valor);   
                printf("Taxa cobrada: %.0f%%\n", tax_compra_bit*100);  
		   }
		    else if(escolher == 2){  
			    printf("Compra realizada com sucesso!\n"); 
			    printf("Valor gasto: R$ %.2f\n", valor);   
			    printf("Taxa cobrada: %.0f%%\n", tax_compra_ethe*100);   
		    }
		    else if(escolher == 3){  
			    printf("Compra realizada com sucesso!\n");   
			    printf("Valor gasto: R$ %.2f\n", valor); 
			    printf("Taxa cobrada: %.0f%%\n", tax_compra_rpl*100);  
		    }
		}else {
			printf("Valor e  invalido ou saldo insuficiente.\n");  
		}
	}else {   
			printf("Senha incorreta, operação cancelada.\n");
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