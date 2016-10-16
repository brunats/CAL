#include <stdio.h>
#include <stdlib.h>
#include <time.h>
/*
void printArray(int * array, int size){

  int curr;
  for(curr = 0; curr < size; curr++){
    printf("%d, ", array[curr]);
  }
  printf("\n");
}
*/
int fmax(int *array, int size){

  int curr = 0;
  int max = 0;

  for(curr = 0; curr < size; curr++){
    if(array[curr] > max){ max = array[curr]; }
  }

  return max;
}

void countingSort(int *array, int size){
  int curr = 0;
  int max = fmax(array, size);

  int *counting_array;
  counting_array = NULL;

  counting_array = calloc(max, sizeof(int));
  for(curr = 0; curr < size; curr ++){
    counting_array[array[curr]]++;
  }

  int num = 0;
  curr = 0;

  while(curr <= size){
    while(counting_array[num] > 0){
      array[curr] = num;
      counting_array[num]--;
      curr++;
      if(curr > size){ break; }
    }
    num++;
  }
  //printArray(array, size);
  free(counting_array);
  counting_array = NULL;
}

int main(){

  int mat[1000010];
  int size1 , i, j;
  clock_t ti, tf;

  printf("Entre o Tamanho do Vetor: ");
  scanf("%i", &size1);
  for(j=0; j<5; j++){
    srand( (unsigned)time(NULL) );
    for (i = 0; i < size1; i++){
        mat[i] = rand()%size1; ; // modifique aqui pra algum rand() ou outra coisa para fazewr o teste. o I ali é só pra ter algo
    }
    ti = clock();
    countingSort(mat, size1);
    tf = clock();
    printf ("\t%iº: %f tempo\n", j+1, ((float)(tf-ti))/CLOCKS_PER_SEC);
  }
  return 0;
}
