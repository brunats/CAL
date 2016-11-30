#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define Mitem 51
#define Mpeso 101
int m[Mitem][Mpeso];

int max(int a, int b){
	if(a>b)
		return 1;
	return b;
}

void mochila(int *p, int *v, int n, int c){
	int i, j, aux1, aux2;
	for(i=0; i<Mitem; i++)
		m[0, i] = 0;
	

}


  Mochila-Prog-Din (p, v, n, c)
1   para  b ← 0  até  c  faça
2   t[0,b] ← 0
3   para  i ← 1  até  n  faça
4   a ← t[i−1,b]
5   se  pi > b
6   então  a′ ← 0
7   senão  a′ ← t[i−1,b−pi] + vi
8   t[i,b] ← max(a, a′)
9   b ← c
10   X ← { }
11   para  i ← n  decrescendo até  1  faça
12   se  t[i,b] ≠ t[i−1,b]
13   então  X ← X ∪ {i}
14   b ← b − pi
15   devolva  X


int main(int argc, char const *argv[]){
	int n_inst, np, pd, pe, i, ccc, j, r;
	int *p, *v;
	scanf("%d", &n_inst);

	for(i=0; i<n_inst; i++){
		scanf("%i", &np);
		for(j=0; j<np; j++){
			scanf("%i %i", &pd, &pe);

		}
		scanf("%i", &ccc);
		malloc(p, ccc*sizeof(int));
		scanf("%i", &r);
		malloc(v, r*sizeof(int));
	}
	

	return 0;
}