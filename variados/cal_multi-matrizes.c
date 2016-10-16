#include <stdio.h>
#include <stdlib.h>
#define MAX 20
/*************************************/
/*
Elabore os seguintes algoritmos e analise o seu tempo de 
execução para diferentes entradas e a sua complexidade de tempo.
2) Implemente um algoritmo (função) que recebe duas matrizes 
quadradas de mesma ordem (n) e realiza a multiplicação entre elas.
*/
/*************************************/

int main(){
	int mat_A[MAX][MAX], mat_B[MAX][MAX], mat_C[MAX][MAX];
	int i, j, a, b, aux, n;

	printf("Digite a ordem\n");
	scanf("%i", &n);

	printf("Leitura Matriz A\n");
	//Carrega Matriz A
	for(i=0; i<n; i++){
		for(j=0; j<n; j++){
			scanf("%i", &mat_A[i][j]);
		}
	}

	printf("Leitura Matriz B\n");
	//Carrega Matriz B
	for(i=0; i<n; i++){
		for(j=0; j<n; j++){
			scanf("%i", &mat_B[i][j]);
		}
	}

	
	//Multiplica A-B
	for(i=0; i<n; i++){							// O(n)
		for(j=0; j<n; j++){						// O(n)
			aux=0;								// O(1)
			for(a=0; a<n; a++)					// O(n)
				aux += mat_A[i][a]*mat_B[a][i];	// O(1)
			mat_C[i][j] = aux;					// O(1)
				
		}
		aux=0;									// O(1)
	}
	

	printf("Matriz A\n");
	//Mostra Matriz A
	for(i=0; i<n; i++){
		for(j=0; j<n; j++){
			printf("%i ", mat_A[i][j]);
		}
		printf("\n");
	}

	printf("Matriz B\n");
	//Mostra Matriz B
	for(i=0; i<n; i++){
		for(j=0; j<n; j++){
			printf("%i ", mat_B[i][j]);
		}
		printf("\n");
	}
	
	printf("Matriz Resultante C\n");
	//Mostra Matriz C
	for(i=0; i<n; i++){
		for(j=0; j<n; j++){
			printf("%i ", mat_C[i][j]);
		}
		printf("\n");
	}

	//Resultado Complexidade O(n³)
	
	return 0;
}