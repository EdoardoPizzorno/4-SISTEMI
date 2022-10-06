#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFFER 20

int menu(){
    int sc=0;

    printf("0. ESCI\n");
    printf("1. Cifratura semplice\n");
    printf("2. Cifratura Cesare\n");
    printf("3. Data una stringa visualizzare in output le ricorrenze\n");
    printf("4. Date due stringhe verificare se sono l'anagramma l'una dell'altra\n");
    printf("5. Date due stringhe verificare se sono Hertzianamente compatibili\n");

    printf("Scelta --> ");
    scanf("%d",&sc);

    return sc;
}
void cifraturaSemplice(char *s, int n);
void cifraturaCesare(char *s, char *key);
void visualizzaRicorrenze(char *s);
void anagramma(char *s, char *s2);
void hertzianamenteCompatibili(char *s, char *s2);

int main()
{
    int scelta=0;

    char s[BUFFER];
    char s2[BUFFER];

    int n=0;
    char key;

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
            break;
        case 3:
            getchar();
            printf("Inserisci stringa: ");
            gets(s);
            visualizzaRicorrenze(s);
            break;
        case 4:
            getchar();
            printf("Inserisci prima stringa: ");
            gets(s);
            printf("Inserisci seconda stringa: ");
            gets(s2);
            anagramma(s,s2);
            break;
        case 5:
            getchar();
            printf("Inserisci prima stringa: ");
            gets(s);
            printf("Inserisci seconda stringa: ");
            gets(s2);
            hertzianamenteCompatibili(s,s2);
            break;
        }
        fflush(stdin);
        getchar();
        system("@cls||clear");
    }while(scelta!=0);
    printf("Programma terminato...");
    return 0;
}
void hertzianamenteCompatibili(char *s, char *s2){

}
void anagramma(char *s, char *s2){

}
void visualizzaRicorrenze(char *s){
    int contLen=0;
    contLen='Z'-'A';

    int cont[contLen];

    for(int i=0;i<contLen;i++) cont[i]=0;

    for(; *s != '\0'; s++){
        cont[(*s-32)]++;
        printf("%d\n",*s-32);
    }
    /*for(int i=('a')-32;i<('z')-32;i++){
        printf("\nLa lettera '%c' compare %d volte",('a'+i),cont[i]);
    }*/
}
void cifraturaCesare(char *s, char *key){
    if(*key>='a' && *key<='z')
        *key-=('a');
    else if(*key>='A' && *key<='Z')
        *key-=('A');

    printf("%d",*key);
    while(*s != '\0'){
        if(*s >= 'A' && *s <= 'Z'){
            if(*s + *key <= 'Z')
                *s += *key;
            else *s = 'A' + (*s + *key - 'Z' - 1);
         }
        s++;
    }
}
void cifraturaSemplice(char *s, int n){
    while(*s != '\0'){
        if(*s + n > 0 && *s + n < 128)
            *s+=n;
        s++;
    }
}
