#include <stdio.h> // biblioteca de comunicação com o usuário
#include <stdlib.h> // biblioteca de realocção de espaço de memória
#include <locale.h>  // biblioteca de texto local
#include <string.h> //biblioteca de responsável da string

int registro()
{
	char arquivo[40];
    char cpf[40];
    char nome[40];
    char sobrenome [40];
    char cargo[40];
    
    printf("Digite o seu CPF para seu cadastrado:");
    scanf("%s",cpf);
    
    strcpy(arquivo, cpf); // copias os valores da string cpf para o arquivo
    
    FILE *file; //cria o arquivo
    file = fopen(arquivo,"w");
    fprintf(file,cpf); // copia o dado cpf para o arquivo
    fclose(file); //fecha o arquivo
    
    file = fopen(arquivo, "a"); //abre o arquivo (a [e de atualização)
    fprintf(file,","); //diciona uma vírgula entre os dados
    fclose(file);
    
    
    
    printf("Digite seu nome:");
    scanf("%s", nome);
    
    file = fopen(arquivo, "a"); //adiciona o nome ao arquivo
	fprintf(file,nome);
	fclose(file);
	
	file = fopen(arquivo, "a"); //diciona uma vírgula entre os dados
	fprintf(file, ",");
	fclose(file);
	
	printf("Digite o seu sobrenome:");
	scanf("%s", sobrenome);
	
	file = fopen(arquivo,"a");
	fprintf(file, sobrenome);
	fclose(file);
	
	file = fopen(arquivo,"a");
	fprintf(file, ",");
	fclose(file);
	
	printf("Digite o seu cargo:");
	scanf("%s", cargo);
	
	file = fopen(arquivo,"a");
	fprintf(file,cargo);
	fclose(file);
	
	system("pause");

    
}

int consultar()
{  

   setlocale(LC_ALL, "Portuguese"); // define a linguegem
 
   char cpf[40];
   char conteudo [200];
   char *token;
   
   printf("digite o CPF que vai ser colsultado: \n");
   scanf("%s", cpf); // armazena a varialvel cpf utilizando a função string (%s)
   
   FILE *file;
   file = fopen(cpf,"r"); //abre o arquivo cpf e le a informação
   
   if(file == NULL) //se não exitir informação, responde como:
   
   {
   	 printf("Usuário não cadastrado"); 
   }
   
   while(fgets(conteudo,200,file) != NULL) //enquanto tiver informaçoes , armazebe a informação se diferete de null
   {
   	  printf("Essas são as informações: \n");
   	 
   	  token = strtok(conteudo, ","); // variavek utilizadoa para dividir a string em linha
   	  printf("CPF: %s\n",token); // infromações que aprecem antes do dado nome
   	  
   	  token = strtok(NULL, ",");
   	  printf("Nome: %s\n", token);
   	  
   	  token = strtok (NULL, ",");
   	  printf("Sobrenome: %s\n", token);
   	  
   	  token = strtok  (NULL, ",");
   	  printf("Cargo: %s\n", token);	 
   }
   
    printf("\n");
    
   system("pause");
}


int deletar()
{
    char cpf[40]; //variável CPF
    
    printf("Digite o CPF a ser deletado: \n"); //
    scanf("%s", cpf); // scaneia o CPF a se deletado

        
    FILE *file;
    file = fopen(cpf, "r"); // abre o arquivo e o le
    fclose(file);
    
   
    
    if (file == NULL) // cria uma condição se o arquivo não exitir
	 {
	  printf("Usuário não encontrado, digite outro CFP\n");
	  system("pause");	
	 } 
	 else 
	{
		remove(cpf); // remove o arquico cpf scaneado
		printf("Usuario foi %s deletado com sucesso!\n", cpf);
		system("pause");
	}
	
	
}



int main()
{
	int opcao=0; // definindo a varável
    int laco=1;
	
	for (laco=1;laco=1;) // laço de repetição
	
	{
	
	 system("cls");
	
	setlocale(LC_ALL, "Portuguese"); // consultar qual a ligungem usada

	printf("\t~~~~ Cadastro de Alunos da EBAC ~~~~\n\n"); //inicio do menu
	printf("Escolha uma opção de menu: \n\n");
	printf("\t1 - Resgitre seu nome \n  ");
	printf("\t2 - Consultar Usuário \n");
	printf("\t3 - Apagar Usuário \n ");
	printf("\t4 - Sair do Sistema\n\n");
	
	printf("Digite sua opção e a confirme:"); //final do menu
	
	scanf("%d", &opcao); //escaneia o que o usuário colocou como opção (aramazena esse dado)
	
	system("cls");
   
	switch(opcao) 
	{
		case 1:
		registro();
	    break;
	    
	    case 2:
		consultar();
	    break;
		
		case 3:
		deletar();
	    break;
	    
	    case 4:
	    printf("Obrigado por utilizar o sistema!\n");
	    return 0;
	    break;
	        
		default:
		printf("Essa opção não existe\n"); 
	    system("pause"); // final da celeção
	    break;						
	 }
	
	
   }
}

