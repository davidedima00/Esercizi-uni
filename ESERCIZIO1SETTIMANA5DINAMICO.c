//Author: Filippo Venturini | Davide Di marco | Riccardo Leonelli
//Date(DeadLine): 20191208
//Notes: Esercizio 1
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#define MAX_STUDENTI 50
#define NUM_ESAMI 5
#define MAX_INSEGNAMENTI 10
//Prototipi delle funzioni
bool AggiungiStudente();
void StampaInfo(int);
void ModificaPianoStudi(int);
void Media();

int contStudenti = 0; //Variabile globale che memorizza il numero di studenti presenti
int verificaScanf = 0; //Variabile globale per la verifica di tutti gli scanf
int dim=10; //dimensione iniziale studenti

typedef struct Studente
{
	int numMatricola;
	char nome[10];
	char cognome[10];
	int annoImmatricolazione;

	struct VotiEsami {
		int codice;
		int voto;
	}piano_di_studi [NUM_ESAMI];

}STUDENTE;

STUDENTE *studenti=NULL;
struct Insegnamento {
	int codice;
	char descrizione[100];
	int anno;
	int crediti;
} insegnamenti[MAX_INSEGNAMENTI]={{819,"Programmazione",1,12},
                  {13,"Analisi",1,12},
                  {58414,"Algebra e Geometria",1,6},
                  {26338,"Inglese B1",1,6},
                  {69731,"Architettura degli elaboratori",1,12},
                  {70212,"Programmazione ad oggetti",2,12},
                  {8574,"Sistemi Operativi",2,12},
                  {405,"Fisica",2,6},
                  {10906,"Basi Di Dati",1,12},
                  {66736,"Metodi Numerici",2,6},
                };;


//Funzione per l'aggiunta di uno studente

bool AggiungiStudente(){
    if (contStudenti==MAX_STUDENTI){
        printf("Impossibile aggiungere nuovi studenti poiche' e' stato raggiunto il numero massimo di studenti registrati");
        return false;
    }

	if (contStudenti%10==0){ //verifico se il contStudenti è divisibile per 10
        dim*=2; //se lo è, raddoppio la dimensione allocata dal vettore
        studenti=(STUDENTE*) realloc(studenti,dim); 
        if (studenti==NULL){ //se l'allocazione fallisce
            printf("Memoria insufficiente per allocare lo spazio del vettore");
            free(studenti); //chiudo l'esecuzione
            return false;
        }

	}
	printf("-------------------------\n");
	printf("AGGIUNGERE STUDENTE :\n");
	int matricolaInserita = 0;
	bool presente; //Booleano per la verifica
	do {
		presente = false;
		printf("\n\tInserisci il numero di matricola: ");
		verificaScanf = scanf("%d", &matricolaInserita);
		while ((getchar()) != '\n'); //Pulizia del buffer

		for (int i = 0; i < contStudenti; i++) { //Ciclo di per controllare che lo studente non sia già presente
			if (studenti[i].numMatricola == matricolaInserita) {
				presente = true;
				printf("\t\tLo studente e' gia' presente!");
				break; //Esce dal ciclo
			}
		}
	} while (verificaScanf != 1 || presente);

	studenti[contStudenti].numMatricola = matricolaInserita; //Assegna il numero di matricola allo studente

	do {
		verificaScanf = 0;
		printf("\tInserire il nome: ");
		verificaScanf = scanf("%s", studenti[contStudenti].nome);
		while ((getchar()) != '\n'); //Pulizia del buffer
	} while (verificaScanf != 1);

	do {
		verificaScanf = 0;
		printf("\tInserire il cognome: ");
		verificaScanf = scanf("%s", studenti[contStudenti].cognome);
		while ((getchar()) != '\n'); //Pulizia del buffer
	} while (verificaScanf != 1);

	int annoInserito = 0;
	do {
		verificaScanf = 0;
		printf("\tInserire l'anno di immatricolazione [1900-2019]: ");
		verificaScanf = scanf("%d", &(annoInserito));
		while ((getchar()) != '\n'); //Pulizia del buffer
	}while(verificaScanf != 1 || annoInserito < 1900 || annoInserito > 2019); //Controlla che l'anno sia inserito entro un range
	studenti[contStudenti].annoImmatricolazione = annoInserito; //Inserimento dell'anno

	printf("\tSeleziona 5 esami per il piano di studi, tra quelli disponibili.\n"); //Output di presentazione di tutti gli insegnamenti disponibili

	for (int k = 0; k < MAX_INSEGNAMENTI; k++) {
		printf("\t%d) %s.\n", insegnamenti[k].codice, insegnamenti[k].descrizione);
	}


	int codiceInserito = 0;
	bool codCorretto; //Variabile per verificare il codice
	for (int j = 0; j < NUM_ESAMI; j++) {
		do {
			codCorretto = false;
			verificaScanf = 0;
			printf("\tDigita il codice dell'esame %d:", j + 1);
			verificaScanf = scanf("%d", &codiceInserito); //Inserisce il codice dentro all'elemento j-esimo del piano di studi
			while ((getchar()) != '\n'); //Pulizia del buffer
			for (int t = 0; t < MAX_INSEGNAMENTI; t++) { //Ciclo che controlla che il codice dell'insegnamento esista
				if (insegnamenti[t].codice == codiceInserito) {
					codCorretto = true;
					break;
				}

			}
			if (codCorretto==false){
                printf("Codice inesistente\n");
			}
		} while (verificaScanf != 1 || codCorretto == false);
		studenti[contStudenti].piano_di_studi[j].codice = codiceInserito; //Assegna il codice dell'esame al piano di studi dello studente
		studenti[contStudenti].piano_di_studi[j].voto =0; //imposto a 0 l'esame ovvero non sostenuto
	}

	contStudenti++; //Incremente il contatore di inserimento
	return true;
}

