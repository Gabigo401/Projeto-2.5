#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

typedef struct {   //struct pro cliente1
    char nome[100]; 
    long long cpf;   //long long para armazenar o numero de cpf
    long long senha;
    float reais;
    float bitcoin;
    float etherium;
    float ripple;
}Cliente1;

typedef struct{  //struct pro cliente2
    char nome[100];
    long long cpf; 
    long long senha;
    float reais; 
    float bitcoin;
    float etherium;
    float ripple;
}Cliente2;

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

void leArquivo(){

}


int main(){
    Cliente1 cliente1 = {"Luanda Soliz", 34567895734, 2344568, 500.00, 20.00, 100.00, 648.25};  //adicionando informações no cliente1
    Cliente2 cliente2 = {"Lidia Mamani", 23498745690, 2356235, 300.00, 26.00, 487.00, 654.00};  //e no cliente2

    long long cpfInput;
	long long senhaInput;  //criando duas variaveis para senha e cpf
    int logado = 0;   //int chamada logad
    int ClienteAtual =0;  //int para saber qual cliente acessou
    printf("Bem vindo! Faca o login para continuar.\n");
    printf("Digite o CPF:\n");
    scanf("%lld", &cpfInput);  //scanf para pegar o cpf digitado e guardar no endereço
    printf("Digite a senha:\n");
    scanf("%lld",  &senhaInput);  //scanf para pegar a senha e guardar

    if(cpfInput == cliente1.cpf && senhaInput == cliente1.senha){  //if para comprar o cpf digitado com o cpf do cliente e comparando a senha tambem
    	printf("\nLogin foi feito com sucesso!, %s.\n", cliente1.nome);
		printf("Lendo arquivo de cliente...\n");
        leArquivo("cliente1.txt", &cliente1, historico_transacoes1, &total_transacoes1);  //adicionando a chama da função para ler o arquivo txt
		logado = 1;  //se o login funcionoi a variavel logado vira 1 para mostrar que alguem esta logado
		ClienteAtual = 1;  //a variavel clienteatual muda para 1 para mostrar que e o cliente1
	}
	else if(cpfInput == cliente2.cpf && senhaInput == cliente2.senha){  //comparando se condiz com o cpf ou senha do outro cliente
		printf("\nLogin foi feito com sucesso!, %s.\n", cliente2.nome);
		leArquivo2("cliente2.txt", &cliente2, historico_transacoes2, &total_transacoes2);  //chamada para abrir o arquivo txt
		logado = 1;  //muda para 1 se alguem logou
		ClienteAtual = 2;  //muda para 2 mostrando que e o cliente2 logado
	}
    if (logado){
		int opcao;
		do{
			ExibirMenu();
			scanf("%d", &opcao);
			
			switch(opcao){  //switch case para as opções mostradas no menu
				case 1:
					if(ClienteAtual == 1){
						Carteira1(cliente1);  //chamando a função de mostrar carteira do cliente1
					   escreveArquivo("cliente1.txt", &cliente1, criptos, 3, historico_transacoes1, total_transacoes1);  //chamando a função de escreverarquivo para escrever  tudo em um txt
					}else{
						Carteira2(cliente2);  //se for o cliente2 esse e chamado
                        escreveArquivo2("cliente2.txt", &cliente2, criptos, 3, historico_transacoes2, total_transacoes2);  //salvando em outro txt o do cliente2
				}
					break;
				case 2:
					if(ClienteAtual == 1){
						ExibirExtrato(historico_transacoes1, total_transacoes1);  //exibindo o extrato do cliente1
					   escreveArquivo("cliente1.txt", &cliente1, criptos, 3, historico_transacoes1, total_transacoes1);  //escrevendo no txt o extrato
					}else{
						ExibirExtrato(historico_transacoes2, total_transacoes2);
						escreveArquivo2("cliente2.txt", &cliente2, criptos, 3, historico_transacoes2, total_transacoes2);
				}
					break;
				case 3:
					if(ClienteAtual == 1){
						DepositoCliente1(&cliente1, historico_transacoes1, &total_transacoes1);  //chamando a função de deposito do cliente1
					}else{
						DepositoCliente2(&cliente2, historico_transacoes2, &total_transacoes2);
				}
					break;
				case 4:
					if(ClienteAtual == 1){
						SaqueCliente1(&cliente1, historico_transacoes1, &total_transacoes1);  //chamando a função para o saque do cliente1
					}else{
						SaqueCliente2(&cliente2, historico_transacoes2, &total_transacoes2);
				}
					break;
				case 5:
					if(ClienteAtual ==1){
						CompraCriptoCliente1(&cliente1, criptos, historico_transacoes1, &total_transacoes1);  //chamando a função para comprar as criptomoedas
					}else{
						CompraCriptoCliente2(&cliente2, criptos, historico_transacoes2, &total_transacoes2);
				}
					break;
				case 6:
					if(ClienteAtual == 1){
						VendaCriptoCliente1(&cliente1, criptos, historico_transacoes1, &total_transacoes1);  //chamando a funções de vender as criptomoedas
					}else{
						VendaCriptoCliente2(&cliente2, criptos, historico_transacoes2, &total_transacoes2);
				}
					break;
				case 7:
					{
						atl_cot_cripto(criptos, 3);  //chamando a função de atualizar as cotações
					    mostrar_cots(criptos, 3);   //mostrando as cotações atualizados
					    escreveArquivo("cliente1.txt", &cliente1, criptos, 3, historico_transacoes1, total_transacoes1);  //escrevendo as cotações no txt
                        escreveArquivo2("cliente2.txt", &cliente2, criptos, 3, historico_transacoes2, total_transacoes2);  //salva no txt do cliente 2
				}
					break;
				case 0:
					printf("Saindo do programa:\n");
					break;
				default:
					printf("Opção invalida,  tente outra opção:\n");
					
			}
		}while (opcao != 0);
	}else{
		printf("Cpf ou senha incorretos.\n");
	}
    return 0;
}