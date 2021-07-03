#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<locale.h>

typedef struct Funcionario{
	int id;
	char nome[20];
	double sal;
	int anoNascimento;
	int idade;
}Funcionario;

void pesquisarArquivoRecord(FILE *arq, char *nome){
	Funcionario info;
	char name[20];
	
	arq = fopen(nome, "rb");
	
	if(arq == NULL){
		printf("ERRO NA ABERTURA DO ARQUIVO!");
	}else{
		printf("\n---- PESQUISA DE FUNCIONÁRIO ----\n\n");
		printf("\nDIGITE O NOME:	");
		fflush(stdin);
		scanf("%[^\n]", &name);
		int Encontrado = 0;
		while(fread(&info, sizeof(struct Funcionario), 1, arq) == 1){
			if(strstr(info.nome, name) != NULL){
      			printf("\n---- FUNCIONÁRIO ENCONTRADO ----\n\n");
            	printf("ID:			%d\n", info.id);
		   		printf("NOME:			%s\n", info.nome);
           		printf("SALÁRIO:		R$ %.2f\n", info.sal);
           		printf("ANO NASCIMENTO:		%d\n", info.anoNascimento); 
           		printf("IDADE:			%d\n", info.idade); 
      			Encontrado = 1;
			}
        }
        if(Encontrado == 0){
        	printf("\nNÃO ENCONTRADO!\n");
		}
	}
	fclose(arq);
}
void escreverArquivoRecord(FILE *arq, char *nome){
	Funcionario info;

	arq = fopen(nome, "ab");
	if(arq == NULL){
		printf("ERRO NA ABERTURA DO ARQUIVO!");
	}else{
		printf("\n---- CADASTRO DE FUNCIONÁRIOS ----\n\n");
		printf("\nDIGITE O ID:		");
		scanf("%d", &info.id);
		printf("\nDIGITE O NOME:		");
		fflush(stdin);
		scanf("%[^\n]", &info.nome);
		printf("\nDIGITE O SALÁRIO:	R$ ");
		scanf("%lf", &info.sal);
		printf("\nDIGITE O ANO DE NASCIMENTO:	");
		scanf("%d", &info.anoNascimento);
		info.idade = 2021 - info.anoNascimento;
		if(fwrite(&info, sizeof(struct Funcionario), 1, arq) != 1){
			printf("\nERRO DE ESCRITA NO ARQUIVO.\n");
		}
	}
	fclose(arq);
}
void lerArquivoRecord(FILE *arq, char *nome){
	Funcionario info;
	arq = fopen(nome, "rb");
	
	if(arq == NULL){
		printf("ERRO NA ABERTURA DO ARQUIVO!");
	}else{
		printf("\n---- LISTAGEM DE FUNCIONÁRIOS ----\n\n");
		while(fread(&info, sizeof(struct Funcionario), 1, arq) == 1){
		   printf("ID:			%d\n", info.id);
		   printf("NOME:			%s\n", info.nome);
           printf("SALÁRIO:		R$ %.2f\n", info.sal);
           printf("ANO NASCIMENTO:		%d\n", info.anoNascimento); 
           printf("IDADE:			%d\n", info.idade); 
           printf("\n");
        }
	}
	fclose(arq);
}
void criarArquivoRecord(FILE *arq, char *nome){
	arq = fopen(nome, "wb");
	
	fclose(arq);	
}
void arquivoPorRecord(){
	char nomeArq[50];
	FILE *novo;
	int opc = 0;
	
	printf("\nDIGITE O NOME DO ARQUIVO .BIN:		");
	scanf("%s", &nomeArq);
	
	printf("\nCRIANDO  O ARQUIVO....\n");
	criarArquivoRecord(novo, nomeArq);
	system("pause");
	system("cls");
	while(opc != 4){
		printf("\nESCOLHA UMA DAS OPÇÕES:\n\n1- ESCREVER;\n2- LER ARQUIVO;\n3- PESQUISAR.\n4- SAIR.\n");
		scanf("%d", &opc);
		switch(opc){
			case 1:
				escreverArquivoRecord(novo, nomeArq);
				system("pause");
				system("cls");
				break;
			case 2:
				lerArquivoRecord(novo, nomeArq);
				system("pause");
				system("cls");
				break;
			case 3:
				pesquisarArquivoRecord(novo, nomeArq);
				system("pause");
				system("cls");
				break;
			case 4:
				system("exit");
				break;
			default:
				printf("\nDIGITE UMA OPÇÃO VÁLIDA.\n");
				break;
		}
	}	
}

