#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

typedef struct {  //struct criada para as cotações
	char nome[20];
	float cotacao;
}Cripto;

typedef struct { //struct para guardar algumas funções ddas transações realizadas
	char tipo[10];
	char moeda[10];
	float quantidade;
}transacao;

typedef struct { //struct pro cliente1
    char nome[100];
    long long cpf;
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
    printf("Menu: \n");
    printf("1- Carteira do Investidor\n");
    printf("2- Extratos\n");
    printf("3- Deposito\n");
    printf("4- Saque\n");
    printf("5- Comprar criptomoedas\n");
    printf("6- Vender criptomoedas\n");
    printf("7- Atualizar cotaï¿½ï¿½es\n");
    printf("0 - Sair\n");
}

void Carteira1(Cliente1 cliente){
    printf("\n carteira de %s\n", cliente.nome);
	printf("Reais: R$ %.2f\n", cliente.reais);
	printf("Bitcoins: %.2f\n", cliente.bitcoin);
	printf("Etherium: %.2f\n", cliente.etherium);
	printf("Ripple: %.2f\n", cliente.ripple);
}

void Carteira2(Cliente2 cliente){
    printf("\n carteira de %s\n", cliente.nome);
	printf("Reais: R$ %.2f\n", cliente.reais);
	printf("Bitcoins: %.2f\n", cliente.bitcoin);
	printf("Etherium: %.2f\n", cliente.etherium);
	printf("Ripple: %.2f\n", cliente.ripple);
}

