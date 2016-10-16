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

#define MBuffer 8192
#define MEntrada 100010
#define MAX_NAME 50
#define MAX_LINHA 50


int main () {
	FILE * pFileNew;

	int i, j, k, l,
		flag,
		result,
		cntLin,
		cont_aux, 
		t_entrada;
	char aux[MAX_LINHA], s_tam[10], aux2[MAX_NAME], name_p[MAX_NAME];
	char mat[MEntrada][MAX_NAME], *buffer;

	  // start pt1 - leitura
	pFileNew = fopen ("exercicio-hash/entrada-1.txt","r");
	if (pFileNew==NULL) {
		printf("Arquivo Inválido");
		exit(0);
	}	

		//"descobre" tam da entrada
	fgets(s_tam, 100, pFileNew);
	t_entrada = atoi(s_tam);


		//Aloca memória para buffer de entrada
	buffer = (char*) malloc (sizeof(char) * MBuffer + 1);
	if (buffer == NULL){
		fputs("Memory Error", stderr);
		exit(2);
	}

	for(i=0; i<MEntrada; i++)
		for(j=0; j<MAX_NAME; j++){
			mat[i][j] = '\0';
		}

	for(i=0; i<MAX_NAME; i++)
		name_p[i] = '\0';
	i = 0;
	cntLin = 0;
	cont_aux = 0;
	printf("tam-entrada: %i\n", t_entrada);
	while ((result = fread (buffer, sizeof(char), MBuffer, pFileNew))!=EOF){
		buffer[result] = '\0';
		if (!result) {
			printf("\n\tAcabou a leitura do arquivo\n");
			break;
		}
		
		//entrada de dados
		for(i = 0; i < result; i++){
			if(cont_aux < t_entrada){
			    if(buffer[i] != '\r') {
		            if (buffer[i] == '\n'){
		            	for(j=0; aux[j] != ' '; j++){
		            		aux2[j] = aux[j];
		            	}
		            	k = atoi(aux2); //ql o numero de id
		            	j++;
		            	for(l=0; (l+j) < cntLin; l++){ //acrescenta no mat[id][] o nome e sobrenome
		            		mat[k][l] = aux[l+j];
		            	}
		            	cntLin = 0;
		            	cont_aux++;
		            	strcpy(aux, "");
	                }else{
	                 	aux[cntLin] = buffer[i];
	                 	cntLin++;
			        }
			    }
			}else{
				//printf("cont_aux %i\n", cont_aux);
				if(buffer[i] != '\r') {
		            if (buffer[i] == '\n'){
		            	if(cont_aux != t_entrada){
		            		printf("-%s-\n", name_p);
		            		strncpy(name_p, aux, cntLin);
		            		printf("%s\n", name_p);
		            		/*
			            	for(j=0; j<t_entrada; j++){
								if(strcmp(mat[j], name_p) == 0){
									printf("%i mat: %s aux: %s\n", i, mat[i], aux);
									break;
								}
							}
							*/
		            	}else{
		            		//1 elemento
		            	}
		            	cntLin = 0;
		            	cont_aux++;
		            	strcpy(aux, "");

	                }else{
	                 	aux[cntLin] = buffer[i];
	                 	cntLin++;
			        }
			    }
			}
		}

			//consulta
	}
	/*
	for(i=0; i<t_entrada; i++){
		printf("%i\t", i);
		for(j=0; mat[i][j]!='\0'; j++){
			printf("%c",mat[i][j]);
		}
		printf("\n");
	}
	*/
	fclose(pFileNew);
	pFileNew = NULL;
	return 0;
} 