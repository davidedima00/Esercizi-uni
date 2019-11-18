/*
Author: Davide Di Marco | Filippo Venturini | Riccardo Leonelli
Date(DeadLine):
Note:
*/



#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main()
{
    int verifica=0;
    int nParole=0;

    //CHIEDO QUANTE PAROLE VUOLE INSERIRE L'UTENTE
    while (nParole<=0 || verifica==0){
        printf("Quante parole vuoi inserire? ");
        verifica=scanf("%d",&nParole);
        if (verifica!=1){
            printf("\nValore inserito errato, inseriscilo nuovamente\n");
        }
        fflush(stdin);
    }
    char **vettoreParole=(char**)malloc(nParole*sizeof(char**));

    char *parola=(char*)malloc((1*sizeof(char))+1);//+1 per il carattere terminatore
                                                   //parola inizialmente contiene un byte di memoria per un char
    char **pVettoreParole;
    pVettoreParole=vettoreParole; //vettore di scorrimento

    if (vettoreParole == NULL || parola == NULL){ //se uno dei due vettori non riesce ad essere allocato
        printf("Memoria insufficiente."); //stampo l'avviso..
        exit(1); //..e chiudo l'esecuzione
    }

    //CHIEDO LE PAROLE ALL UTENTE

    char ch;
    int counter,lenParola;
    for (int i=0;i<nParole;i++){

        counter=0; //contatore del while
        lenParola=0;
        printf("\nInserisci parola %0d: ",i+1);

       while ((ch=getchar())!= '\n'){
               lenParola++; //aumenta di uno la lunghezza
               if (lenParola>1){
                    parola=realloc(parola,lenParola*sizeof(char)); //rialloca spazio per gli altri char
               }
               *(parola+counter)=ch;
               counter++;
        }
        *(parola+lenParola)='\0'; //aggiungo il carattere terminatore alla parola
        //vettoreParole++;
        *(vettoreParole+i)=parola; //aggiungo la parola al vettore delle parole

        printf("Parola inserita: %s indirizzo: %d\n ",*(vettoreParole+i),vettoreParole+i);
    }
    printf("\nIndirizzo del puntatore di scorrimento: %d",pVettoreParole);
    //VISUALIZZO LE PAROLE
    for (int indice=0;indice<nParole;indice++){
            printf("Parola %d: %s | indirizzo: %d\n",indice+1,*(pVettoreParole+indice), pVettoreParole+indice);
    }
    free(parola);
    free(vettoreParole);
    return 0;
}
