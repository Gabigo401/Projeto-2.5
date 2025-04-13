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



    
    return 0;
}