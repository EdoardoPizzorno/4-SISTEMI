#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define BUFFER 20
#define TRUE 1
#define FALSE 0

int menu();
void invertiStringa(char s1[]);
void concatenaStringa(char s1[], char s2[]);
void esercizio(int v[], int n);

int main()
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
                break;
            case 1:
                printf("\nInserisci stringa: ");
                scanf("%s",&s1);
                invertiStringa(s1);
                break;
            case 2:
                printf("\nInserisci prima stringa: ");
                scanf("%s",&s1);
                printf("Inserisci seconda stringa: ");
                scanf("%s",&s2);
                concatenaStringa(s1,s2);
                break;
            case 3:
                printf("Inserisci la lunghezza del vettore: ");
                scanf("%d",&n);
                int v[n];
                for(int i=0;i<n;i++){
                    printf("Inserisci elemento %d: "+(i+1));
                    scanf("%d",&v[i]);
                }
                esercizio(v,n);
                break;
        }
        fflush(stdin);
        getchar();
        system("@cls||clear");
    }while(scelta!=0);
    printf("Premi per continuare...");
    return 0;
}
void esercizio(int v[], int n){
    ordina(v,n);
    for(int i=0;i<n;i++){
        printf("\nElemento %d: %d",(i+1),*(v+i));
    }
}
void ordina(int v[], int n){
    for(int i=0;i<=n-2;i++){
        int posmin=i;
        for(int j=i+1;j<=n-1;j++){
            if(v[posmin]>v[j])
                posmin=j;
        }
        if(posmin!=i){
            int aus=v[i];
            v[i]=v[posmin];
            v[posmin]=aus;
        }
    }
}
void concatenaStringa(char s1[], char s2[]){
    char *ps1;
    char *ps2;
    char *ps3;
    char s3[BUFFER];
    ps1=s1;
    ps2=s2;
    ps3=s3;

    while(strlen(s3)!=strlen(s1)){
        *(ps3++)=*(ps1++);
    }
    while(strlen(s3)!=(strlen(s1)+strlen(s2))){
        *(ps3++)=*(ps2++);
    }
    ps3='\0';
    printf("FINALE: %s",s3);
}
void invertiStringa(char s1[]){
    char *ps1;
    char *s;
    char s2[BUFFER];

    s=s2;
    ps1=s1;
    ps1+=(strlen(ps1)-1);
    while(strlen(s2)!=strlen(s1)){
        *(s++)=*(ps1--);
    }
    s='\0';
    printf("FINALE: %s",s2);
}
int menu(){
    int sc=0;

    printf("1. Inverti stringa\n");
    printf("2. Concatena stringa\n");
    printf("3. Ordina contenuto vettore dato in input\n");

    printf("Scelta--> ");
    scanf("%d",&sc);
    return sc;
}
