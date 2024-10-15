#include <stdio.h> //biblioteca de comunica��o do usu�rio
#include <stdlib.h> //biblioteca de aloca��o de espa�o em mem�ria
#include <locale.h> //biblioteca de aloca��o de texto por regi�o
#include <string.h> // biblioteca respons�vel por cuiodar das strings

int registro() //fun��o respons�vel por cadastrar os usu�rios no sistema
{
	//in�cio de cria��o de vari�veis/strings
	char arquivo[40];
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	//final de cria��o de vari�veis/strings
	
	printf("Digite o CPF a Ser Cadastrado: "); //coletando informa��es do usu�rio
	scanf("%s", cpf); //%s refere-se a string
	
	strcpy(arquivo,cpf); // Respons�vel por copiar os valores das strings
	
	FILE *file; //cria o arquivo
	file = fopen(arquivo, "w"); //cria o arquivo e o "w" refere-se a escrever (write)
	fprintf(file,cpf); //salva o valor da vari�vel
	fclose(file); //fecha o arquivo
	
	file = fopen(arquivo, "a");
	fprintf(file, ", ");
	fclose(file);
	
	printf("Digite o Nome a Ser Cadastrado: ");
	scanf("%s", nome);
	
	file = fopen(arquivo, "a");
	fprintf(file,nome);
	fclose(file);
	
	file = fopen(arquivo, "a");
	fprintf(file, ", ");
	fclose(file);
	
	printf("Digite o Sobrenome a Ser Cadastrado: ");
	scanf("%s", sobrenome);
	
	file = fopen(arquivo, "a");
	fprintf(file, sobrenome);
	fclose(file);
	
	file = fopen(arquivo, "a");
	fprintf(file, ", ");
	fclose(file);
	
	printf("Digite o Cargo a Ser Cadastrado: ");
	scanf("%s", cargo);
	
	file = fopen(arquivo, "a");
	fprintf(file,cargo);
	fclose(file);
	
	system("pause");	
		
}

int consulta()
{
	setlocale(LC_ALL, "Portuguese"); //definindo a linguagem
	
	char cpf[40];
	char conteudo[200];
	
	printf("Digite o CPF a Ser Consultado: ");
	scanf("%s",cpf);
	
	FILE *file;
	file = fopen(cpf,"r");
	if(file == NULL)
	{
		printf("O CPF N�o Foi Localizado!\n");
	}
	
	while(fgets(conteudo, 200, file) != NULL)
	{
		printf("\nEssas S�o as Informa��es do Usu�rio: ");
		printf("%s", conteudo);
		printf("\n\n");
	}
	
	system("pause");
		
}

int deletar()
{
	char cpf[40];
	
	printf("Digite o CPF do Usu�rio a Ser Deletado: ");
	scanf("%s",cpf);
	
	FILE *file;
	file = fopen(cpf, "r");
	
	if(file == NULL)
	{
		printf("O Usu�rio N�o Se Encontra No Sistema!\n");
		system("pause");
	}
	
	else if (file != NULL)
	{
		fclose(file);
		printf("O Arquivo Foi Deletado!\n");
		system("pause");
		remove(cpf);
	}
}

int main()
	{
	int opcao=0; //definindo as vari�veis
	int laco=1; 
	
	for(laco=1;laco=1;)
	{
	
		system("cls"); 
	
		setlocale(LC_ALL, "Portuguese"); //definindo a linguagem
	
		printf("### Cart�rio Rafael ###\n\n"); //in�cio do menu do menu
		printf("Escolha a op��o desejada do Menu:\n\n");
		printf("\t1 - Registrar Nomes\n");
		printf("\t2 - Consultar Nomes\n");
		printf("\t3 - Deletar Nomes\n\n");
		printf("\t4 - Sair do Sistema\n\n");
		printf("Op��o: "); //fim do menu
	
		scanf("%d", &opcao); //armazenando informa��es da escolha do usu�rio
	
		system("cls"); //respons�vel por limpar a tela
		
		
		switch(opcao) //in�cio da sele��o do menu
		{
			case 1:
			registro(); //chamada de fun��es 
			break;
			
			case 2:
			consulta();
			break;
			
			case 3:
			deletar();
			break;
			
			case 4:
			printf("Obrigado por utilizar o sistema\n");
			return 0;
			break;
			
			default:  	
			printf("Essa op��o n�o existe\n");
			system("pause");
			break;	
		}
		
	
	}
}
