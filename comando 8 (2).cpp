#include <stdio.h> //biblioteca de comunicação com o usuário
#include <stdlib.h> //biblioteca de alocação de espaço em memória 
#include <locale.h> //biblioteca de alocações de texto por região
#include <string.h> //biblioteca responsavel por cuidar das string

int registro() //função responsavel por cadsatrar os usuarios no sistema
{
	//inicio criacao de varaveis/string
	char arquivo[40];
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	
	printf("digite o CPF a ser cadastrado: "); // coletando informação do usuário
	scanf("%s", cpf); // %s refere-se a string
	
	strcpy(arquivo, cpf); //responsavel por copiar os valores das string
	
	FILE *file; //cria o arquivo
	file = fopen(arquivo, "w"); // cria o arquivo, w é escrever
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
		printf("Não foi possivel abrir o arquivo, não localizado!. \n");	
	}
	while(fgets(conteudo, 200, file)!= NULL)
	{
		printf("\nEssas sao as informações do usuario: ");
		printf("%s", conteudo);
		printf("\n\n");
		
	}
	system("pause");
}

int deletar()
{
   char cpf[40];
   
   printf("Digite o CPF do usuário a ser deletado: ");
   scanf("%s",cpf);
   
   remove(cpf);
   
   FILE *file;
   file = fopen(cpf,"r");
   
   if(file == NULL)
   {
   	printf("O usuário não se encontra no sistema!.\n");
   	system("pause");
   }
}
int main()
    
    {
	int opcao=0; //definindo variáveis 
	int x=1;
	
	for(x=1;x=1;)
	{
		
		system("cls");
	
	setlocale(LC_ALL, "Portuguese");  //definindo linguagem
	
	printf("### Cartório da EBAC ###\n\n"); //inicio do menu
	printf("Escolha a opção do menu:\n\n");
	printf("\t1 - registrar nomes\n");
	printf("\t2 - consultar nomes\n");
	printf("\t3 - deletar nomes\n");
	printf("\t4 - Sair do sistema\n\n");
	printf("Opção: "); //fim do menu
	
	scanf("%d", &opcao); // armazenando a escolha do usuario
	
	system("cls"); // responsavel por limpar a tela
	
	switch(opcao)
	{
		case 1:
			    registro(); // chamada de funções
		        break;
		
		case 2:
		    	consulta();
		        break;
		
		case 3:
				deletar();
		        break;
		        
		case 4:
		        printf("Obrigado por utilizar o sistema!\n");
				return 0;
				break;        
		          
		
		default:
			    printf("essa opcao nao esta disponivel\n");
		        system("pause");
		        break;
			
			
			
	}
	
	
}
}
