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
int anagramma(char *s, char *s2);
int hertzianamenteCompatibili(char *s, char *s2);

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
            if(anagramma(s,s2)==0) printf("\nNo anagramma");
            else printf("\nAnagramma");
            break;
        case 5:
            getchar();
            printf("Inserisci prima stringa: ");
            gets(s);
            printf("Inserisci seconda stringa: ");
            gets(s2);
            if(hertzianamenteCompatibili(s,s2)==0) printf("\nNo compatibili");
            else printf("\nCompatibili");
            break;
        }
        fflush(stdin);
        getchar();
        system("@cls||clear");
    }while(scelta!=0);
    printf("Programma terminato...");
    return 0;
}
int hertzianamenteCompatibili(char *s1, char *s2){
    int lenS1 = 0, lenS2 = 0;
    int i, ret;

    for(; *(s1+lenS1) != '\0'; lenS1++);
    for(; *(s2+lenS2) != '\0'; lenS2++);
    if (lenS1 != lenS2)
        ret = 0; // Se lunghezza diversa
    else{
        // Verifico
        ret = 1;
        i = 1;
        while((i<lenS1) && (ret == 1))// VERIFICA COMPATIBILITA' DIRETTA
        {
            if(*(s1+i) != *(s2+i))
                ret = 0;
            i = i+2;
        }
        if (ret == 0) // VERIFICA COMPATIBILITA' INVERSA
        {
            ret = 1;
            i = 0;
            while((i<lenS1) && (ret == 1))
            {
                if(*(s1+i) != *(s2+i))
                    ret = 0;
                i = i+2;
            }
        }
    }
    return ret;
}
int anagramma(char *s1, char *s2){
    int numS1[BUFFER] = {0}, numS2[BUFFER] = {0};
    int ret, lenS1, lenS2;
    int i;

    lenS1 = 0; lenS2 = 0;
    for(; *(s1+lenS1) != '\0'; lenS1++)
    {// Mentre calcolo lunghezza stringa popolo anche vettore intero rispettivo
     if (*(s1+lenS1)>='a' && *(s1+lenS1)<='z')
             //numS1[s1[lenS1] -'a']++;
             *(numS1+ (*(s1+lenS1)-'a')) += 1;
    }
    for(; *(s2+lenS2) != '\0'; lenS2++)
    {// Mentre calcolo lunghezza stringa popolo anche vettore intero rispettivo
     if (*(s2+lenS2)>='a' && *(s2+lenS2)<='z')
         //numS2[s2[lenS2] -'a']++;
        *(numS2+ (*(s2+lenS2)-'a')) += 1;
    }
    i = 0;
    ret = 1;
    while((i<26) && (ret == 1))
    {
        if(*(numS1+i) != *(numS2+i))
            ret = 0; // NO ANAGRAMMA
        i++;
    }
    return ret;
}
void visualizzaRicorrenze(char *s){
    int j;
    int cont=0;
    int len = 0;
    for(; *(s+len); len++);
    for(int i=0; i<len; i++)
    {
        cont = 0;
        j = i-1;

        while((j>=0) && (*(s+j) != *(s+i)))
            j--;
        if(j<0)
        {
            cont = 1;
            for(j = i+1; j<len; j++)
                if(*(s+i) == *(s+j))
                    cont++;
            printf("Il valore %c e' presente %d volte\n", *(s+i), cont);
        }
    }
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
