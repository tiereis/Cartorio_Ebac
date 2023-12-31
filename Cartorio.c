#include <stdio.h> //biblioteca de comunica��o com o usu�rio
#include <stdlib.h> //biblioteca de aloca��o de espa�o em mem�ria
#include <locale.h> //biblioteca de aloca��o de texto por regi�o
#include <string.h> //biblioteca respons�vel por cuidar das strings

int registrar(){
	
	char arquivo[40];
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	int laco = 1;
	int opcao;
	
	while(laco==1){
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
		fprintf(file, " "); //adiciona um espa�o entre o nome e sobre nome no arquivo criado
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
		
		printf("\n\nDeseja incluir mais nome?\nDigite (1) para SIM (2) para N�O.\n");
		scanf("%d", &opcao);
		
		if(opcao == 2){
			laco = 0;	
		}
		if(opcao == 1){
			laco = 1;
		}
		else{
			printf("Op��o inv�lida!\n\n");
			laco =0;
		}
	}
	
	system("pause");
}

int consultar(){
	
	setlocale(LC_ALL, "Portuguese");
	
	
	char cpf[40];
	char conteudo[200];
	
	printf("Digite o CPF a ser consultado: ");//inicia a consulta pelo cpf
	scanf("%s", cpf);
	
	FILE *file;
	file = fopen(cpf, "r");
	
	if(file == NULL)//se nao encontrado retorna ao usuaria essa informa��o
	{
		printf("N�o foi poss�vel abrir o arquivo, n�o localizado!\n");
	}
	
	while(fgets(conteudo, 200, file) != NULL)//caso presente retorna ao usuario as suas onforma��es
	{
		printf("\nEsses s�o as informa��es do us�ario: ");
		printf("%s", conteudo);
		printf("\n\n");
	}
	
	system("pause");
}

int deletar(){
	
	char cpf[40];
	char conteudo[200];
	char confirmaDel;
	
	printf("Digite o CPF a ser deletado: \n");//consulta o cpf a ser deletado
	scanf("%s", cpf);
	
	
	FILE *file;
	file = fopen(cpf, "r");
	
	if(file == NULL){
		printf("O usuario n�o se encontra no sistema.\n\n");//caso nao exista no sistema, retorna uma mensagem ao usuario
		system("pause");
	}
	fclose(file);
	
	remove(cpf);
	
	printf("O usuario foi deletado do sistema.\n\n");//caso exista no sistema, retorna ao usuaria uma mensagem confirmando a exclus�o do usuario
		system("pause");
	
}

int main(){
	
	int opcao = 0; //Definindo variaveis
	int laco=1;
	char senhadigitada[]="a";
	int comparacao;
	
	printf("### Cart�rio da EBAC ###\n\n");
	printf("Login de administrador\n\nDigite a sua senha: ");
	scanf("%s", senhadigitada);
	
	comparacao = strcmp(senhadigitada, "admin"); //compara��o das senha recebidads para validar acesso
	
	if(comparacao == 0){
		
		system("cls");
		for(laco=1;laco=1;)
		{
			setlocale(LC_ALL, "Portuguese"); //Definindo linguagem
			
			system("cls");
			
			printf("### Cart�rio da EBAC ###\n\n"); //Inicio do Menu
			printf("Escolha a op��o desejada do menu:\n\n");
			printf("\t1 - Registrar os nomes\n");
			printf("\t2 - Consultar os nomes\n");
			printf("\t3 - Deletar os nomes\n");
			printf("\t4 - Sair do sistema\n\n");
			printf("Op��o: "); //Fim do Menu
		
			scanf("%d", &opcao); //armazenando a escolha do usuario
		
			system("cls"); //limpa tela
		
			switch(opcao)
			{//Inicio da sele��o
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
				printf("Essa opcao n�o esta disponivel!\n");
				system("pause");
				break;
			}//Fim da sele��o
		}
	}
	else{
		printf("Senha incorreta!");
	}
}

