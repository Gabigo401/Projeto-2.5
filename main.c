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

void VendaCriptoCliente(){

}

void atl_cot_cripto(){

}

void mostrar_cots(){

}

void escreveArquivo(const char *nome_arquivo, Cliente1 *cliente, Cripto criptos[], int qtdCriptos, transacao historico[], int totalTransacoes){ //crio um ponteiro com uma string constante e um ponteiro para a struct cliente1, um vetor da struct cripto e uma função int para percorrer o vetor sem sair do limite e um vetor pra struct transação junto com um int para o maximo de transações
    FILE *arquivo = fopen(nome_arquivo, "w+"); //criei um ponteiro para o arquivo e abro ele com o fopen e dentro dela dou um nome e a ação desejada, a letra 'W' significa write que seria que eu vou abrir o arquivo e escrever nele
    if (arquivo == NULL) { //um if para confirmar se o arquivo foi aberto
        perror("Erro ao abrir o arquivo");  //mensagem se ocorre um erro na abertura
        return;
    }
    fprintf(arquivo, "%s\n", cliente->nome);  //fprint para salvar o nome do cliente
    fprintf(arquivo, "%lld\n", cliente->cpf);  //fprtinf para salvar o cpf
    fprintf(arquivo, "%lld\n", cliente->senha); //fprint para salvar a senha do usuario
    fprintf(arquivo, "%f\n", cliente->reais);  //fprint para salvar o saldo em reais
    fprintf(arquivo, "%f\n", cliente->bitcoin);  //para salvar os bitcoins que o usuario tem
    fprintf(arquivo, "%f\n", cliente->etherium); //salva os etherium que o usuario tem
    fprintf(arquivo, "%f\n", cliente->ripple);  //salva os ripples que o cliente tem

    fprintf(arquivo, "--- COTAÇÕES ATUAIS ---\n");  //aqui eu salvo as cotações  das moedas que o usuario for atualizando ao usar a opção 7
    int i;   //crio um int chamado i
    for ( i = 0; i < qtdCriptos; i++) {   //uso um for para usar o i para ler as linhas da do vetor de cripto
        fprintf(arquivo, "%s: %.4f\n", criptos[i].nome, criptos[i].cotacao); //aqui eu salvo as cotações atualizados da struct cripto como nome e a cotação e salvo a das 3 moedas sempre que ela foir atualizado
    }
    fprintf(arquivo, "===== EXTRATO DE TRANSAÇÕES =====\n");
    if (totalTransacoes == 0) { //if usado para verificar se o int e igual a 0 e se for o programa fala que não tem nenhum extrato para salvar
        fprintf(arquivo, "Nenhuma transação registrada.\n");
    } else {
    	int i;  //variavel int i
        for (i = 0; i < totalTransacoes; i++) {  //o i e usado para percorrer cada linha do vetor de transacoes
            fprintf(arquivo, "%d. Tipo: %s | Moeda: %s | Quantidade: %.2f\n",  //e aqui eu salvo no arquivo utilizando o ponteiro para salvar dentro dele qual foi o tipo de transação qual moeda usada e a quantidade usada
                    i + 1,   //e incremento ele para ler a proxima linha
                    historico[i].tipo,  //usando o i essa parte acessa a struct transacao e pega o valor de tipo que esta armazenado la
                    historico[i].moeda,  //usando o i ele le o tipo de moeda que esta naquela linha 
                    historico[i].quantidade);  //usando o i ele le a quantidade que foi usado naquela linha naquela transação
        }
    }
    fclose(arquivo);  //aqui o arquivo e fechado apos salvar todas essas informações
}

void escreveArquivo2(const char *nome_arquivo, Cliente2 *cliente, Cripto criptos[], int qtdCriptos, transacao historico_transacoes2[], int total_transacoes2) {
    FILE *arquivo = fopen(nome_arquivo, "w+"); // <- modo correto pra criar e escrever
    if (arquivo == NULL) {
        perror("Erro ao abrir o arquivo");
        return;
    }
    fprintf(arquivo, "%s\n", cliente->nome);
    fprintf(arquivo, "%lld\n", cliente->cpf);
    fprintf(arquivo, "%lld\n", cliente->senha);
    fprintf(arquivo, "%f\n", cliente->reais);
    fprintf(arquivo, "%f\n", cliente->bitcoin);
    fprintf(arquivo, "%f\n", cliente->etherium);
    fprintf(arquivo, "%f\n", cliente->ripple);

    fprintf(arquivo, "--- COTAÇÕES ATUAIS ---\n");
    int i;
    for ( i = 0; i < qtdCriptos; i++) {
        fprintf(arquivo, "%s: %.4f\n", criptos[i].nome, criptos[i].cotacao);
    }
    fprintf(arquivo, "===== EXTRATO DE TRANSAÇÕES =====\n");
    if (total_transacoes2 == 0) {
        fprintf(arquivo, "Nenhuma transação registrada.\n");
    } else {
    	int i;
        for (i = 0; i < total_transacoes2; i++) {
            fprintf(arquivo, "%d. Tipo: %s | Moeda: %s | Quantidade: %.2f\n",
                    i + 1,
                    historico_transacoes2[i].tipo,
                    historico_transacoes2[i].moeda,
                    historico_transacoes2[i].quantidade);
        }
    }
    fclose(arquivo);
}

void leArquivo(){

}

int main(){
    return 0;
}