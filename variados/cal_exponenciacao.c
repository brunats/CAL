#include <stdio.h>
#include <stdlib.h>

/*************************************/
/*
Elabore os seguintes algoritmos e analise o seu tempo de 
execução para diferentes entradas e a sua complexidade de tempo.
1) Implemente um algoritmo (função) que recebe como 
parâmetro dois valores inteiros a e b e calcula  a^b. 
*/
/*************************************/
int main(){
	int a, b, i, cont;

	scanf("%i %i", &a, &b);		//
								//
	cont=1;						//
	for(i=0; i<b; i++){			// O(n)
		cont = cont*a;			// O(1)
	}
	printf("%i^%i = %i\n", a, b, cont);
	//Resultado Complexidade O(n)
	return 0;
}