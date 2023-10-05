#include <stdio.h>
#include <stdlib.h>

int main()
{
    int v[]={3, 6, 9};

    for(int i=0;i<3;i++){
        printf("v[%d]: %d - Addr: %p\n", i, v[i], &v);
    }
    //stampo contenuto vettore usandolo come puntatore
    //*(v+1)=10; //IN QUESTO MODO VADO A MODIFICARE IL VALORE DI V[1] in 10 al posto di 6
    for(int i=0;i<3;i++){
        printf("%d\n",*(v+i));
    }
    return 0;

}
