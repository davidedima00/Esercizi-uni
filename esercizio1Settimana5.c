/*
Author: Davide Di Marco | Filippo Venturini | Riccardo Leonelli
Date: 08/12/2019
Note: Gestione corso di laurea
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>


#define NUM_ESAMI 2
#define NUM_STUDENTI 3
#define LENMATRICOLA 5

//DEFINIZIONE DELLE STRUTTURE
 typedef struct studente { //Struttura che contiene i dati dello studente
     int matricola; //Numero Matricola
     int annoImm; //Anno immatricolazione
     char nome[30];
     char cognome[30];
    struct esami {
            int codice; //codice dell'insegnamento lunghezza massima 5
            int voto; //voto = 0 se non sostenuto
        }pianoStudi[NUM_ESAMI];
 }STUDENTE;

 typedef struct {
     int codice; //Codice dell'insegnamento (I CODICI SONO FORMATI DA 5 CIFRE)
     int crediti; //crediti dell'esame
     char descrizione[100]; //Descrizione dell'insegnamento
     char anno; //anno
 }INSEGNAMENTO;

//PROTOTIPI DELLE FUNZIONI
void ottieniInfo(int matricola); //TRAMITE LA MATRICOLA OTTIONE LE INFORMAZIONI DELLA MATRICOLA SELEZIONATA
void aggiungiStudente();
void mediaStudenti();
//VARIABILI GLOBALI
STUDENTE studenti[NUM_STUDENTI];
INSEGNAMENTO insegnamenti[NUM_ESAMI]={{819,12,"Programmazione",1},
                                  {13,12,"Analisi Matematica",1},
                                  //{58414,6,"Algebra e geometria",1},
                                  //{11929,12,"Algoritmi e strutture dati",1},
                                  //{69731,12,"Architettura degli elaboratori",1}
                                  };
int nStudenti=0; //rappresenta il numero di studenti inseriti
//MAIN PROGRAMMA
int main()
{
    int verifica=0;
    int scelta=0;
    bool fine=false;
    while (fine == false){
        printf("Che operazione vuoi effettuare?\nPer AGGIUNGERE UN NUOVO STUDENTE digita '1'\n"
               "Per OTTENERE INFORMAZIONI DI UNO STUDENTE digita '2'\n"
               "Per CONOSCERE LA MEDIA DI TUTTI GLI STUDENTI CHE HANNO COMPLETATO IL CORSO digita '3'\n"
               "Per USCIRE DAL PROGRAMMA digita un numero a scelta");
        scelta=0;
        verifica=0;
        while (verifica==0 || scelta==0){
            printf("\nOperazione: ");
            verifica=scanf("%d",&scelta);
            fflush(stdin);
            if (verifica!=1){
                printf("Valore inserito errato");
                continue;
            }
            if (scelta<1 || scelta>3){
                printf("\nValore inserito errato");
                scelta=0;
                return 0;
            }
            int matricola;
            switch(scelta){
                case 1:
                    aggiungiStudente();
                    break;
                case 2:
                    verifica=0;
                    while (matricola<1 || matricola>99999 || verifica==0){
                        printf("Inserisci il numero di matricola dello studente da cercare: ");
                        verifica=scanf("%d",&matricola);
                        fflush(stdin);
                        if (verifica!=1){
                            printf("\nMATRICOLA INSERITA ERRATA");
                            verifica=0;
                        }
                        if (matricola<1 || matricola>99999){
                            printf("\nLe matricole sono comprese tra 1 e 99999\n");
                        }
                    }
                    ottieniInfo(matricola);
                    break;
                case 3:
                    mediaStudenti();
                case 4:
                    //MODIFICA IL PROFILO DI UNO STUDENTE
                default:
                    return 0;
                    break;
            }
        }
    }
    return 0;
}

void aggiungiStudente(){


    if (nStudenti<=NUM_STUDENTI) {
        int verifica=0;
        int presente=false;
        STUDENTE studente;
        printf("\t Inserisci NOME: ");
        gets(studente.nome);
        printf("\t Inserisci COGNOME: ");
        gets(studente.cognome);
        while (verifica==0 || presente==true){
            printf("\t Inserisci MATRICOLA(MAX 5 CIFRE): ");
            verifica=scanf("%5d",&studente.matricola);
            fflush(stdin);
            int counter=0;
            int numero=studente.matricola;
            while (numero%10!=0){ //FACCIO UN CICLO PER CONTARE IL NUMERO DI CIFRE E VERIFICARE CHE QUESTA SIA FATTA DI 5 MAX 5 CIFRE
                    numero/=10;
                    counter++;0
                    if (counter>LENMATRICOLA-1){
                        verifica=0;
                        printf("\t La matricola deve contenere massimo 5 cifre\n");
                        break;
                    }
            }
            //SE LA MATRICOLA DELLO STUDENTE E' GIà PRESENTE
            for (int i=0;i<NUM_ESAMI;i++){
                if (studenti[i].matricola==studente.matricola){
                    printf("La matricola inserita e' gia' presente");
                    presente=true;
                    break;
                }
            }
        }
        verifica=0;
         while (verifica==0){
            printf("\t Inserisci ANNO IMMATRICOLAZIONE: ");
            verifica=scanf("%4d",&studente.annoImm);
            fflush(stdin);
            if (studente.annoImm<2016 || studente.annoImm>2019 || verifica!=1){
                printf("\nValore inserito errato\n");
                verifica=0;
            }
        }
        //INSERIMENTO PIANO DI STUDI E VOTAZIONI
        printf("Scegli ora 5 esami dal piano di studi del 1 anno: ");
        for (int i=0;i<NUM_ESAMI;i++){ //MOSTRO A VIDEO GLI INSEGNAMENTI ED IL RELATIVO CODICE
            printf("\n\t %d) %-30s | Codice: %d",i+1,insegnamenti[i].descrizione,insegnamenti[i].codice);
        }

        //INSERIMENTO DEI CODICI D'INSEGNAMENTO
        verifica=0;
        int cont = 0; //contatore del while
        int codiceInserito;
        int i; //contatore ciclo for
        int ins_scelto[NUM_ESAMI]; //TRUE DISPONIBILE, FALSE NON DISPONIBILE
        //INIZIALIZZO IL VETTORE a TRUE
        for (int k=0;k<NUM_ESAMI;k++){
                ins_scelto[k]=true;
        }
        while (cont<NUM_ESAMI || verifica==0) {
            printf("\nEsame n. %d\n\tInserisci CODICE INSEGNAMENTO: ",cont+1);
            verifica=scanf("%d",&codiceInserito);
            fflush(stdin);
            if (verifica!=1){
                printf("Codice inserito errato");
                verifica=0;
            }
            for (i=0;i<NUM_ESAMI;i++){
                    if (insegnamenti[i].codice == codiceInserito && ins_scelto[i]==true){ //se esiste il codice inserito dall'utente e non e' già stato scelto
                       break; //esci dal ciclo
                    }
                    if (insegnamenti[i].codice==codiceInserito && ins_scelto[i]==false){
                        printf("Insegnamento gia' selezionato, provane un altro");
                        verifica=0;
                        break;
                    }
                    if (i==NUM_ESAMI-1){//VUOL DIRE CHE NON L'HA TROVATO
                        printf("Codice Inesistente. Inseriscilo nuovamente\n");
                        printf("%d",codiceInserito);
                        verifica=0;
                        break;
                    }
            }
            if (verifica!=0){ //SE IL CODICE QUINDI E' CORRETTO INSERISCO IL VOTO
                int votoInserito=0;
                verifica=0;
                while (verifica==0){
                    printf("\n\tInserisci voto in %s (0 se lo studente non ha sostenuto l'esame): ",insegnamenti[i].descrizione);
                    verifica=scanf("%d",&votoInserito);
                    fflush(stdin);
                    if (verifica!=1){
                        printf("Valore inserito errato\n");
                        verifica=0;
                    }
                    if (votoInserito != 0 && (votoInserito<18 || votoInserito>30)){
                        printf("Voto non valido, devi inserire un voto tra 18 e 30");
                        verifica=0;
                    }
                    else
                    {
                        studente.pianoStudi[cont].voto=votoInserito;
                        studente.pianoStudi[cont].codice=codiceInserito;
                        printf("Posizione studente: %d POSIZIONE NEL PIANO STUDI: %d\n",nStudenti,cont);
                        cont++;
                        ins_scelto[i]=false; //setto a false la possibilita di scegliere la materia
                        break;
                    }
                }
            }
        }
        studenti[nStudenti]=studente;
        nStudenti++;
    }
    else{
        printf ("\nImpossibile aggiungere altri studenti. E' stato raggiunto il numero massimo di studenti");
        return;
    }
}

void ottieniInfo(int matricola){
        for (int i=0;i<nStudenti;i++){
            if (studenti[i].matricola==matricola){ //se trovo lo studente con la matricola ricercata
                printf("\n\nNome: %s \n"
               "Cognome: %s \n"
               "Anno immatricolazione: %d\n"
               "Matricola: %d\n\n",studenti[i].nome,studenti[i].cognome,studenti[i].annoImm,studenti[i].matricola);
               printf("PIANO DI STUDI di %s %s\n\n",studenti[i].nome,studenti[i].cognome);
               for (int k=0;k<NUM_ESAMI;k++){
                    printf("%d)\nCODICE: %d,\nINSEGNAMENTO: %s,\n",k+1,studenti[i].pianoStudi[k].codice,insegnamenti[k].descrizione);
                    if (studenti[i].pianoStudi[k].voto!=0){
                        printf("VOTO: %d\n",studenti[i].pianoStudi[k].voto);
                    }else{
                        printf("VOTO: %s\n","Non sostenuto");
                    }
                     printf("CREDITI: %d\n\n",insegnamenti[k].crediti);
               }
               break;
            }
            else{
                printf("La matricola richiesta non esiste\n");
                break;
            }
    }
}



void mediaStudenti(){
    int sommaCrediti=0; //SOMMA DEI CREDITI TOTALI DEL CORSO
    bool completo=false; //TRUE se lo studente ha completato il piano di studi, FALSE se non lo ha completato
    //INIZIALIZZO LA SOMMA DEI CREDITI CHE SERVIRA PER IL CALCOLO DELLA MEDIA PONDERATA
    for (int t=0;t<NUM_ESAMI;t++){
        sommaCrediti+=insegnamenti[t].crediti;
    }
    int somma;
    int mediaP;
    int i; //contatore del for, che mi serve anche come indice dello studente
    int k; //contatore de
    for (i=0;i<nStudenti;i++){ //per ogni studente
        mediaP=0;
        somma=0;
        for (int k=0;k<NUM_ESAMI;k++){//per ogni insegnamento
            if (studenti[i].pianoStudi[k].voto==0){
                break; //passa allo studente successivo
            }
            if (k==NUM_ESAMI-1){ //lo studente in questione ha completato gli esami del piano di studio
                completo=true;
                break;
            }
        }
        if (completo==true){ //se lo studente ha terminato gli esami del piano di studio allora calcolo la sua media pesata al numero di crediti
            for (int j=0;j<NUM_ESAMI;j++){
                somma+=(studenti[i].pianoStudi[j].voto)*insegnamenti[j].crediti;
            }
        }
        mediaP=somma/sommaCrediti;
        printf("MEDIA PONDERATA DI %s %s: %d",studenti[i].nome, studenti[i].cognome,mediaP);
    }
}



