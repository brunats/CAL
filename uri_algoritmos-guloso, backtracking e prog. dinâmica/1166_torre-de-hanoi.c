#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAX 51
int m[52];

int ehQuadP(int a){
	int aux = sqrt(a);
	if(a%aux == 0)
		return 1;
	else
		return 0;
}

void calculaNBolas(){
	int i, j, ml[MAX], cont, flag, p, te;

	i=0;
	while(i<MAX){
		ml[i] =  0;
		i++;
	}
	
	p=0;
	cont=1;
	for(i=0; i<MAX+1; i++){
		flag=1;
		for(j = 1; j < i+1; ++j){
			if(ehQuadP(ml[j]+cont)){
				flag--;
				ml[j] = cont;
			}
		}
		if(flag){
			m[i] = cont-1;
			ml[i+1] = cont;
		}
	}
}

int main(int argc, char const *argv[]){
	int n_inst, v, b, i;
	scanf("%d", &n_inst);

	calculaNBolas();
	for(i=0; i<n_inst; i++){
		scanf("%i", &v);
		printf("%i\n", m[v]);
	}
	

	return 0;
}