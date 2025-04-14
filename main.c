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

void ExibirExtrato(transacao historico[], int total){  //pegando a struct transações e a variavel de historico alem de criar um int chamado total
	int i;   //criando um int chamado  i
    printf("\n===== EXTRATO DE TRANSAÇÕES =====\n");

    if (total == 0) {   //se a variavel total for 0 fala que não foi feita nenhuma transação ainda
        printf("Nenhuma transação registrada.\n");  
        return;
    }

    for (i = 0; i < total; i++) {   //agora aq pegamos o 1 e inchementamos ele ao ler cada linha da variavel historico
        printf("%d. Tipo: %s | Moeda: %s | Quantidade: %.2f\n",  //apos ler cada linha essa linha aparece pelo printf mostrando qual tipo de transação, qual moeda foi usado e a quantidade usada
               i + 1,  //incrementa o i para ler a proxima linha mas sempre tem que ser menor que o numero de transações ja feita
               historico[i].tipo,    //mostra o tipo
               historico[i].moeda,  //qual moeda
               historico[i].quantidade);   //e a quantidade
    }
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
    return 0;
}