#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX 50
#define TRUE 1
#define FALSE 0

int menu(){
    char sc;

    printf("q. ESCI\n");
    printf("a. array\n");
    printf("b. decrescente\n");
    printf("c. doppie\n");
    printf("d. due stringhe lettere doppie\n");

    printf("Scelta --> ");
    scanf("%c",&sc);

    return sc;
}

void caricaVet(int *v, int n);
void stampaVet(int *v, int n);
int verificaFibonacci(int *v, int *fibo, int n);
int verificaDecrescente(char *s);
void verificaDoppie(char *s);
void charInComune(char *s1, char *s2);

int main()
{
    char scelta;

    int v[MAX];
    int fibo[MAX];
    int n=0;

    char s[MAX];

    char s2[MAX];

    do{
        fflush(stdin);
        scelta=menu();
        switch(scelta){
            case 'q':
                break;
            case 'Q':
                break;
            case 'a':
                do{
                    printf("\nInserisci la lunghezza del vettore: ");
                    scanf("%d",&n);
                }while(n<=2 || n>MAX);
                caricaVet(v,n);
                if(verificaFibonacci(v,fibo,n)==TRUE) printf("\nCome Fibonacci");
                else if(verificaFibonacci(v,fibo,n)==FALSE) printf("\nNon come Fibonacci");
                break;
            case 'b':
                printf("\nInserisci stringa: ");
                scanf("%s",&s);
                if(verificaDecrescente(s)==TRUE) printf("\nDecrescente");
                else printf("\nNon decrescente");
                break;
            case 'c':
                printf("\nInserisci stringa: ");
                scanf("%s",&s);
                verificaDoppie(s);
                break;
            case 'd':
                printf("\nInserisci prima stringa: ");
                scanf("%s",&s);
                printf("\nInserisci seconda stringa: ");
                scanf("%s",&s2);
                charInComune(s,s2);
                break;
        }
        fflush(stdin);
        getchar();
        system("@cls||clear");
    }while(scelta!='q' && scelta!='Q');
    printf("Premi per continuare...");
    return 0;
}
void charInComune(char *s1, char *s2){
    int len1=0;
    int len2=0;
    int cont[MAX]={0};
    int contLen=0;

    while(*s1!='\0'){
        len1++;
        s1++;
    }
    while(*s2!='\0'){
        len2++;
        s2++;
    }
    for(int i=0;i<len1;i++){
        for(int j=0;j<len2;j++){
            if(*(s1+i)==*(s2+j)){
                int aus=*(s1+i);
                cont[aus]++;
                contLen++;
            }
        }
    }
    int doppi=0;
    for(int i=0;i<contLen;i++){
        if((cont+i)>1)
            doppi++;
    }
    printf("I caratteri che si ripetono sono: %d", doppi);
}
void verificaDoppie(char *s){
    int cont=0;

    int doppie=FALSE;
    char doppieVet[MAX];
    int indexDoppie=0;

    int len = 0;
    for(; *(s+len); len++);

    for(int i=0; i<len; i++)
    {
        int j = i-1;
        cont = 0;
        while((j>=0) && (*(s+j) != *(s+i)))
            j--;
        if(j<0)
        {
            cont = 1;
            for(j = i+1; j<len; j++)
                if(*(s+i) == *(s+j))
                    cont++;
            if(cont>1){
                *(doppieVet+indexDoppie)=*(s+i);
                indexDoppie++;
                doppie=TRUE;
            }
        }
    }
    if(doppie==TRUE){
        printf("\nLe doppie sono: ");
        for(int i=0;i<indexDoppie;i++){
            printf("%c ",*(doppieVet+i));
        }
    }else printf("\nNon ci sono doppie");
}
int verificaDecrescente(char *s){
    int decrescente=TRUE;

    printf("stringa: %s",s);

    int i=0;
    while(decrescente==FALSE || *s!='\0'){
        if(*(s+(i+1))>*(s+i))
            decrescente=FALSE;
    }
    return decrescente;
}
int verificaFibonacci(int *v, int *fibo, int n){
    int fibonacci=TRUE;
    int i=0;
    caricaVetFibo(&(*fibo),n);
    *(v+0)=0;
    *(v+1)=1;
    *(v+2)=1;
    *(v+3)=2;
    *(v+4)=3;
    *(v+5)=5;
    *(v+6)=8; //ecc
    stampaVet(&(*v),n);
    while(fibonacci==FALSE || i!=n){
        if(*(v+i)!=*(fibo+i))
            fibonacci=FALSE;
        i++;
    }
    return fibonacci;
}
void caricaVetFibo(int *fibo, int n){
    int a=0;
    int b=1;
    int c=0;
    *(fibo+0)=0;
    *(fibo+1)=1;
    for(int i=2;i<n;i++){
        c=a+b;
        a=b;
        b=c;
        *(fibo+i)=c;
    }
    printf("\nFibo: ");
    for(int i=0;i<n;i++){
        printf("%d ",*(fibo+i));
    }
}
void stampaVet(int *v, int n){
    for(int i=0;i<n;i++){
        printf("\n%d) %d",i,*(v+i));
    }
}
void caricaVet(int *v, int n){
    for(int i=0;i<n;i++){
        *(v+i)=(rand()%MAX)+1;
    }
}
