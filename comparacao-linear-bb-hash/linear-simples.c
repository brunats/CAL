/*
Comparação entre o uso de busca linear, busca binária e Hash

Escreva um programa que leia um número inteiro n e em seguida leia n pares p s, 
onde s indica um numero de um personagem ficticio (nome e sobrenome) e p indica um 
número de ordem associado a esse personagem. Depois, leia um número inteiro m e 
mais m nomes (nome e sobrenome). Para cada um desses nomes, mostre o número de 
ordem associado ao personagem.

Escreva três versões para este programa e as compare:
	==> a) Use um vetor ou lista e realize buscas lineares; <==
	b) Use um vetor ou árvore e realize buscas binárias;
	c) Use um hash encadeado com lista ou árvores;
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <time.h>

#define MBuffer 8192
#define MEntrada 100010
#define MAX_NAME 50
#define MAX_LINHA 50

int pesquisa(char mat[][MAX_NAME], char *name, int max){
	int i;
	for(i=0; i<max; i++){
		if(strcmp(mat[i], name) == 0)
			return i;
	}
	return -1;
}

int main (int argc, char *argv[]){

	int i, j, n, x,
		t_entrada,
		t_procurados;
	char nome[MAX_NAME], sobrenome[MAX_NAME], nome_c[MAX_NAME], mat[MEntrada][MAX_NAME];
	FILE * pFileNew;
	float aux;
    clock_t ti, tf;


	if(argc != 2){
		printf("Arquivo Inválido\n");
		exit(0);
	}

	pFileNew = fopen (argv[1],"w");
	if (pFileNew==NULL) {
		printf("Arquivo Inválido");
		exit(0);
	}	
	scanf("%i", &t_entrada);
	//limpa a matriz
	for(i=0; i<MEntrada; i++)
		for(j=0; j<MAX_NAME; j++)
			mat[i][j] = '\0';

	//entrada de dados
	for(i=0; i<t_entrada; i++){
		scanf("%i %s %s", &x, nome, sobrenome);

		strcat(nome_c, nome);
		strcat(nome_c, " ");
		strcat(nome_c, sobrenome);

		strcpy(mat[x], nome_c);
		
		printf("%s\n", mat[x]);
		strcpy(nome_c, "");
	}
	scanf("%i", &t_procurados);

	//casos de testes
	i=0;
	ti = clock();
		printf("\tt_inicial: %f\n", (float)ti/CLOCKS_PER_SEC);
	while(i<t_procurados){
		scanf("%s %s",nome, sobrenome);
		strcat(nome, " ");
		strcat(nome, sobrenome);
		
		n = pesquisa(mat, nome, t_entrada); 
		
		if(n != -1)
			fprintf(pFileNew, "%i\n", n);
		
		strcpy(nome, "");
		i++;
	}
	tf = clock();
	printf("\t\tt_final: %f", (float)tf/CLOCKS_PER_SEC);
	printf ("\t%f tempo\n", ((float)(tf-ti))/CLOCKS_PER_SEC);

	fclose(pFileNew);
	pFileNew = NULL;
	return 0;
} 