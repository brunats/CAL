#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <iostream>
#include <time.h>

using namespace std;

char* itoa(int value, char* result, int base) {
  // check that the base if valid
  if (base < 2 || base > 36) { *result = '\0'; return result; }

  char* ptr = result, *ptr1 = result, tmp_char;
  int tmp_value;

  do {
    tmp_value = value;
    value /= base;
    *ptr++ = "zyxwvutsrqponmlkjihgfedcba9876543210123456789abcdefghijklmnopqrstuvwxyz" [35 + (tmp_value - value * base)];
  } while ( value );

  // Apply negative sign
  if (tmp_value < 0) *ptr++ = '-';
  *ptr-- = '\0';
  while(ptr1 < ptr) {
    tmp_char = *ptr;
    *ptr--= *ptr1;
    *ptr1++ = tmp_char;
  }
  return result;
}


void ordena(char **nomes, int qtde){
    int i, j;
    char aux[65];

    for(i = 0; i < qtde; i++) {
        for(j = 0; j < qtde; j++) {
            if(strcmp(nomes[i], nomes[j]) < 0) {
                strcpy(aux, nomes[i]);
                strcpy(nomes[i], nomes[j]);
                strcpy(nomes[j], aux);
            }
        }
    }
}

void buscaBin(char key[], char **array, int inicio, int fim) {
    int meio, cmp, cont = 0, j = 0, aux3;
    char aux[65] = {NULL}, aux2[65] = {NULL};

    if (inicio > fim) return;
    meio = (inicio + fim) / 2;
    while(cont < 2){
        if(array[meio][j] == ' '){
            cont++;
        }
        if(cont == 2){
            break;
        }
        aux[j] = array[meio][j];
        j++;
    }
    aux[j--] = '\n';
  //  printf("%i%s?%i%s?", strlen(aux),aux, strlen(key),key);
    //system("pause");
    cmp = strcmp(key, aux);
    if (cmp == 0){
        cont = 0;
        j = 0;
        while(cont < 2){
            if(array[meio][j] == ' '){
                cont++;
            }
            //aux2[j] = array[meio][j];
            if(cont == 2){
                break;
            }
            j++;
        }
        int extra = strlen(array[meio]);
        array[meio][extra] = '\n';
        int y = 0;
        j++;
        while(array[meio][j] != '\n'){
            aux2[y] = array[meio][j];
            j++;
            y++;
            strcat(aux2, "\n");
        }
        //printf("%s", aux2);
    }
    if (cmp < 0)
        return buscaBin( key, array, inicio, meio - 1);
    else
        return buscaBin( key, array, meio + 1, fim);
}
int main(){
    FILE *entrada;
    char c, minhaString[65] = {NULL}, numString[6] = {NULL}, auxV [5] = {NULL}, aux[65] = {NULL};
    int qtdPares, qtdPares_verificacao, j = 0, i = 0, aux2 = 0, aux3 = 0, aux4 = 0;
    char **vetorzao = {NULL};
    clock_t ti, tf;

    if((entrada = fopen("entrada-5.txt", "r")) == NULL){
        printf("Erro ao abrir o arquivo!\n");
    }
    fscanf(entrada, "%i\n", &qtdPares);

    vetorzao = (char **) malloc((qtdPares*2) * sizeof(char *));
    for (i = 0; i < (qtdPares*2); i++){
    	vetorzao[i] = (char *) malloc(50 * sizeof(char));
    }

    for(i = 0; i < (qtdPares*2); i++){
        for(j = 0; j < 50; j++){
            vetorzao[i][j] = NULL;
        }
    }

    for(i = 0; i < qtdPares; i++){
        j = 0;
        while(c != ' '){
            fscanf(entrada, "%c", &c);
            minhaString[j] = c;
            j++;
        }
        int num = atoi(minhaString);
        itoa(num, numString,10);
        auxV[0] = ' ';
        for(int x = 1; x <= (strlen(numString)); x++){
            auxV[x] = numString[x-1];
            aux2 = x;
        }
        auxV[aux2+1] = '\n';
        j = 0;
        while(c != '\n'){
            fscanf(entrada, "%c", &c);
            if(c != '\n'){
                minhaString[j] = c;
            }
            j++;
        }
        strcat(minhaString, auxV);
        int len = strlen(minhaString);
        for(int x = 0; x < len; x++){
            vetorzao[i][x] = minhaString[x];
        }
        //printf("%s", vetorzao[i]);
        memset(&auxV, 0, sizeof(auxV));
        aux2 = 0;
        memset(&minhaString, 0, sizeof(minhaString));
    }
    ordena(vetorzao, qtdPares);
    fscanf(entrada, "%i\n", &qtdPares_verificacao);

    ti = clock();
    printf("\t\tinicial: %f", (float)ti/CLOCKS_PER_SEC);
    for(i = 0; i < qtdPares_verificacao; i++){
        j = 0;
        while(c != ' '){
            fscanf(entrada, "%c", &c);
            minhaString[j] = c;
            j++;
        }
        while(c != '\n'){
            fscanf(entrada, "%c", &c);
            minhaString[j] = c;
            j++;
        }
        j = 0;
        buscaBin(minhaString, vetorzao, 0, qtdPares);
        /*if(chave != -1){
            printf("%i\n", chave);
        }*/
        memset(&minhaString, 0, sizeof(minhaString));
    }
    tf = clock();
    printf("\t\tt_final: %f", (float)tf/CLOCKS_PER_SEC);
    printf ("\t%f tempo\n", ((float)(tf-ti))/CLOCKS_PER_SEC);

    free(vetorzao);
    fclose(entrada);
    return 0;
}
