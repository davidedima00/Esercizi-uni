/*Author; Davide Di Marco | Riccardo Leonelli | Filippo Venturini
Data(DeadLine):
Note:


*/


#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int main()
{
    int verifica=0;
    int max=1;
    int dim=30; //dimensione iniziale del vettore
    int* arrayPrimi= (int*)malloc(dim*sizeof(int)); //alloco memoria per i primi 30 numeri primi
    if (arrayPrimi==NULL){ //se arrayPrimi ritorna NULL vuol dire che non c'è spazio in memoria per allocare il vettore
        printf("Spazio in memoria insufficiente");
    }

    while (max<=1){
        printf("Inserisci fino a che valore vuoi trovare i numeri primi: ");
        verifica=scanf("%d",&max);
        if (verifica!=1){
            printf("\nValore inserito errato");
        }
        if (max<=1){
            printf("Inserisci un numero maggiore di 1\n");
        }
    }
    //trovo i numeri primi fino al valore definito dall'utente
    bool primo=false;
    int nPrimi=0; //conta i numeri primi trovati

    for (int n=2;n<=max;n++){ //per ogni numero
            if (n==2){ //se n=1 allora è primo
                *(arrayPrimi)=n;

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
                    if (nPrimi>dim){ //se i numeri primi sono maggiori dello spazio di allocazione creato per il vettore
                        arrayPrimi=(int*)realloc(arrayPrimi,nPrimi*sizeof(int)); //rialloco di 1 lo spazio del vettore
                    }
                   *(arrayPrimi+nPrimi)=n;
                }
            }
    }

    for (int index=0;index<nPrimi;index++){
            printf("%d%c",*(arrayPrimi+index), index==nPrimi-1 ? ' ': '-');
    }

    printf("\nSpazio allocato per l'array di primi: %d bytes",sizeof(arrayPrimi)*nPrimi);
    free(arrayPrimi);
    getchar();
    return 0;
}
