#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <time.h>

#define MBuffer 8192
#define MEntrada 100010
#define MAX_NAME 50
#define MAX_LINHA 50

/*
strcmp(maior,menor) == 1           strcmp(“bb”,”aa”) == 1
strcmp(menor,maior) == -1          strcmp(“aa”,”bb”) == -1
strcmp(grande,grande) == 0         strcmp(“bb”,”bb”) == 0
strcmp(pequeno,pequeno) == 0     
*/
int pesquisa(char **mat, char *name, int max){
	int i;
	for(i=0; i<max; i++){
		if(strcmp(mat[i], name) == 0)
			return i;
	}
	return -1;
}

int pesquisaBinariaSimples(char **mat, char *name, int min, int max){
	int x, met;
	printf("1\n");
    if(strcmp(mat[min], name) == 1) //menor que o menor elemento
    	return -1;
    printf("2\n");
    if(strcmp(mat[max], name) == -1) //maior que o maior elemento
    	return -1;

    printf("3\n");
    while(min <= max){
    	met = (max - min) / 2;
		x = strcmp(mat[met], name);
		if(x == 0)
			return met;
		if(x == 1)
			max = met - 1;
		if(x == -1)
			min = met + 1;

    }
    printf("4\n");
    return -1;
} 

int pesquisaBinaria(char **mat, char *name, int min, int max){
	int x, met;
	met = (max - min) / 2;
	x = strcmp(mat[met], name);
	if(min == max){      //só existe um elemento na pesquisa
    	if(x == 0) //acertou
    	    return met;
    	else
    	    return -1; //nao encontrado
    }else{
        if(x == 1)
	        return pesquisaBinaria(mat, name, min, (met-1)); //esta no lado direito
	    if(x==-1)
            return pesquisaBinaria(mat, name, (met+1), max); // esta no lado esquerto
    }
    return -1;
}

void ordena(char **mat, int max){
	int i, j, x;
	char aux[MAX_NAME];

	for(i=0; i<max; i++){
		for(j=(i+1); j<max; j++){
			x = strcmp(mat[i],mat[j]); 
			if(x == 1){ //strcmp(maior, menor)
				strcpy(aux, mat[j]);
				strcpy(mat[j], mat[i]);
				strcpy(mat[i], aux);
			}
		}
	}
}

int main (int argc, char *argv[]){

	int i, j, n, x,
		t_entrada,
		t_procurados;
	char nome[MAX_NAME], sobrenome[MAX_NAME], nome_c[MAX_NAME];
	char **matT;
	FILE * pFileNew;
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

	//aloca matriz
	matT = malloc (t_entrada * sizeof (char *));
	if(matT == NULL){
		printf("Erro na alocacao\n");
		exit(0);
	}
	for (i = 0; i < t_entrada; ++i){
    	matT[i] = malloc (MAX_NAME * sizeof (char));
    	if(matT[i] == NULL){
			printf("Erro na alocacao\n");
			exit(0);
		}
	}

	//limpa a matriz
	for(i=0; i<t_entrada; i++)
		for(j=0; j<MAX_NAME; j++)
			matT[i][j] = '\0';

	//entrada de dados
	for(i=0; i<t_entrada; i++){
		scanf("%i %s %s", &x, nome, sobrenome);

		strcat(nome_c, nome);
		strcat(nome_c, " ");
		strcat(nome_c, sobrenome);

		strcpy(matT[x], nome_c);
		
		printf("%s\n", matT[x]);
		strcpy(nome_c, "");
	}
	//m de busca
	scanf("%i", &t_procurados);

	//ordena matT
	ordena(matT, t_entrada);

	//casos de testes
	i=0;
	ti = clock();
		printf("\tt_inicial: %f\n", (float)ti/CLOCKS_PER_SEC);
	while(i<t_procurados){
		printf("ola\n");
		scanf("%s %s",nome, sobrenome);
		strcat(nome, " ");
		strcat(nome, sobrenome);
		
		printf("eu heim\n");
		n = pesquisaBinariaSimples(matT, nome, 0, t_entrada); 
		
		printf("bla 1\n");
		if(n != -1){
			printf("%s %i\n",nome, n);
			fprintf(pFileNew, "%i\n", n);
		}else{
			printf("%s\n", nome);
			fprintf(pFileNew, "-\n");
		}
		printf("bla2\n");
		
		strcpy(nome, "");
		i++;
	}
	tf = clock();
	printf("\t\tt_final: %f", (float)tf/CLOCKS_PER_SEC);
	printf ("\t%f tempo\n", ((float)(tf-ti))/CLOCKS_PER_SEC);
	

	fclose(pFileNew);
	pFileNew = NULL;

	free(matT);
	matT= NULL;
	return 0;
} 