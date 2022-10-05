#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFFER 20

int menu(){
    int sc=0;

    printf("0. ESCI\n");
    printf("1. Cifratura semplice\n");
    printf("2. Cifratura di Cesare\n");

    printf("Scelta --> ");
    scanf("%d",&sc);

    return sc;
}
void cifraturaSemplice(char *s, int n);
void cifraturaCesare(char *s, char *key);

int main()
{
    int scelta=0;

    char s[BUFFER];

    int n=0;

    char key=' ';

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
            cifraturaSemplice(&s,n);
            printf("\nStringa modificata: %s",s);
            break;
        case 2:
            getchar();
            printf("Inserisci stringa: ");
            gets(s);
            do{
                printf("\nInserisci chiave: ");
                scanf("%c",&key);
            }while(key<=64 || key>=91 && key<=96 || key>=123);
            cifraturaCesare(&s, &key);
            printf("\nStringa modificata: %s",s);
        }
        fflush(stdin);
        getchar();
        system("@cls||clear");
    }while(scelta!=0);
    printf("Programma terminato...");
    return 0;
}
void cifraturaCesare(char *s, char *key){
    if(*key>='a' && *key<='z')
        *key-=('a'-1);
    else if(*key>='A' && *key<='Z')
        *key-=('A'-1);
    printf("%d",*key);
    while(*s != '\0'){
        if(*s >= 'a' && *s <= 'z' || *s >= 'A' && *s <= 'Z'){
            if(*s >= ('z'-(*key-1)) && *s <= 'z')
                *s -= (23+*key+1);
            else *s += *key;
        }
        if(*s >= 'A' && *s <= 'Z'){
            if(*s >= ('Z'-(*key-1)) && *s <= 'Z')
                *s -= (23+*key+1);
            else *s += *key;
         }
        s++;
    }
}
void cifraturaSemplice(char *s, int n){
    while(*s != '\0'){
        if(*s+n > 64 && *s+n < 91)
            *s+=n;
        if(*s+n > 96 && *s+n<123)
            *s+=n;
        s++;
    }
}
