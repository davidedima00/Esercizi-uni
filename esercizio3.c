/*
Author: Davide Di marco | Riccardo Leonelli | Filippo Venturini
Date: 17/10/2019
Notes:
*/

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h> //contiene la funzione memset

int main()
{
    unsigned char carattere;
    char bufferA[100]; //insieme di caratteri, è una stringa
    int index=0;

    memset(bufferA,'\0',sizeof(bufferA)); //con la funzione memset si pulische

    unsigned int lTesto=0; //lunghezza del testo

    unsigned int nSpazi=0, nMaiuscole=0, nMinuscole=0, nPunteggiatura=0,
    nNumeri=0, nGrafici=0,nStamp=0,nControl=0,
    nAlpha=0,nAlNum=0,nBlack=0; //VARIABILI CHE CONTENGONO LE CARATTERISTICHE DEL TESTO

    printf("Inserisci un testo (deve terminare con il carattere '#'):");

    while ((carattere=getchar())!='#'){ //CICLO PER OGNI CARATTERE DEL TESTO, il getchar legge carattere per carattere

           bufferA[index++]=carattere; //creo la stringa aggiungendo

           if (isupper(carattere)){ //CARATTERE MAIUSCOLO
                ++nMaiuscole;
           }if (islower(carattere)){ //CARATTERE MINUSCOLO
               ++nMinuscole;
           }if (isspace(carattere) && carattere!='\n' && carattere!='\t'){ //SPAZIO
               ++nSpazi;
           }if (ispunct(carattere)){ //SEGNO DI PUNTEGGIATURA
               ++nPunteggiatura;
           }if (isdigit(carattere)){ //CIFRA
               ++nNumeri;
           }if (isgraph(carattere)){ //AL CARATTERE CORRISPONDE UN SIMBOLO GRAFICO?
               ++nGrafici;
           }if (isprint(carattere)){ //IL CARATTERE E' STAMPABILE
               ++nStamp;
           }if (iscntrl(carattere)){ //IL CARATTERE E' DI CONTROLLO
               ++nControl;
           }if (isalnum(carattere)){ //IL CARATTERE E' ALPHANUMERICO
               ++nAlNum;
           }if (isalpha(carattere)){ //IL CARATTERE E' ALFABETICO
               ++nAlpha;
           }if (isblank(carattere)){ //IL CARATTERE ESISTE, MA NON E' VISIBILE SULLO SCHERMO
               ++nBlack;
           }
           ++lTesto; //AGGIUNGO UNO ALLA LUNGHEZZA TOTALE DEL TESTO COMPRESO '#', e gli spazi
    }

    //STAMPO TUTTE LE CARATTERISTICHE DEL TESTO
    printf("\n\nLETTERE MAIUSCOLE: %u\n"
           "LETTERE MINUSCOLE: %u\n"
           "SPAZI: %u\n"
           "SEGNI DI PUNTEGGIATURA: %u\n"
           "CIFRE: %u\n"
           "CARATTERI GRAFICI: %u\n"
           "CARATTERI STAMPABILI: %u\n"
           "CARATTERI DI CONTROLLO: %u\n"
           "CARATTERI ALFANUMERI: %u\n"
           "CARATTERI ALFABETICI: %u\n"
           "CARATTERI NON VISIBILI (spazi o tabulazioni): %u\n"
           "LUNGHEZZA TOTALE DEL TESTO: %u\n"
           "Il TESTO ERA: %s\n",nMaiuscole,nMinuscole,nSpazi,nPunteggiatura,nNumeri,nGrafici,nStamp,nControl,
                                            nAlNum,nAlpha,nBlack,lTesto,bufferA);

    //UTILIZZO DELLA FUNZIONE TO UPPER E TO LOWER
    fflush(stdin); //PULISCO LA MEMORIA DI INPUT

    char car;
    char car2;
    printf("\nInserisci una parola in minuscolo, essa verra\' convertita in maiuscolo:");
    scanf("%c",&car);
    fflush(stdin);
    printf("\n\nLETTERA IN MAIUSCOLO: %c",toupper(car));

    printf("\nInserisci una parola in maiuscolo, essa verra\' convertita in minuscolo:");
    scanf("%c",&car2);
    fflush(stdin);
    printf("\n\nLETTERA IN MINUSCOLO: %c",tolower(car2));
    getchar();
    return 0;
}