//Funzione per stampare le informazioni relative ad uno studente
void StampaInfo(int matricola) {
	printf("-------------------------\n");
	printf("STAMPARE INFORMAZIONI:\n");
	for (int i = 0; i < MAX_STUDENTI; i++) { //Ciclo per trovare lo studente corrispondente
		if (studenti[i].numMatricola == matricola) {
			printf("\tNumero matricola: %d\n", studenti[i].numMatricola);
			printf("\tNome: %s\n", studenti[i].nome);
			printf("\tCognome: %s\n", studenti[i].cognome);
			printf("\tAnno di immatricolazione: %d\n", studenti[i].annoImmatricolazione);
			printf("\tPIANO DI STUDI:\n");
			for (int j = 0; j < NUM_ESAMI; j++){
				printf("\t\tCodice Esame: %d", studenti[i].piano_di_studi[j].codice);
                if (studenti[i].piano_di_studi[j].voto==0){ //se il voto e' uguale a 0 allora vuol dire che lo studente non ha sostenuto l'esame
                    printf("|Voto: %s|\n","Non sostenuto");
                }else{
                    printf("|Voto: %d|\n",studenti[i].piano_di_studi[j].voto);
                }
			}
			return; //Esce dalla funzione
		}
	}
	printf("\t__MATRICOLA NON PRESENTE__\n");
	return;
}

