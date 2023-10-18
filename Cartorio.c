
#include <stdio.h> //biblioteca de comunicação com o usuário
#include <stdlib.h> //biblioteca de alocação de espaço em memória
#include <locale.h> //biblioteca de alocação de texto por região
#include <string.h> //biblioteca responsável por cuidar das strings

int registrar(){
	
	char arquivo[40];
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];	
	
	printf("Digite o CPF a ser cadastrado ");
	scanf("%s", cpf);
	
	strcpy(arquivo, cpf); // copia os valores das strings
	
	FILE *file; //cria o arquivo no banco de dados
	file = fopen(arquivo, "w"); // cria o arquivo
	fprintf(file, cpf); // salvar o valor da variavel. Seria um printf e scanf combinados?
	fclose(file); // fechar o arquivo
	
	file = fopen(arquivo, "a"); //atualiza o arquivo
	fprintf(file, ", "); //inseri uma virgula entre as variaveis armazenadas
	fclose(file);
	
	printf("Digite o nome a ser cadastrado: ");
	scanf("%s", nome);
	
	file = fopen(arquivo, "a");
	fprintf(file, nome);
	fclose(file);
	
	file = fopen(arquivo, "a"); 
	fprintf(file, " "); //adiciona um espaço entre o nome e sobre nome no arquivo criado
	fclose(file);
	
	printf("Digite o sobrenome a ser cadastrado: ");
	scanf("%s", sobrenome);
	
	file = fopen(arquivo, "a");
	fprintf(file, sobrenome);
	fclose(file);
	
	file = fopen(arquivo, "a");
	fprintf(file, ", "); 
	fclose(file);
	
	printf("Digite o cargo a ser cadastrado: ");
	scanf("%s", cargo);
	
	file = fopen(arquivo, "a");
	fprintf(file, cargo);
	fclose(file);
	
	system("pause");
}

int consultar(){
	
	setlocale(LC_ALL, "Portuguese");
	
	
	char cpf[40];
	char conteudo[200];
	
	printf("Digite o CPF a ser consultado: ");
	scanf("%s", cpf);
	
	FILE *file;
	file = fopen(cpf, "r");
	
	if(file == NULL)
	{
		printf("Não foi possível abrir o arquivo, não localizado!\n");
	}
	
	while(fgets(conteudo, 200, file) != NULL)
	{
		printf("\nEsses são as informações do usúario: ");
		printf("%s", conteudo);
		printf("\n\n");
	}
	
	system("pause");
}

int deletar(){
	
	char cpf[40];
	char conteudo[200];
	char confirmaDel;
	
	printf("Digite o CPF a ser deletado: "); //Abaixo tentei implementar alem do pedido uma confimação antes de deletar, so que o arquivo não é deletado. Não sei se é algum erro de syntax
	scanf("%s", cpf);
	
	remove(cpf); //função que deleta o arquivo
	
	FILE *file;
	file = fopen(cpf, "r");
	
	if(file == NULL){
		printf("O usuario não se encontra no sistema.\n");
		system("pause");
	}
	
	//remove(cpf); //função que deleta o arquivo
	//printf("Usúario deletado com sucesso!\n");
	//system("pause");
	
	//else{
	//	while(fgets(conteudo, 200, file) != NULL){
	//		printf("\nEsses são as informações do usúario: ");
	//		printf("%s", conteudo);
	//		printf("\n\n");
	//	}
	//	
	//	printf("Deseja deletar esse usúario? (Y) ou (N) \n");
	//	scanf("%s", confirmaDel);		
	//	
	//	if(confirmaDel == 'y' || confirmaDel == 'Y'){
	//		remove(cpf); //função que deleta o arquivo
	//		printf("Usúario deletado com sucesso!\n");
	//		system("pause");
	//	}
//	}
}

int main(){
	
	int opcao = 0; //Definindo variaveis
	int laco=1;
	
	for(laco=1;laco=1;)
	{
		
		system("cls");
	
		setlocale(LC_ALL, "Portuguese"); //Definindo linguagem
		
		printf("### Cartório da EBAC ###\n\n"); //Inicio do Menu
		printf("Escolha a opção desejada do menu:\n\n");
		printf("\t1 - Registrar os nomes\n");
		printf("\t2 - Consultar os nomes\n");
		printf("\t3 - Deletar os nomes\n"); 
		printf("\t4 - Sair do sistema\n\n");
		printf("Opção: "); //Fim do Menu
	
		scanf("%d", &opcao); //armazenando a escolha do usuario
	
		system("cls"); //limpa tela
	
		switch(opcao)
		{//Inicio da seleção
			case 1:
			registrar();
			break;
			
			case 2:
			consultar();
			break;
			
			case 3:
			deletar();
			break;
			
			case 4:
			printf("Obrigado por utilizar o sistema");
			return 0;
			break;
			
			default:
			printf("Essa opcao não esta disponivel!\n");
			system("pause");
			break;
		}//Fim da seleção
	}
}

