/********************************************************************************************************************

Alcune librerie e funzioni potrebbero non essere disponibili su tutti i sistemi operativi.
Per problemi di compatibilità su linux e altri IDE, alcune funzioni potrebbero essere commentate.

********************************************************************************************************************/
#include <iostream>
#include <stdlib.h>
#include <cstdlib>
#include <cstring>
#include <unistd.h>

using namespace std;

//dichiarazione righe X colonne
const int colonne = 20;
const int righe = 20;

//dichiaro due matrici, una per la generazione corrente e una per la nuova generazione
unsigned char matrix[righe][colonne];
unsigned char newMatrix[righe][colonne];

//funzione per pulire la console che posso richiamare quando voglio
void clearConsole() {
    system("clear");
}

//funzione per inizializzare la matrice
void inizializza(int colonne, int righe) {
    for (int i = 1; i <= colonne; i++) {
        for (int j = 1; j <= righe; j++) {
            matrix[i][j] = '.';
            matrix[j][i] = '.';
        }
    }
    //inizializza con il pattern "Glider"
    matrix[2][3] = 'o';
    matrix[3][4] = 'o';
    matrix[4][2] = 'o';
    matrix[4][3] = 'o';
    matrix[4][4] = 'o';
}

void vita(int riga, int colonna) {
    int count = 0;

    for (int i = riga - 1; i <= riga + 1; i++) {
        for (int j = colonna - 1; j <= colonna + 1; j++) {
            if (i >= 1 && i <= righe && j >= 1 && j <= colonne && !(i == riga && j == colonna)) {
                if (matrix[i][j] == 'o') {
                    count++;
                }
            }
        }
    }

    if (matrix[riga][colonna] == 'o') {
        if (count < 2 || count > 3) {
            newMatrix[riga][colonna] = '.';
        } else {
            newMatrix[riga][colonna] = 'o';
        }
    } else {
        if (count == 3) {
            newMatrix[riga][colonna] = 'o';
        } else {
            newMatrix[riga][colonna] = '.';
        }
    }
}

//funzione per stampare la matrice in console
void printStats() {
    clearConsole();
    cout << endl;
    for (int i = 1; i <= righe; i++) {
        for (int j = 1; j <= colonne; j++) {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
}

//verifica le celle che devono morire o sopravvivere
void verifica(int righe, int colonne) {
    for (int i = 1; i <= righe; i++) {
        for (int j = 1; j <= colonne; j++) {
            vita(i, j);
        }
    }

    //aggiorna la matrice principale con la nuova generazione
    for (int i = 1; i <= righe; i++) {
        for (int j = 1; j <= colonne; j++) {
            matrix[i][j] = newMatrix[i][j];
        }
    }
}

int main() {
    srand(time(NULL));
    inizializza(colonne, righe);

    while (true) {
        printStats();
        verifica(righe, colonne);
        usleep(100000);  //attendi 100 millisecondi tra le generazioni
    }

    return 0;
}