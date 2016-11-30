#include <stdio.h>
#include <stdlib.h>
#define M_TIPO 26
#define N_MAX 10000001

int fmin(int a, int b){
	if(a>b)
		return b;
	return a;
}

int minB(int M[M_TIPO], int c, int t[N_MAX], int p){
	int min, i;
	min = 1999999;
	for(i=0; i<c; i++)
		if(p-M[i] > -1)
			min = fmin(min, (1+t[p-M[i]]));
	return min;
}

int calculaBlocos(int M[M_TIPO], int c, int n){
	int i;
	int t[n+1];

	if(n%M[c-1] == 0) //se ele for divisivel pelo maior, nao terá outra seq
		return n/M[c-1];

	t[0] = 0;
	for(i=1; i<n+1; i++){
		t[i] = minB(M, c, t, i);
	}
	return t[n];
}

void buble(int vet[M_TIPO], int n){
	int i, j, tmp;
	i=0;
    for (i = n; i > 0; i--){
        for (j = 1; j < i; j++){
            if(vet[j-1] > vet[j]){
                tmp = vet[j-1];
                vet[j-1] = vet[j];
                vet[j] = tmp;
            }
        }
    }
}

void print_Blocos(int mat[M_TIPO], int n){
	int i = 0;
	while(i<n){
		printf("%i ", mat[i]);
		i++;
	}
}

void le_Blocos(int mat[M_TIPO], int n){
	int i = 0;
	while(i<n){
		scanf("%i", &mat[i]);
		i++;
	}
}

int main(int argc, char const *argv[])
{
	int n_inst, n_tipo, tam, i, qtd_blocos;
	int mat[M_TIPO];

	scanf("%d", &n_inst);
	for(i=0; i<n_inst; i++){
		scanf("%i %i", &n_tipo, &tam);
		le_Blocos(mat, n_tipo);
		buble(mat, n_tipo);
		qtd_blocos = calculaBlocos(mat, n_tipo, tam);
		printf("%i\n", qtd_blocos);
	}
	

	return 0;
}