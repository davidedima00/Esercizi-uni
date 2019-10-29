/*
Author: Davide Di marco
Date: 29/10/2019
Note: Script che gioca a tris
*/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#define RIGHE 3
#define COLONNE 3

int main()
{
    char campo[RIGHE][COLONNE];

    int giocatore=1; /**=1 giocatore 1, =2 giovatore 2**/
    int vincitore=0;
    int cella=0;
    bool libero = true;

    //INIZIALIZZO IL CAMPO
    for (int riga=0;riga<RIGHE;riga++){
            memset(campo[riga],'.',sizeof(campo[riga]));
    }
    //MOSTRO IL CAMPO
    for (int riga=0;riga<RIGHE;riga++){
                for (int colonna=0;colonna<COLONNE;colonna++){
                    printf("| %c |",campo[riga][colonna]);
                }
                printf("\n");
            }

    printf("1 | 2 | 3\n"
           "4 | 5 | 6\n"
           "7 | 8 | 9\n\n");

    while (vincitore==0){ //vincitore=0 non c'è nessun vincitore
            int riga, col;
            while (libero){
                do {
                printf("\nGIOCATORE %d INSERISCI IL NUMERO "
                       "DELLA CASELLA CHE VUOI OCCUPARE(1-9): ",giocatore);
                scanf("%d",&cella);
                fflush(stdin);
                } while( cella <1 || cella>9  );

                //SCELTA RIGA
                if (cella%3==0){
                    riga=(cella/3)-1;
                }else{
                    riga=cella/3;
                }
                //SCELTA COLONNA
                if (cella%3==0){
                    col=2;
                }
                else{
                     col=cella%3-1;
                }
                printf("\nRIGA: %d, COLONNA: %d\n",riga,col);
                printf("%c\n",campo[riga][col]);
                //OTTENGO LA POSIZIONE NELLA MATRICE E LA CARICO CON IL SIMBOLO X, O A SECONDA DEL GIOCATORE
                if (giocatore==1){
                    if (campo[riga][col]=='.'){
                       campo[riga][col]='X';
                       libero=false;
                    }else{
                    printf("LA CASELLA SCELTA E\' GIA\' OCCUPATA DA %c",campo[riga][col]);

                    }

                }else{
                    if (campo[riga][col]=='.'){
                       campo[riga][col]='O';
                       libero=false;
                    }else{
                        printf("LA CASELLA SCELTA E\' GIA\' OCCUPATA");
                    }
                }
        }

            //STAMPO IL CAMPO
             for (int riga=0;riga<RIGHE;riga++){
                for (int colonna=0;colonna<COLONNE;colonna++){
                    printf("| %c |",campo[riga][colonna]);
                }
                printf("\n");
            }
            //fflush(stdin);

            //VERIFICO IL TRIS

             //DIAGONALI
            if ((campo[0][0]=='X' && campo[1][1]=='X' && campo[2][2]=='X') ||
                (campo[0][2]=='X' && campo[1][1]=='X' && campo[2][0]=='X') ||
            //ORIZZONTALE
                (campo[0][0]=='X' && campo[0][1]=='X' && campo[0][2]=='X') ||
                (campo[1][0]=='X' && campo[1][1]=='X' && campo[1][2]=='X') ||
                (campo[2][0]=='X' && campo[2][1]=='X' && campo[2][2]=='X') ||
            //VERTICALE
                (campo[0][0]=='X' && campo[1][0]=='X' && campo[2][0]=='X') ||
                (campo[0][1]=='X' && campo[1][1]=='X' && campo[2][1]=='X') ||
                (campo[0][2]=='X' && campo[1][2]=='X' && campo[2][2]=='X')){
                    vincitore=1;
                    break;
                }
                else if ((campo[0][0]='O' && campo[1][1]=='O' && campo[2][2]=='O') ||
                (campo[0][2]=='O' && campo[1][1]=='O' && campo[2][0]=='O') ||
            //ORIZZONTALE
                (campo[0][0]=='O' && campo[0][1]=='O' && campo[0][2]=='O') ||
                (campo[1][0]=='O' && campo[1][1]=='O' && campo[1][2]=='O') ||
                (campo[2][0]=='O' && campo[2][1]=='O' && campo[2][2]=='O') ||
            //VERTICALE
                (campo[0][0]=='O' && campo[1][0]=='O' && campo[2][0]=='O') ||
                (campo[0][1]=='O' && campo[1][1]=='O' && campo[2][1]=='O') ||
                (campo[0][2]=='O' && campo[1][2]=='O' && campo[2][2]=='O')){
                    vincitore=2;
                    break;
                }

             if (giocatore==1){
                giocatore=2;
                libero=true;
             }else{
             giocatore=1;
             libero=true;
             }

    }
    printf("########################## Il vincitore e\' il giocatore %d  ################################",vincitore);
    getchar();



    return 0;
}
