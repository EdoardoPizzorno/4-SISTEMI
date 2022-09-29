#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define BUFFER 20
#define TRUE 1
#define FALSE 0

int menu();
void invertiStringa(char *s1);
void concatenaStringa(char *s1, char *s2);
void esercizio(int *v, int n);
void convertiMinMaiuscViceversa(char s1[]);

int main(int argv, int *argc[])
{
    int scelta=0;

    char s1[BUFFER];
    char s2[BUFFER];

    int n=0;

    do{
        fflush(stdin);
        scelta=menu();
        switch(scelta){
            case 0:
                getchar();
                printf("Inserisci stringa: ");
                gets(s1);
                convertiMinMaiuscViceversa(&s1);
                break;
            case 1:
                getchar();
                printf("Inserisci stringa: ");
                gets(s1);
                invertiStringa(&s1);
                printf("Stringa modificata: %s",s1);
                break;
            case 2:
                getchar();
                printf("Inserisci prima stringa: ");
                gets(s1);
                printf("Inserisci seconda stringa: ");
                gets(s2);
                concatenaStringa(&s1,&s2);
                printf("Stringa concatenata: %s",s1);
                break;
            case 3:
                printf("Inserisci la lunghezza del vettore: ");
                scanf("%d",&n);
                int v[n];
                for(int i=0;i<n;i++){
                    printf("Inserisci elemento %d: ",(i+1));
                    scanf("%d",&v[i]);
                }
                esercizio(&v,n);
                break;
        }
        fflush(stdin);
        getchar();
        system("@cls||clear");
    }while(scelta!=0);
    printf("Premi per continuare...");
    return 0;
}
void esercizio(int *v, int n){
    ordina(v,n);
    for(int i=0;i<n;i++){
        printf("\nElemento %d: %d",(i+1),*(v+i));
    }
}
void ordina(int *v, int n){
    for(int i=0;i<=n-2;i++){
        int posmin=i;
        for(int j=i+1;j<=n-1;j++){
            if(*(v+posmin)>*(v+j))
                posmin=j;
        }
        if(posmin!=i){
            int aus=*(v+i);
            *(v+i)=*(v+posmin);
            *(v+posmin)=aus;
        }
    }
}
void concatenaStringa(char *s1, char *s2){
    while(*s1 != '\0')
        s1++;
    while(*s2 != '\0'){
        *s1 = *s2;
        s1++;
        s2++;
    }
    *s1 = '\0';
}
void invertiStringa(char s1[]){
    char *pF;
    char aus;

    pF=s1;

    while(*pF != '\0')
        pF++;
    pF--;
    while(s1 < pF){
        aus = *s1;
        *s1 = *pF;
        *pF = aus;
        s1++;
        pF--;
    }
}
int menu(){
    int sc=0;

    printf("0. Converti da maiuscolo in minuscolo o viceversa\n");
    printf("1. Inverti stringa\n");
    printf("2. Concatena stringa\n");
    printf("3. Ordina contenuto vettore dato in input\n");

    printf("Scelta--> ");
    scanf("%d",&sc);
    return sc;
}
void convertiMinMaiuscViceversa(char *s1){
    char s2[20];
    char *ps2;

    ps2=s2;

    do{
        if(*s1>64 && *s1<91)
            *ps2=(*s1+32);
        else{
            if(*s1>96 && *s1<123)
                *ps2=(*s1-32);
            else *ps2=*s1;
        }
        ps2++;
        s1++;
    }while(*s1!='\0');

    *ps2='\0';
    printf("Stringa modificata: %s",s2);
}
