#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAX 51
int m[51];

int ehQuadP(int a){
	int aux = sqrt(a);
	if(a%aux == 0)
		return 1;
	else
		return 0;
}

void calculaNBolas(){
	int i, ml[MAX], cont, flag, p;
	p=0;
	cont=0;
	while(1){
		flag == 1;
		for(i=0; i<MAX;i++){
			if(ehQuadP(ml[i]+cont));{
				flag--;
				ml[i] = cont;
			}
		}
		if(flag){
			m[p] = cont-1;
			ml[p++] = cont;
			if(p == 51)
				break;
		}
		cont++;
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