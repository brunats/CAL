#include <stdio.h>

float raiz_quadrada(float numero);

int main( int argc, char **argv)
{  
    float numero;
   
    printf("Entre com um número positivo por favor : ");
    scanf("%f",&numero);
   
    printf("A raiz quadrada de %.3f é %.5f \n",numero,raiz_quadrada(numero));

    return(0);
}


float raiz_quadrada (float numero)
{
    int n;                              //O(1)
    float rec = numero;                 //O(1)
   
    for (n = 0; n < 10; ++n)            //O(n)
          rec = rec/2 + numero/(2*rec); //O(1)
           
    return(rec);                        //O(1)
}

/*
Complexidade de tempo
    O(n)
Complexidade de espaco
    O(1)
    */