void RegistrarTransacao(transacao historico[], int *total, const char *tipo, const char *moeda, float quantidade){ //chamando a struct transacao e criando variaveis para os parametros ja criados na struct
	if (*total < 100) { //se  a variavel total for menor que 100 
        strcpy(historico[*total].tipo, tipo);  //usando strcpy para copiar os valores da string para essa variavel
        strcpy(historico[*total].moeda, moeda); //strcpy para copiar os valores da string nessa variavel
        historico[*total].quantidade = quantidade; //pegando a variavel historico e salvando nela as transações ja feitar
        (*total)++;  //incrementando +1 para nunca salva na mesma linha 
    }
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

void DepositoCliente1(Cliente1 *cliente, transacao historico[], int *total){  //ao fazer a função dentro do parenteses eu chamo a struct Cliente1 e o *cliente eu to pegando os valores dentro dessa struct e podendo modificalas usando um ponteiro// chamando a struct de transações para guardar nelas
    float valor;    //variavel float chamada valor para armazenar os valores recebidos
	long long senhaInput;  //variavel long long com nome de senhaInput
	printf("Digite o valor do deposito desejado:\n");
	scanf("%f", &valor);  //scanf que le o valor digitado e armazena no endereço da variavel valor atraves do &

    printf("Digite a senha para validar o deposito:\n");
	scanf("%lld", &senhaInput);  //scanf que le e armazena a senha recebida pelo usuario no endereço da variavel senhaInput, o algarismo & permite o acesso e armazenamento dessa variavel

    if(senhaInput == cliente ->senha){ //if para validar se a senha e igual a senha armazenada na struct cliente1, usando um ponteiro para verificar
		if( valor > 0){   //if para verificar se o valor e maior que 0, se for o programa continua se não aparece uma mensagem falando que o numero e invalido
		cliente -> reais += valor; // aqui se acessa os valores armazenados em 'reais' na struct cliente atravez de um ponteiro e adicionar nela os valores que foram recebidos do usuario e atualiza a struct com esses novos valores
		RegistrarTransacao(historico, total, "Deposito", "Reais", valor);  //chamando a função registrarTransacao para guardar nelas as transações
		printf("Deposito realizado com exito!. Saldo Atual: R$ %.2f\n", cliente -> reais); //printf mostrando o saldo atravez de um ponteiro para pegar os valores de 'reais'
	}else {  //else para mostrar a imagem se o valor for menor que zero
		printf("Valor invalido para fazer o deposito.\n");
	}
	}else {   //else avisando que a senha digitada e incorreta e voltando para o menu
		printf("Senha incorreta, Tente novamente.\n");
	}
}

void DepositoCliente2(Cliente2 *cliente, transacao historico[], int *total){  
    float valor;    
	long long senhaInput;  
	printf("Digite o valor do deposito desejado:\n");
	scanf("%f", &valor);  

    printf("Digite a senha para validar o deposito:\n");
	scanf("%lld", &senhaInput);  

    if(senhaInput == cliente ->senha){ 
		if( valor > 0){   
		cliente -> reais += valor; 
		RegistrarTransacao(historico, total, "Deposito", "Reais", valor);
		printf("Deposito realizado com exito!. Saldo Atual: R$ %.2f\n", cliente -> reais); 
	}else { 
		printf("Valor invalido para fazer o deposito.\n");
	}
	}else {   
		printf("Senha incorreta, Tente novamente.\n");
	}
}

void SaqueCliente1(Cliente1 *cliente, transacao historico[], int *total){   //a função acessa a struct cliente1 como um ponteiro // chamando a struct de transacao para guardar nelas as operações
    float valor;  //variavel float chamado valor que recebe o valor digitado
	long long senhaInput;  //variavel long long que recebe a senha digitada
	printf("Digite o valor do saque desejado:\n");
	scanf("%f", &valor);  //scanf que le e armazena na variavel de valor o valor digitado
	
	printf("Digite a senha para validar o saque:\n");
	scanf("%lld", &senhaInput); //scanf que le e armazena na variavel de senha a senha digitada
	
    if(senhaInput == cliente ->senha){   //if que verifica se  senha recebida e igual ao da struct de cliente1
        if(valor > 0 && valor <= cliente ->reais){  //if que verifica se o valor e maior que zero e verifica se e  menor que o valor que ja esta armazenado na struct de cliente1, essa comparação e feita usando alguns ponteiros para acessar os valores de 'reais'
		cliente ->reais -= valor;  //acessa os valores de 'reais' da struct do cliente e faz  o subtração do valor dela com o valor digitado pelo usuario e atualiza ela com os novos valores
		RegistrarTransacao(historico, total, "Saque", "Reais", valor);  //chamando a função de registrar as transações de todas as operações que foram feitar aqui
		printf("Saque feito com sucesso!. Saldo atual R$ %.2f\n", cliente -> reais);
	}else {  //else que mostra se o valor e invalido ou se o valor digitado e maior que o valor guardado na struct cliente1
		printf("Saldo insuficiente ou valor invalido.");
	}
	 }else {  //else que avisa se a senha estiver e errada
		printf("Senha incorreta, operação cancelada.\n");
	}
}

void SaqueCliente2(Cliente2 *cliente, transacao historico[], int *total){
	float valor;
	long long senhaInput;
	printf("Digite o valor do saque desejado: \n");
	scanf("%f", &valor);
	
	printf("Digite a senha para validar o saque:\n");
	scanf("%lld", &senhaInput);
	
	if(senhaInput == cliente ->senha){
        if(valor > 0 && valor <= cliente -> reais){
		cliente ->reais -= valor;
		RegistrarTransacao(historico, total, "Saque", "Reais", valor);
		printf("Saque feito com sucesso!. Saldo atual R$ %.2f\n", cliente -> reais);
	}else {
		printf("Saldo insuficiente ou valor invalido.");
	}
	}else {
		printf("Senha incorreta, operação cancelada.\n");
	}
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

void VendaCriptoCliente1(Cliente1 *cliente, Cripto criptos[], transacao historico[], int *total){  //chamando a struct de criptos e a de transacao
	char confirmacao;   //char de que vai ser usado para receber a confirmação do cliente
	float tax_venda_bit = 0.03;   //float mostrando a taxa de venda do bitcoin
	float tax_venda_ethe = 0.02;  //float mostrando a taxa de venda do etherium
	float tax_venda_rpl = 0.01;   // float mostrando a taxa de vende do ripple
	float quantos, quantos_iniciais, valor_recebido;   //float que vai armazenar a quantidade de criptomoedas que deseja vender, a quantidade que foi escolhida antes de passar pela taxação e a quantidade de dinheiro recebido pela venda
	long long senhaInput;    //long long que vai guardar a senha pra validação da transação
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
				    RegistrarTransacao(historico, total, "Venda", "Bitcoin", quantos); //chamada da função para salvar as operações
					printf("Venda realizada com sucesso!\n");
					printf("Quantidade vendida: %.2f Bitcoins\n", quantos_iniciais);  //mostra a  quantidade vendida se for bitcoin
					printf("Valor recebido: R$ %.2f\n", valor_recebido);   //mostra o valor recebido pela venda da moeda
					printf("Taxa cobrada: %.0f%%\n", tax_venda_bit * 100);  //mostra a taxa que foi cobrada pela venda
				}else {
					printf("Quantidade desejada e insuficiente.\n");  //mensagem se o valor escolhido para venda for maior que o valor ns struct do cliente
				}
				break;
			case 2:
				if(quantos <= cliente ->etherium){   //verificação de a quantidade escolhida para venda e menor que a quantidade que esta na struct do cliente
					quantos_iniciais = quantos;  //a variavel quantosiniciais fica com o mesmo valor de quanto
					quantos = quantos-(quantos * tax_venda_ethe);  //a variavel quantos e subtraida com o valor escolhido para venda multiplicada pela taxa de venda da moeda
					valor_recebido = quantos * criptos[1].cotacao;  //a variavel velorrecebido recebe o valor da variavel quantos que foi multiplicada pela cotação do etherium
					cliente ->etherium -= quantos;   //acessa os valores de etherium do cliente e  subtrai ela com o valor que foi escolhido para venda
					cliente ->reais += quantos * criptos[1].cotacao; //acessa o valor de reais do cliente se soma com o valor que foi recebido pela venda que seria a quantidade escolhida para venda multiplicado pela cotação da moeda
					RegistrarTransacao(historico, total, "Venda", "Etherium", quantos);  //chamando para salvar as operações
					printf("Venda feita com sucesso!\n");
					printf("Quantidade vendida: %.2f Ethereum\n", quantos_iniciais);  //mostra a quantidade venda
					printf("Valor recebido: R$ %.2f\n", valor_recebido);  //mostra o valor recebido pela venda
					printf("Taxa cobrada: %.0f%%\n", tax_venda_ethe * 100); //mostra a taxa de venda da moeda
				}else {
					printf("Quantidade desejada e insuficiente.\n");
				}
				break;
			case 3:
				if(quantos <= cliente ->ripple){  //veriffica se a quantidade escolhida para venda e menor que a quantidade que tem no struct do cliente
					quantos_iniciais = quantos;  //as duas variaveis ficam com os valores iguais
					quantos = quantos-(quantos * tax_venda_rpl);   //a variavel  quantos e subtraida com o valor escolhida para venda multiplicada pela taxa de venda da moeda
					valor_recebido = quantos * criptos[2].cotacao;   //a variavel valor_recebido recebe o valor resultante da multiplicação entre a variavel quantos e a cotação da moeda escolhida
					cliente ->ripple -= quantos;  //acessa os valores de ripple do cliente e subtrai ela com o valor que foi escolhido para venda
					cliente ->reais += quantos * criptos[2].cotacao;   //acessa os valores de reais do cliente e soma com os valores resultante da multiplicação entre a variavel quanto e a cotação da moeda escolhida
					RegistrarTransacao(historico, total, "Venda", "Ripple", quantos);  //chamando para salvar as operações
					printf("Venda feita com sucesso!\n");
					printf("Quantidade vendida: %.2f Ripple\n", quantos_iniciais);  //mostra a quantidade escolhida para venda
					printf("Valor recebido: R$ %.2f\n", valor_recebido);  //mostra o valor recebido pela venda
					printf("Taxa cobrada: %.0f%%\n", tax_venda_rpl * 100);  //mostra a taxa de venda da moeda
				}else {
					printf("Quantidade desejada e insuficiente.\n");  //else se a quantidade escolhida para venda e maior que a armazenada na struct
				}
				break;
			default:
				printf("Criptomoeda invalida.\n"); //aparece isso se a moeda escolhida não esta cadastrada
		}
	}else {  //else que se mostra se a senha inserida pelo usuario esta errada
		printf("Senha incorreta, operação cancelada.\n");
	}
}

