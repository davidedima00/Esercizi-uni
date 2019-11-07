/*                                                                                     *
Author: Davide Di Marco                                                                *
Date (DeadLine): 10/10/2019                                                            *
Note: 2 versioni per la ricerca di una sottostringa in una stringa principale.         *
      La prima versione è implementata senza l'utilizzo della libreria string.h        *
      La seconda versione è implementata con l'utilizzo della libreria string.h        *
                                                                                       *
***************************************************************************************/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#define MAX 30 //MAX è la lunghezza massima della stringa


int main(){
/**VERSIONE SENZA UTILIZZO DELLA LIBRERIA STRING.H**/
    char s1[MAX+1]={'\0'}; //Vettore per la prima stringa
    char s2[MAX+1]={'\0'}; //Vettore per la seconda stringa
    //char stringaVuota[30]={'\0'};
     //STRINGA CONTENENTE IL TESTO DELLA VERIFICA
    char nS[MAX+1]={'\0'}; //STRINGA CREATA SOSTITUITA CON GLI '*'
    char carattere; //Carattere corrente utilizzato durante lo scorrimento del vettore carattere per carattere

    int dim1=0;//Lunghezza stringa s1
    int dim2=0; //Lunghezza stringa s2
    int index=0; //Indice del while

    int verifica; //Variabile per la verifica dello scanf

	//Ciclo per l'inserimento della stringa1
    do{
        //Se la prima stringa è troppo lunga
        if (dim1>MAX){
        printf("\nERRORE: STRINGA TROPPO LUNGA\n");
        }
        printf("INSERISCI STRINGA: ");
        verifica=scanf("%s",s1); //Memorizzazione
        if (verifica!=1){
            printf("\nValore inserito errato\n");
            continue;
        }
        fflush(stdin); //Pulizia del buffer

        dim1=0; //Variabile per la verifica della dimensione della prima parola
        index=0; //Indice per lo scorrimento della prima stringa
        while (s1[index]!='\0'){ //Fino al terminatore
            dim1+=1; //Incrementa la variabile di controllo
            if (dim1>30){ //Stringa troppo lunga
                break;
            }
            index++; //Incrementa l'indice di scorrimento
        }
    }while (dim1>MAX); //Continua il ciclo fino a quando la dimensione non supera il massimo

	//Ciclo per l'inserimento della stringa2
    do{
        if (dim2>30){
            printf("ERRORE: STRINGA TROPPO LUNGA\n");
        }
        printf("INSERISCI OCCORRENZA DA RICERCARE: ");
        verifica=scanf("%s",s2);
        if (verifica!=1){
            printf("\nValore inserito errato\n");
            continue;
        }
        fflush(stdin);
        printf("\n");
        dim2=0;
        index=0;
        while (s2[index]!='\0'){
            dim2+=1;
            index++;
        }
    }while (dim2>30);

	//VERIFICA LUNGHEZZA DELLE STRINGHE, LA STRINGA 2 DEVE ESSERE NECESSARIAMENTE PIU' CORTA DELLA STRINGA 1
    if (dim2>dim1){
            printf("LA STRINGA 2 E' PIU\' LUNGA DELLA STRINGA 1");
            exit(1);
    }
	//RICERCA DELLE OCCORRENZE
    printf("RICERCO LE OCCORRENZE DI \'%s\' NELLA STRINGA \'%s\' e le sostituisco con \'*\'\n",s2,s1);
    int index1=0; //indice della nuova stringa
    int index2=0; //indice stringa2
    int dimSv=0; //lunghezza della stringa di verifica
    bool occor=false;
    printf("\n\t\t\tCODICE SENZA UTILIZZARE FUNZIONI DI STRING.H\n");
    for (int index=0;index<=dim1;index++){ //CICLO PER OGNI LETTERA DELLA STRIG
        carattere=s1[index];
        if (carattere==s2[index2]){

                if (carattere=='*' && index==dim1-1){
                        nS[index1]='*';
                        index1++;
                    }
            //stringaVuota[index2]=carattere;
            index2++;
            dimSv++;
            if (dimSv==dim2){

                nS[index1]='*';
                index1++;
                dimSv=0;
                index2=0;
                /*for (int k=0;k<30;k++){
                    stringaVuota[k]='\0';
                }*/
                occor=true;
            }
        }
        else{
            nS[index1]=carattere;
            index1++;
        }
    }
    if (occor==false){ //LA STRINGA TEMPORANEA E' VUOTA QUINDI NON CI SONO OCCORRENZE
        printf("\n\n\tNON CI SONO OCCORRENZE");
    }else{
        printf("\nNUOVA STRINGA: %s\n",nS);
    }

/***************************************** VERSIONE CON L'UTILIZZO DELLA LIBRERIA STRING.H ***********************************************************/

    printf("\n\t\t\tCODICE UTILIZZANDO FUNZIONI DI STRING.H\n");
    occor=true;
    char *returnStrstr; //Puntatore per memorizzare l'indirizzo restituito da strstr
	char tmpString[MAX + 1]; //Array temporaneo
	int sostituzioni=0;//conta le sostituzioni avvenute nella stringa
	do {
		returnStrstr = strstr(s1, s2); //Trova la prima occorrenza della seconda parola
		if (returnStrstr == NULL){ //Se non la trova esce dal ciclo
            occor=false;
			continue;
		}
		memset(tmpString, '\0', MAX + 1); //Resetta tmp
		memmove(tmpString, s1, returnStrstr - s1); //Inserisco i caratteri saltati da strstr che si trovano prima dell'occorrenza
		strcat(tmpString, "*"); //Inserisco l'asterisco al posto dell'occorrenza
		strcat(tmpString, returnStrstr + dim2); //Aggiungo al vettore temporaneo tutti i caratteri della stringa saltando quelli dell'occorrenza
		memmove(s1, tmpString, dim1); //S1 acquisiace tutti i caratteri tmp compreso * dell'occorrenza sostituita
		sostituzioni++;
	} while (returnStrstr != NULL); //Continua fintanto che strstr non trova più occorrenze
    if (occor==true || sostituzioni!=0){
        printf("\nNUOVA STRINGA: %s", tmpString); //Print del risultato
    }else{
        printf("\n\tNON CI SONO OCCORRENZE");
    }
	getchar();
    return 0;
}
