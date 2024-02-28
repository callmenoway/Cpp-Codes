/********************************************************************************************************************

Alcune librerie e funzioni potrebbero non essere disponibili su tutti i sistemi operativi.
Per problemi di compatibilità su linux e altri IDE, la funzione sleep() è stata commentata.

********************************************************************************************************************/

#include <iostream>
#include <stdlib.h>
//#include <Windows.h>
#include <unistd.h>   
#include <cstdlib>

using namespace std;
const int COLONNE=7;
const int RIGHE=6;

unsigned short int matrix[RIGHE][COLONNE];

bool verifyWinner(int player){
    for (int i = 0; i < RIGHE; i++){
        for (int j = 0; j < COLONNE; j++){
            if (matrix[i][j] != 0)
            {
                // Controlla le possibili combinazioni vincenti
                if (j + 3 < COLONNE && matrix[i][j + 1] == matrix[i][j] && matrix[i][j + 2] == matrix[i][j] && matrix[i][j + 3] == matrix[i][j]){
                    return true;
                }
                if (i + 3 < RIGHE && matrix[i + 1][j] == matrix[i][j] && matrix[i + 2][j] == matrix[i][j] && matrix[i + 3][j] == matrix[i][j]){
                    return true;
                }
                if (i + 3 < RIGHE && j + 3 < COLONNE && matrix[i + 1][j + 1] == matrix[i][j] && matrix[i + 2][j + 2] == matrix[i][j] && matrix[i + 3][j + 3] == matrix[i][j]){
                    return true;
                }
                if (i + 3 < RIGHE && j - 3 >= 0 && matrix[i + 1][j - 1] == matrix[i][j] && matrix[i + 2][j - 2] == matrix[i][j] && matrix[i + 3][j - 3] == matrix[i][j]){
                    return true;
                }
            }
        }
    }
    return false;
}

void addGettone(int colonna, int& player, int& turno, bool& repeat, bool& finale){
     for(int i = 6; i >= 1; i--){
        if(matrix[colonna][1] == 1 || matrix[colonna][1] == 2){
            cout << "Colonna piena!" << endl;
            return;
        }
        else if(matrix[colonna][i] == 1 || matrix[colonna][i] == 2){
        }
        else{
            if (player == 0){
                //inserisce il gettone del player 0
                matrix[colonna][i] = 1;
                if(verifyWinner(player) == true){
                    //caso vittoria player 0
                    cout << "HA VINTO IL GIOCATORE " << player << endl;
                    finale = true;
                    repeat = false;
                }
                turno++;
                player = 1;
                return;
            }else if (player == 1){
                //inserisce il gettone del player 1
                matrix[colonna][i] = 2;
                if(verifyWinner(player) == true){
                    //caso vittoria player 1
                    cout << "HA VINTO IL GIOCATORE " << player << endl;
                    finale = true;
                    repeat = false;
                }
                turno++;
                player = 0;
                return;
            }
        }
     }
}

void printStats(int& player, int& turno, int& colonna, bool& repeat, bool& finale){
        //print 4 in row totale
        cout << endl;
        cout << "1   2   3   4   5   6   7" << endl;
        cout << "-------------------------" << endl;
        cout << matrix[1][1] << " | " << matrix[2][1] << " | " << matrix[3][1] << " | " << matrix[4][1] << " | " << matrix[5][1] << " | " << matrix[6][1] << " | " << matrix[7][1]<< endl;
        cout << matrix[1][2] << " | " << matrix[2][2] << " | " << matrix[3][2] << " | " << matrix[4][2] << " | " << matrix[5][2] << " | " << matrix[6][2] << " | " << matrix[7][2]<< endl;
        cout << matrix[1][3] << " | " << matrix[2][3] << " | " << matrix[3][3] << " | " << matrix[4][3] << " | " << matrix[5][3] << " | " << matrix[6][3] << " | " << matrix[7][3]<< endl;
        cout << matrix[1][4] << " | " << matrix[2][4] << " | " << matrix[3][4] << " | " << matrix[4][4] << " | " << matrix[5][4] << " | " << matrix[6][4] << " | " << matrix[7][4]<< endl;
        cout << matrix[1][5] << " | " << matrix[2][5] << " | " << matrix[3][5] << " | " << matrix[4][5] << " | " << matrix[5][5] << " | " << matrix[6][5] << " | " << matrix[7][5]<< endl;
        cout << matrix[1][6] << " | " << matrix[2][6] << " | " << matrix[3][6] << " | " << matrix[4][6] << " | " << matrix[5][6] << " | " << matrix[6][6] << " | " << matrix[7][6]<< endl;
        cout << "-------------------------\n" << endl;
        if (turno == 42){
            //caso in cui le combinazioni siamo 43 dà il pareggio
            cout << "Pareggio!" << endl;
            repeat = false;
        }
        else if (finale == false){
            //in caso che non si è in finale fa inserire una nuova colonna
            cout << "Turno:  " << turno << endl;
            cout << "Player: " << player << endl;
            cout << "Inserire la colonna: ";
        } else if(finale == true){
            finale = false;
            return;
        }

        cin >> colonna;
        //callback funzione per aggiungere il gettone
        return addGettone(colonna, player, turno, repeat, finale);
}

int main()
{
    int player = 0, colonna, turno = 0;
    bool repeat = true;
    bool finale = false;
    do{
        //system("clear");
        printStats(player, turno, colonna, repeat, finale);
    }while(repeat || finale);

    return 0;
}