#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

typedef struct {
    char nome[100];
    __int64 cpf;
    __int64 senha;
    float reais;
    float bitcoin;
    float etherium;
    float ripple;
}Cliente1;

typedef struct{
    char nome[100];
    __int64 cpf;
    __int64 senha;
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
    Cliente1 cliente1 = {"Luanda Soliz", 34567895734, 2344568, 500.00, 20.00, 100.00, 648.25};
    Cliente2 cliente2 = {"Lidia Mamani", 23498745690, 2356235, 300.00, 26.00, 487.00, 654.00};

    __int64 cpfInput, senhaInput;
    int logado = 0;
    int ClienteAtual =0;
    printf("Bem vindo! Faca o login para continuar.\n");
    printf("Digite o CPF:\n");
    scanf("%lld", &cpfInput);
    printf("Digite a senha:\n");
    scanf("%lld",  &senhaInput);

    if(cpfInput == cliente1.cpf && senhaInput == cliente1.senha){
    	printf("\nLogin foi feito com sucesso!, %s.\n", cliente1.nome);
		logado = 1;
		ClienteAtual = 1;
	}
	else if(cpfInput == cliente2.cpf && senhaInput == cliente2.senha){
		printf("\nLogin foi feito com sucesso!, %s.\n", cliente2.nome);
		logado = 1;
		ClienteAtual = 2;
	}
    
    if (logado){
		int opcao;
		do{
			ExibirMenu();
			scanf("%d", &opcao);
			
			switch(opcao){
				case 1:
					if(ClienteAtual == 1){
					}else{
				}
					break;
				case 2:
					if(ClienteAtual == 1){
					}else{
				}
					break;
				case 3:
					if(ClienteAtual == 1){
					}else{
				}
					break;
				case 4:
					if(ClienteAtual == 1){
					}else{
				}
					break;
				case 5:
					if(ClienteAtual ==1){
					}else{
				}
					break;
				case 6:
					if(ClienteAtual == 1){
					}else{
				}
					break;
				case 7:
					{
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