/*Author; Davide Di Marco | Riccardo Leonelli | Filippo Venturini
Data(DeadLine): 24/11/2019
Note: Trovare numeri primi
*/
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int main()
{
    int verifica=0;
    int max=1;
    int dim=10; //dimensione iniziale del vettore
    unsigned int* arrayPrimi= (unsigned int*)malloc(dim*sizeof(unsigned int)); //alloco memoria per i primi dim numeri primi
    if (arrayPrimi==NULL){ //se arrayPrimi ritorna NULL vuol dire che non c'è spazio in memoria per allocare il vettore
        printf("Spazio in memoria insufficiente");
    }
    //chiedo all'utente di inserire il valore massimo
    while (max<=1 || max>10000){
        printf("Inserisci fino a che valore vuoi trovare i numeri primi(MIN. 2 - MAX. 10'000): ");
        verifica=scanf("%d",&max);
        if (verifica!=1){ //verifico il valore di ritorno della scanf
            printf("\nValore inserito errato, chiusura programma\n");
            return 0;
        }
        fflush(stdin);
        //verifico se il valore entra nel range permesso
        if (max<2){
            printf("Inserisci un numero maggiore di 1\n");
        }else if (max>=10000){
            printf("Inserisci un numero minore o uguale a 10'000\n");
        }
    }
    //trovo i numeri primi fino al valore definito dall'utente
    bool primo=false;
    int nPrimi=0; //conta i numeri primi trovati
    for (int n=2;n<=max;n++){ //per ogni numero
            if (n==2){ //se n=1 allora è primo
                *(arrayPrimi)=n; //lo aaggiungo all'array di numeri primi
            }else{ //altrimenti
                for (int divisore=2;divisore<n;divisore++){ //per ogni divisore, con i divisori che vanno fino alla metà del numero
                    if (n%divisore==0){ //se è divisibile allora non è primo
                        primo=false;
                        break;//finisco il ciclo e verifico il numero successivo
                    }else { //allora il numero è primo
                        primo=true;
                    }
                }
                if (primo){ //se e' primo
                    nPrimi++; //incremento di 1 il contatore dei numeri primi
                    if (nPrimi>=dim){ //se i numeri primi sono maggiori dello spazio di allocazione creato per il vettore
                        dim*=2; //raddoppio la dimensione del vettore allocato
                        arrayPrimi=(unsigned int*)realloc(arrayPrimi,dim*sizeof(unsigned int)); //rialloco il doppio dello spazio del vettore
                    }
                   *(arrayPrimi+nPrimi)=n; //aggiungo il numero nell'array di numeri primi
                }
            }
    }
    for (int index=0;index<=nPrimi;index++){
            printf("%d%c",*(arrayPrimi+index), index==nPrimi ? ' ': '-'); //printo i numeri primi
    }
    free(arrayPrimi); //libero lo spazio in memoria allocato da arrayPrimi
    getchar();
    return 0;
}
