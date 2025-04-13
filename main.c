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

void DepositoCliente1(Cliente1 *cliente){  //ao fazer a função dentro do parenteses eu chamo a struct Cliente1 e o *cliente eu to pegando os valores dentro dessa struct e podendo modificalas usando um ponteiro
    float valor;    //variavel float chamada valor para armazenar os valores recebidos
	__int64 senhaInput;  //variavel int com nome de senhaInput
	printf("Digite o valor do deposito desejado:\n");
	scanf("%f", &valor);  //scanf que le o valor digitado e armazena no endereço da variavel valor atraves do &

    printf("Digite a senha para validar o deposito:\n");
	scanf("%lld", &senhaInput);  //scanf que le e armazena a senha recebida pelo usuario no endereço da variavel senhaInput, o algarismo & permite o acesso e armazenamento dessa variavel

    if(senhaInput == cliente ->senha){ //if para validar se a senha e igual a senha armazenada na struct cliente1, usando um ponteiro para verificar
		if( valor > 0){   //if para verificar se o valor e maior que 0, se for o programa continua se não aparece uma mensagem falando que o numero e invalido
		cliente -> reais += valor; // aqui se acessa os valores armazenados em 'reais' na struct cliente atravez de um ponteiro e adicionar nela os valores que foram recebidos do usuario e atualiza a struct com esses novos valores
		printf("Deposito realizado com exito!. Saldo Atual: R$ %.2f\n", cliente -> reais); //printf mostrando o saldo atravez de um ponteiro para pegar os valores de 'reais'
	}else {  //else para mostrar a imagem se o valor for menor que zero
		printf("Valor invalido para fazer o deposito.\n");
	}
	}else {   //else avisando que a senha digitada e incorreta e voltando para o menu
		printf("Senha incorreta, Tente novamente.\n");
	}
}

void DepositoCliente2(Cliente2 *cliente){  
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