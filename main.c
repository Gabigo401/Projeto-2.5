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

void SaqueCliente1(Cliente1 *cliente){   //a função acessa a struct cliente1 como um ponteiro
    float valor;  //variavel float chamado valor que recebe o valor digitado
	__int64 senhaInput;  //variavel int que recebe a senha digitada
	printf("Digite o valor do saque desejado:\n");
	scanf("%f", &valor);  //scanf que le e armazena na variavel de valor o valor digitado
	
	printf("Digite a senha para validar o saque:\n");
	scanf("%lld", &senhaInput); //scanf que le e armazena na variavel de senha a senha digitada
	
    if(senhaInput == cliente ->senha){   //if que verifica se  senha recebida e igual ao da struct de cliente1
        if(valor > 0 && valor <= cliente ->reais){  //if que verifica se o valor e maior que zero e verifica se e  menor que o valor que ja esta armazenado na struct de cliente1, essa comparação e feita usando alguns ponteiros para acessar os valores de 'reais'
		cliente ->reais -= valor;  //acessa os valores de 'reais' da struct do cliente e faz  o subtração do valor dela com o valor digitado pelo usuario e atualiza ela com os novos valores
		printf("Saque feito com sucesso!. Saldo atual R$ %.2f\n", cliente -> reais);
	}else {  //else que mostra se o valor e invalido ou se o valor digitado e maior que o valor guardado na struct cliente1
		printf("Saldo insuficiente ou valor invalido.");
	}
	 }else {  //else que avisa se a senha estiver e errada
		printf("Senha incorreta, operaï¿½ï¿½o cancelada.\n");
	}
}

void SaqueCliente2(Cliente2 *cliente, transacao historico[], int *total){
	float valor;
	__int64 senhaInput;
	printf("Digite o valor do saque desejado: \n");
	scanf("%f", &valor);
	
	printf("Digite a senha para validar o saque:\n");
	scanf("%lld", &senhaInput);
	
	if(senhaInput == cliente ->senha){
        if(valor > 0 && valor <= cliente -> reais){
		cliente ->reais -= valor;
		printf("Saque feito com sucesso!. Saldo atual R$ %.2f\n", cliente -> reais);
	}else {
		printf("Saldo insuficiente ou valor invalido.");
	}
	}else {
		printf("Senha incorreta, operaï¿½ï¿½o cancelada.\n");
	}
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