void pesquisarArquivoTexto(FILE *arq, char *nome){ 
	 char string[100], texto[100];
	 
	 arq = fopen(nome, "r");
	 
	 if(arq == NULL){
		printf("ERRO NA ABERTURA DO ARQUIVO!");
	 }else{
		printf("\n---- PESQUISA DE TEXTO ----\n\n");
		printf("\nDIGITE O TEXTO:	");
		fflush(stdin);
		scanf("%[^\n]", &string);
		int i = 1, Encontrado = 0;
		while(!feof(arq)){
      		char *res = fgets(texto, 100, arq);  
      		if(res){
      			if(strstr(texto, string) != NULL){
      				printf("\nLINHA %d : %s", i, texto);
      				Encontrado = 1;
				}
			}	
			i++;
  		}
  		if(Encontrado == 0){
  			printf("\nTEXTO NÃO ENCONTRADO!\n");
		}
	}	
	fclose(arq);
}
void escreverArquivoTexto(FILE *arq, char *nome){
	char string[100];
	int i = 0;
	
	arq = fopen(nome, "a");
	
	if(arq == NULL){
		printf("ERRO NA ABERTURA DO ARQUIVO!");
	}else{
		char c;
		printf("\nDIGITE O TEXTO QUE DESEJA INSERIR NO ARQUIVO:	");
		fflush(stdin);
		scanf("%[^\n]", &string);
		fputs(string, arq);
		fputs("\n", arq);
	}
	fclose(arq);
}
void lerArquivoTexto(FILE *arq, char *nome){
	char string[100], *res;
	arq = fopen(nome, "r");
	
	if(arq == NULL){
		printf("ERRO NA ABERTURA DO ARQUIVO!");
	}else{
		printf("\n---- LEITURA DO ARQUIVO ----\n\n");
		int i = 1;
  		while(!feof(arq)){
      		res = fgets(string, 100, arq);  
      		if(res)
	  			printf("LINHA %d : %s", i, string);
      		i++;
  		}
	}
	fclose(arq);
}
void criarArquivoTexto(FILE *arq, char *nome){
	arq = fopen(nome, "w");
	
	fclose(arq);
}
void arquivoPorTexto(){
	char nomeArq[50];
	FILE *novo;
	int opc = 0;
	
	printf("\nDIGITE O NOME DO ARQUIVO .TXT:		");
	scanf("%s", &nomeArq);
	
	printf("\nCRIANDO  O ARQUIVO....\n");
	criarArquivoTexto(novo, nomeArq);
	system("pause");
	system("cls");
	while(opc != 4){
		printf("\nESCOLHA UMA DAS OPÇÕES:\n\n1- ESCREVER;\n2- LER ARQUIVO;\n3- PESQUISAR.\n4- SAIR.\n");
		scanf("%d", &opc);
		switch(opc){
			case 1:
				escreverArquivoTexto(novo, nomeArq);
				system("pause");
				system("cls");
				break;
			case 2:
				lerArquivoTexto(novo, nomeArq);
				system("pause");
				system("cls");
				break;
			case 3:
				pesquisarArquivoTexto(novo, nomeArq);
				system("pause");
				system("cls");
				break;
			case 4:
				system("exit");
				break;
			default:
				printf("\nDIGITE UMA OPÇÃO VÁLIDA.\n");
				break;
		}
	}
}

void main(){
	setlocale(LC_ALL, "Portuguese");
	int opc = 0;
	
	while(opc != 3){
		printf("ESCOLHA UMA DAS OPÇÕES ABAIXO:\n\n1- TEXTO;\n2- RECORD;\n3- SAIR.\n");
		scanf("%d", &opc);
		switch(opc){
			case 1:
				arquivoPorTexto();
				system("pause");
				system("cls");
				break;
			case 2:
				arquivoPorRecord();
				system("pause");
				system("cls");
				break;
			case 3:
				system("exit");
				break;
			default:
				printf("\nDIGITE UMA OPÇÃO VÁLIDA.");
				system("pause");
				system("cls");
				break;
		}
	}
}
