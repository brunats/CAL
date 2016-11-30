#include "stdio.h"
#include "stdlib.h"

float min(float a, float b, float c){
	if(a < b && a < c)
		return a;
	if(b < a && b < c)
		return b;
	if(c < a && c < b)
		return c;
}
int main (){
	int i, j;
	int n_inst, n_tipo_bloco, comp;
	int *mat, *troco;
	
	//entrada de dados
	scanf("%i", &n_inst);
	i=0;
	while(i<n_inst){
		scanf("%i %i", &n_tipo_bloco, &comp);
		mat = malloc(n_tipo_bloco * sizeof(int));
		troco = malloc((comp+1) * sizeof(int));
		for(j=0; j<n_tipo_bloco; j++){
			scanf("%i", &mat[j]);
		}
		troco[0] = 0;
		for(j=1; j<n_tipo_bloco; j++){
			troco[j] = min(1+troco[j-mat[])
		}
			
		
		
		i++;
	}
	free(mat);
	mat = NULL;
	printf("eeeee");
return 0;
}
