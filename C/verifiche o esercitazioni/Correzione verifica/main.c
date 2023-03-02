#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX 50+1
#define TRUE 1
#define FALSE 0

char menu(){
    char sc;

    printf("q. ESCI\n");
    printf("a. Problema1\n");
    printf("b. Problema2\n");
    printf("c. Problema3\n");
    printf("d. Problema4\n");

    printf("Scelta-->");
    scanf("%c",&sc);
    return sc;
}
void caricaVet(int *v, int len);
void stampaVet(int *v, int len);
int verificaFibonacci(int *v, int len);
int verificaOrdinataDec(char *s);
int verificaDoppie(char *s);
void verificaCaratteriComuni(char *s1, char *s2);

int main()
{
    char scelta;

    srand(time(NULL));

    int v[MAX];
    int len=0;

    char s1[MAX];
    char s2[MAX];

    do{
        scelta=menu();
        switch(scelta){
        case 'a':
        case 'A':
            fflush(stdin);
            do{
                printf("\nInserisci lunghezza vettore: ");
                scanf("%d",&len);
            }while(len<3 || len>MAX);
            caricaVet(v,len);
            stampaVet(v,len);
            if(verificaFibonacci(v,len)==TRUE)
                printf("\nFibonacci");
            else
                printf("\nNO Fibonacci");
            getchar();
            break;
        case 'b':
        case 'B':
            printf("Inserisci stringa: ");
            scanf("%s",&s1);
            if(verificaOrdinataDec(s1)==TRUE)
                printf("Ordinata DECRESCENTE");
            else printf("NON ordinata decrescente");
            getchar();
            break;
        case 'c':
        case 'C':
            printf("Inserisci stringa: ");
            scanf("%s",&s1);
            if(verificaDoppie(s1)==TRUE)
                printf("La stringa '%s' contiene doppie");
            else printf("La stringa '%s' non contiene doppie");
            getchar();
            break;
        case 'd':
        case 'D':
            printf("Inserisci la prima stringa: ");
            scanf("%s",&s1);
            printf("Inserisci la seconda stringa: ");
            scanf("%s",&s2);
            verificaCaratteriComuni(s1,s2);
            getchar();
            break;
        }
        getchar();
        fflush(stdin);
        system("@cls||clear");
    }while(scelta!='q' && scelta!='Q');
    printf("Premi per continuare...");
    return 0;
}
void verificaCaratteriComuni(char *s1, char *s2){
    int len1;
    int len2;
    int cont=0;

    for(len1=0; *(s1+len1)!='\0';len1++);
    for(len2=0; *(s2+len2)!='\0';len2++);

    for(int i=0;i<len1;i++){
        int j=0;
        while(*(s1+j) != *(s1+i) && j<1)
            j++;
        if(i==j){
            j=0;
            while(*(s2+j) == *(s1+i) && *(s2+j)!=*(s1+i))
                j++;
            if(*(s2+j)!='\0')
                cont++;
        }
    }
    printf("\nI caratteri che si ripetono sono: %d",cont);
}
int verificaDoppie(char *s){
    int doppie=FALSE;
    int i=0;
    int j=0;
    char *pP;
    char *pA;
    pP=s;
    pA=s+1;

    while(*pA!='\0' && *pA!=*pP){
        pA++;
        pP++;
    }
    if(*pA!='\0')
        doppie=TRUE;
    return doppie;
}
int verificaOrdinataDec(char *s){
    int decrescente=TRUE;

    int i=0;
    int j=1;
    while(*(s+i)>=*(s+j) && *(s+j)!='\0'){
        i++;
        j++;
    }
    if(*(s+j)!='\0')
        decrescente=FALSE;
    return decrescente;
}
void caricaVet(int *v, int len){
    int *pV;
    for(pV=v; pV<(v+len);pV++){
        *pV=rand()%MAX;
    }
}
void stampaVet(int *v, int len){
    int *pV;
    for(pV=v; pV<(v+len);pV++){
        printf("%d ",*pV);
    }
}
int verificaFibonacci(int *v, int len){
    int a=*v;
    int b=*(v+1);
    int *pV;
    int fibonacci=FALSE;
    int aus;

    pV=(v+2);

    if(a==0 && b==1){
        while(*pV == (a+b) && pV<(v+len)){
            aus=a+b;
            a=b;
            b=aus;
            pV++;
        }
        if(pV == (v+len))
            fibonacci=TRUE;
    }
    return fibonacci;
}
