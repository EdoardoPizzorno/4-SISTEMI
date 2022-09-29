#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFFER 20

int menu(){
    int sc=0;

    printf("0. ESCI\n");
    printf("1. Cifratura\n");

    printf("Scelta --> ");
    scanf("%d",&sc);

    return sc;
}
void cifraturaCesare(char *s, int n);
void cifratura2(char *s, int n);

int main()
{
    int scelta=0;

    char s[BUFFER];

    int n=0;

    do{
        fflush(stdin);
        scelta=menu();
        switch(scelta){
        case 0:
            break;
        case 1:
            getchar();
            printf("Inserisci stringa: ");
            gets(s);
            printf("Inserisci n: ");
            scanf("%d",&n);
            cifraturaCesare(&s,n);
            printf("\nStringa modificata: %s",s);
            break;
        case 2:
            getchar();
            printf("Inserisci stringa: ");
            gets(s);
            printf("Inserisci n: ");
            scanf("%d",&n);
            cifratura2(&s, n);
        }
        fflush(stdin);
        getchar();
        system("@cls||clear");
    }while(scelta!=0);
    printf("Programma terminato...");
    return 0;
}
void cifratura2(char *s, int n){
}
void cifraturaCesare(char *s, int n){
    while(*s != '\0'){
        *s+=n;
        s++;
    }
}