//Funzione per la modifica del piano di studi
void ModificaPianoStudi(int matricola) {
	printf("-------------------------\n");
	printf("MODIFICARE IL PIANO DI STUDI:\n");
	int codiceInserito = 0; //Variabile per il codice dell'esame
	int votoInserito = 0; //Variabile per il voto
	for (int i = 0; i < MAX_STUDENTI; i++) { //Ciclo per trovare lo studente corrispondente
		if (studenti[i].numMatricola == matricola) {
			StampaInfo(matricola); //Visualizza i dati relativi alla matricola di cui si vuole modificare il piano di studi
			do {
				verificaScanf = 0;
				printf("Codice dell'esame: ");
				verificaScanf = scanf("%d", &codiceInserito);
				while ((getchar()) != '\n'); //Pulizia del buffer
			} while (verificaScanf != 1);

			for (int k = 0; k < NUM_ESAMI; k++){
				if (studenti[i].piano_di_studi[k].codice == codiceInserito) {
					do {
						verificaScanf = 0;
						verificaScanf = printf("\tInserire il voto (31 per la lode): ");
						verificaScanf = scanf("%d", &votoInserito); //Inserisce il voto
						while ((getchar()) != '\n'); //Pulizia del buffer

						if (votoInserito < 18 || votoInserito > 31) {
							printf("\t\tVoto inserito errato!\n");
						}
					} while (verificaScanf != 1 || votoInserito < 18 || votoInserito > 31);

					studenti[i].piano_di_studi[k].voto = votoInserito; //Inserisce il voto
					printf("\t\tVOTO INSERITO.\n");
					return;//Esce dalla funzione perchè la valutazione è stata modificata
				}
			    if (k == NUM_ESAMI - 1) {
					printf("\tNon e' presente l'esame indicato."); //In caso l'esame indicato non sia presente
				}
			}
		}
	}
	printf("\t__MATRICOLA NON PRESENTE__\n");
	return;
}
//Funzione per calcolare la media degli studenti
void Media() {
	printf("-------------------------\n");
	printf("CALCOLARE LA MEDIA DEI VOTI:\n");
	if (contStudenti == 0) { //Controlla che la struttura non sia vuota
		printf("\tNon sono presenti studenti!\n");
		return; //Esce dalla funzione
	}
	int sommaTotale; //Variabile per la somma pesata totale
	int sommaCrediti; //Somma di tutti i crediti
	int creditiEsame;
	bool completo;
	for (int i = 0; i < contStudenti; i++) {
		sommaTotale = 0;
	    sommaCrediti = 0;
		completo = true;
		for (int k = 0; k < NUM_ESAMI && completo == true; k++) {
			if (studenti[i].piano_di_studi[k].voto == 0) {
				completo = false; //Esce dal ciclo perchè lo studente non ha completato tutti gli esami
			}
			else {
				creditiEsame = 0;//Setta i crediti del singolo esame a 0
				for (int j = 0; j < MAX_INSEGNAMENTI; j++) { //Scorre tutti gli insegnamenti
					if (studenti[i].piano_di_studi[k].codice == insegnamenti[j].codice) {
						creditiEsame = insegnamenti[j].crediti; //Memorizza in una variabile i crediti corrispondenti all'insegnamento
						sommaCrediti += creditiEsame; //Aggiunge i crediti alla somma dei pesi
						break; //Esce dal ciclo
					}
				}
				sommaTotale += studenti[i].piano_di_studi[k].voto*creditiEsame; //Aggiunge alla somma totale il valore pesato del singolo esame
			}
		}
		if (completo) {
			printf("\tNome: %s |Cognome: %s |Media:%d\n",studenti[i].nome, studenti[i].cognome, sommaTotale / sommaCrediti); //Calcola la media del singolo studente
		}
		else {
			printf("\tNome: %s |Cognome: %s |\n\t\tPIANO DI STUDI NON COMPLETO!\n", studenti[i].nome, studenti[i].cognome); //In caso lo studente non abbia svolto tutti gli esami
		}
	}
}
int main() {
    studenti=(STUDENTE*) malloc(dim*sizeof(STUDENTE)); //alloco spazio per gli studenti
    if (studenti==NULL){
        printf("Memoria insufficiente per allocare lo spazio del vettore");
        return 0; //chiudo l'esecuzione
    }
	do {
		int opzioneScelta = 0; //Memorizza l'opzione da effetturare
		int matricolaInserita = 0; //Memorizza la matricola inserita
		do {
			verificaScanf = 0;
			printf("-------------------------\n");
			printf("|AGGIUNGERE STUDENTE : 1|\n|STAMPARE INFORMAZIONI: 2|\n|MODIFICARE IL PIANO DI STUDI: 3|\n|CALCOLARE LA MEDIA DEI VOTI: 4|\n|USCIRE: 5| ");
			printf("\nOpzione desiderata: ");
			verificaScanf = scanf("%d", &opzioneScelta);
			while ((getchar()) != '\n'); //Pulizia del buffer
		} while (verificaScanf != 1);

		if (opzioneScelta == 5) //Esce dal ciclo
			return 0;
		switch (opzioneScelta) { //Switch per le varie casistiche
		case 1:
			if (!AggiungiStudente()){
                return 0;
			}
			break;
		case 2:
			do {
				verificaScanf = 0;
				printf("\tMatricola: ");
				verificaScanf = scanf("%d", &matricolaInserita);
				while ((getchar()) != '\n'); //Pulizia del buffer
			} while (verificaScanf != 1);

			StampaInfo(matricolaInserita); //Invoca la funzione per la stampa delle info
			break;
		case 3:
			do {
				verificaScanf = 0;
				printf("\tMatricola: ");
				verificaScanf = scanf("%d", &matricolaInserita);
				while ((getchar()) != '\n'); //Pulizia del buffer
			} while (verificaScanf != 1);
			ModificaPianoStudi(matricolaInserita); //Invoca la funzione per la modifica del piano di studi
			break;
		case 4:
			Media(); //Invoca la funzione per la media
			break;
		}
	} while (true);
    free(studenti);
	getchar();
	return 0;
}

