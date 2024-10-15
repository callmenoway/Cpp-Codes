/********************************************************************************************************************

Alcune librerie e funzioni potrebbero non essere disponibili su tutti i sistemi operativi.
Per problemi di compatibilità su linux e altri IDE, alcune funzioni potrebbero essere commentate.

********************************************************************************************************************/
#ifdef __unix__

    #define OS_Windows 0
    #include <iostream>
    #include <stdlib.h>
    #include <cstdlib>
    #include <cstring>
    #include <unistd.h>
    #include <fstream>

#elif defined(_WIN32) || defined(WIN32)

    #define OS_Windows 1
    #include <iostream>
    #include <windows.h>
    #include <stdlib.h>
    #include <cstdlib>
    #include <cstring>
    #include <unistd.h>
    #include <fstream>

#endif



using namespace std;

//dichiarazione righe x colonne
const int colonne = 39;
const int righe = 25;

//dichiaro due matrici, una per la generazione corrente e una per la nuova generazione
unsigned char matrix[righe][colonne];
unsigned char newMatrix[righe][colonne];

//funzione per pulire la console che posso richiamare quando voglio
void clearConsole() {
    if(OS_Windows)
        system("cls");
    else if(!OS_Windows)
        system("clear");
} 

//funzione per inizializzare la matrice
void inizializza(int colonne, int righe) {
    //inizializzo la matrice con punti
    for (int i = 1; i <= colonne; i++) {
        for (int j = 1; j <= righe; j++) {
            matrix[i][j] = '.';
            matrix[j][i] = '.';
        }
    }
    //lettura da file

    ifstream fileLettura("giocodellavita.txt");
    //caso file non trovato
    if (!fileLettura.is_open()) {
        cerr << "Errore nell'apertura del file!" << endl;
        sleep(10);
        return;
    }

    //lettura coordinate x ed y dal filetxt
    int x, y;
    while (fileLettura >> x >> y) {
        matrix[x][y] = '#';
    }
    fileLettura.close();
}

void vita(int riga, int colonna) {
    int count = 0;

    for (int i = riga - 1; i <= riga + 1; i++) {
        for (int j = colonna - 1; j <= colonna + 1; j++) {
            if (i >= 1 && i <= righe && j >= 1 && j <= colonne && !(i == riga && j == colonna)) {
                if (matrix[i][j] == '#') {
                    count++;
                }
            }
        }
    }

    if (matrix[riga][colonna] == '#') {
        if (count < 2 || count > 3) {
            newMatrix[riga][colonna] = '.';
        } else {
            newMatrix[riga][colonna] = '#';
        }
    } else {
        if (count == 3) {
            newMatrix[riga][colonna] = '#';
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
    inizializza(colonne, righe);

    while (true) {
        printStats();
        verifica(righe, colonne);
        usleep(100000);  //attendo 100 millisecondi tra le generazioni per evitare bug grafici
    }

    return 0;
}