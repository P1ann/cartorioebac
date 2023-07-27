#include <stdio.h> //biblioteca de comunica��o com o usu�rio
#include <stdlib.h> //biblioteca de aloca��o de espa�o em mem�ria 
#include <locale.h> //biblioteca de aloca��es de texto por regi�o
#include <string.h> //biblioteca responsavel por cuidar das string

int registro() //fun��o responsavel por cadsatrar os usuarios no sistema
{
	//inicio criacao de varaveis/string
	char arquivo[40];
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	
	printf("digite o CPF a ser cadastrado: "); // coletando informa��o do usu�rio
	scanf("%s", cpf); // %s refere-se a string
	
	strcpy(arquivo, cpf); //responsavel por copiar os valores das string
	
	FILE *file; //cria o arquivo
	file = fopen(arquivo, "w"); // cria o arquivo, w � escrever
	fprintf(file,cpf); //salva o valor da variavel
	fclose(file); //fecha o arquivo
	
	file = fopen(arquivo, "a");
	fprintf(file,",");
	fclose(file);
	
	printf("digite o nome a ser cadastrado: ");
	scanf("%s",nome);
	
	file = fopen(arquivo,"a");
	fprintf(file,nome);
	fclose(file);
	
	file = fopen(arquivo, "a");
	fprintf(file,",");
	fclose(file);
	
	printf("digite o sobrenome a ser cadastrado: ");
	scanf("%s",sobrenome);
	
	file = fopen(arquivo, "a");
	fprintf(file,sobrenome);
	fclose(file);
	
	file = fopen(arquivo, "a");
	fprintf(file,",");
	fclose(file);
	
	printf("digite o cargo a ser cadstrado");
	scanf("%s",cargo);
	
	file = fopen(arquivo, "a");
	fprintf(file,cargo);
	fclose(file);
	
	system("pause");
	
	
	
}

int consulta()
{
	setlocale(LC_ALL, "Portuguese");
	
	char cpf[40];
	char conteudo[200];
	
	printf("digite o cpf a ser consultado: ");
	scanf("%s",cpf);
	
	FILE *file;
	file = fopen(cpf,"r");
	
	if(file == NULL)
	{
		printf("N�o foi possivel abrir o arquivo, n�o localizado!. \n");	
	}
	while(fgets(conteudo, 200, file)!= NULL)
	{
		printf("\nEssas sao as informa��es do usuario: ");
		printf("%s", conteudo);
		printf("\n\n");
		
	}
	system("pause");
}

int deletar()
{
   char cpf[40];
   
   printf("Digite o CPF do usu�rio a ser deletado: ");
   scanf("%s",cpf);
   
   remove(cpf);
   
   FILE *file;
   file = fopen(cpf,"r");
   
   if(file == NULL)
   {
   	printf("O usu�rio n�o se encontra no sistema!.\n");
   	system("pause");
   }
}
int main()
    
    {
	int opcao=0; //definindo vari�veis 
	int x=1;
	
	for(x=1;x=1;)
	{
		
		system("cls");
	
	setlocale(LC_ALL, "Portuguese");  //definindo linguagem
	
	printf("### Cart�rio da EBAC ###\n\n"); //inicio do menu
	printf("Escolha a op��o do menu:\n\n");
	printf("\t1 - registrar nomes\n");
	printf("\t2 - consultar nomes\n");
	printf("\t3 - deletar nomes\n\n");
	printf("Op��o: "); //fim do menu
	
	scanf("%d", &opcao); // armazenando a escolha do usuario
	
	system("cls"); // responsavel por limpar a tela
	
	switch(opcao)
	{
		case 1:
			    registro(); // chamada de fun��es
		        break;
		
		case 2:
		    	consulta();
		        break;
		
		case 3:
				deletar();
		        break;
		          
		
		default:
			    printf("essa opcao nao esta disponivel\n");
		        system("pause");
		        break;
			
			
			
	}
	
	
}
}
