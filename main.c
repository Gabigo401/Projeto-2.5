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

void DepositoCliente1(Cliente1 *cliente){
    float valor;
	__int64 senhaInput;
	printf("Digite o valor do deposito desejado:\n");
	scanf("%f", &valor);

    printf("Digite a senha para validar o deposito:\n");
	scanf("%lld", &senhaInput);

    if(senhaInput == cliente ->senha){
		if( valor > 0){
		cliente -> reais += valor;
		printf("Deposito realizado com exito!. Saldo Atual: R$ %.2f\n", cliente -> reais);
	}else {
		printf("Valor invalido para fazer o deposito.\n");
	}
	}else {
		printf("Senha incorreta, Tente novamente.\n");
	}
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
    return 0;
}