void VendaCriptoCliente2(Cliente2 *cliente, Cripto criptos[], transacao historico[], int *total){
	char confirmacao;   
	float tax_venda_bit = 0.03;   
	float tax_venda_ethe = 0.02;  
	float tax_venda_rpl = 0.01;   
	float quantos, quantos_iniciais, valor_recebido;   
	long long senhaInput;    
	int escolher;   
	printf("\n Escolha a criptomoeda para vender:\n");
	printf("1- Bitcoin\n");
	printf("2- Etherium\n");
	printf("3- Ripple\n");
	scanf("%d", &escolher); 

	printf("Digite a quantidade desejada para vender: \n");
	scanf("%f", &quantos);  
	
	printf("Digite a senha para validar a operação:\n");
	scanf("%lld", &senhaInput);  
	
	if(senhaInput == cliente ->senha){  
        printf("Voce deseja confirmar a compra? (S/N): ");
        scanf(" %c", &confirmacao);  

        if(confirmacao != 'S' && confirmacao != 's') {  
            printf("Compra cancelada.\n");
            return;
        }
		switch(escolher) {  
			case 1:
				if(quantos <= cliente ->bitcoin){  
					quantos_iniciais = quantos;    
					quantos = quantos-(quantos * tax_venda_bit);    
					valor_recebido = quantos * criptos[0].cotacao;  
					cliente ->bitcoin -= quantos;   
					cliente ->reais += quantos * criptos[0].cotacao; 
				    RegistrarTransacao(historico, total, "Venda", "Bitcoin", quantos);
					printf("Venda realizada com sucesso!\n");
					printf("Quantidade vendida: %.2f Bitcoins\n", quantos_iniciais);  
					printf("Valor recebido: R$ %.2f\n", valor_recebido);   
					printf("Taxa cobrada: %.0f%%\n", tax_venda_bit * 100); 
				}else {
					printf("Quantidade desejada e insuficiente.\n"); 
				}
				break;
			case 2:
				if(quantos <= cliente ->etherium){   
					quantos_iniciais = quantos; 
					quantos = quantos-(quantos * tax_venda_ethe);  
					valor_recebido = quantos * criptos[1].cotacao; 
					cliente ->etherium -= quantos;  
					cliente ->reais += quantos * criptos[1].cotacao; 
					RegistrarTransacao(historico, total, "Venda", "Etherium", quantos);
					printf("Venda feita com sucesso!\n");
					printf("Quantidade vendida: %.2f Ethereum\n", quantos_iniciais);  
					printf("Valor recebido: R$ %.2f\n", valor_recebido); 
					printf("Taxa cobrada: %.0f%%\n", tax_venda_ethe * 100); 
				}else {
					printf("Quantidade desejada e insuficiente.\n");
				}
				break;
			case 3:
				if(quantos <= cliente ->ripple){ 
					quantos_iniciais = quantos; 
					quantos = quantos-(quantos * tax_venda_rpl);   
					valor_recebido = quantos * criptos[2].cotacao;   
					cliente ->ripple -= quantos;  
					cliente ->reais += quantos * criptos[2].cotacao;   
					RegistrarTransacao(historico, total, "Venda", "Ripple", quantos);
					printf("Venda feita com sucesso!\n");
					printf("Quantidade vendida: %.2f Ripple\n", quantos_iniciais); 
					printf("Valor recebido: R$ %.2f\n", valor_recebido); 
					printf("Taxa cobrada: %.0f%%\n", tax_venda_rpl * 100); 
				}else {
					printf("Quantidade desejada e insuficiente.\n"); 
				}
				break;
			default:
				printf("Criptomoeda invalida.\n"); 
		}
	}else {  
		printf("Senha incorreta, operação cancelada.\n");
	}
}

void atl_cot_cripto(Cripto criptos[], int qtd){
	int i;  //cria uma variavel int chamada i
	for(i = 0; i<qtd; i++){  //um laço de repetição aonde o i tem que ser igual a 0 e o i menor que a variavel int qtd  e apos isso a variavel i e incrementada, ela percorre todas as qtd de cripto e a variavel i e o indice de cada moeda começando do 0
		float variar = ((rand() % 1001) / 10000.0f)- 0.05f;  //variavel float chamada variar, no rand ele gera um numero aleatorio entre 0 e 1000 e depois divide esse numero pelo numero 10000.0f, apos isso, o valor resultante da operação anterior e subtraido pelo valor 0.05
		criptos[i].cotacao *= (1+ variar);  //assim gerando um numero -0.05 e +0.05 em outras palavras entre os valores -5% e +5%. Nessa linha o valor que esta armazenado das tres moedas na struct cotação e multiplicada pelo valor resultanto de toda conta anterior assim gerando uma nova cotação
	}
}

void mostrar_cots(Cripto criptos[], int qtd){  //acessa a struct cripto e cria uma variavel int chamada qtd
	int i;  //cria uma variavel int chamada i
	printf("Cotações:\n");
	for(i = 0; i < qtd; i++){   //laço de repetição para ler todos os valores da struct
		printf("%s: R$ %.2f\n", criptos[i].nome, criptos[i].cotacao);  //printf para mostrar todos os valores da struct
	}
}

void escreveArquivo(){

}

void leArquivo(){

}


int main(){
    Cliente1 cliente1 = {"Luanda Soliz", 34567895734, 2344568, 500.00, 20.00, 100.00, 648.25};  //adicionando informações no cliente1
    Cliente2 cliente2 = {"Lidia Mamani", 23498745690, 2356235, 300.00, 26.00, 487.00, 654.00};  //e no cliente2

    Cripto criptos[3] = {   //adicionado valores para a struct cripto das 3 moedas
		{"Bitcoin", 150000.0},  //valores pra  bitcoin
		{"Ethereum", 8000.0},  //valores para etherium
		{"Ripple", 3.0}   //valores para ripple
		};  
  
    transacao historico_transacoes1[100];  //pegando a struct transacao e adicionando uma variavei int para os total e colocando um limite para o historico
    int total_transacoes1 = 0;

    transacao historico_transacoes2[100];  //para o cliente 2
    int total_transacoes2 = 0;
  
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
