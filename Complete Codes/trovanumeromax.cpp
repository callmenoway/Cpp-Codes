/********************************************************************************************************************
12/04/2024
Alcune librerie e funzioni potrebbero non essere disponibili su tutti i sistemi operativi.
Per problemi di compatibilità su linux e altri IDE, alcune funzioni potrebbero essere commentate.

********************************************************************************************************************/
#include <iostream>
#include <cstdlib>
#include <chrono>

using namespace std;
using namespace std::chrono;

const int MAX = 100; //numero di elementi dell'array

void trovaMassimoFor(long long array[]) {
    long long temp = 0; //numero maggiore
    auto start = high_resolution_clock::now(); //start cronometro
    for (int i = 0; i < 20; i++) { //ciclo for per trovare il numero maggiore
        if (array[i] > temp) {
            temp = array[i];
        }
    }
    auto stop = high_resolution_clock::now(); //stop cronometro
    auto duration = duration_cast<microseconds>(stop - start); //calcolo tempo di esecuzione

    cout << "Tempo di esecuzione ciclo FOR: " << duration.count() << " microsecondi" << endl;
    //cout << "numero maggiore: " << temp << endl;
}

void trovaMassimoSort(long long array[]) {
    long long temp = 0; //numero maggiore
    auto start = high_resolution_clock::now(); //start cronometro
    for (int i = 0; i < MAX; i++) { //ciclo for per ordinare l'array (bubblesort)
        for (int j = 0; j < MAX - 1; j++) {
            if (array[j] > array[j + 1]) {
                temp = array[j];
                array[j] = array[j + 1];
                array[j + 1] = temp;
                temp = array[j];
                array[j] = array[j + 1];
                array[j + 1] = temp;
            }
        }
    }
    auto stop = high_resolution_clock::now(); //stop cronometro
    auto duration = duration_cast<microseconds>(stop - start); //calcolo tempo di esecuzione

    cout << "Tempo di esecuzione SORT: " << duration.count() << " microsecondi" << endl; //stampa tempo di esecuzione
    //cout << "numero maggiore: " << array[0] << endl;
}

int main() {
    srand((unsigned) time(NULL)); //inizializzazione del generatore di numeri casuali
    long long array[MAX]; //dichiarazione array
    for(int i = 0; i < MAX; i++){ //ciclo for per riempire l'array con numeri casuali
        array[i] = (rand() % 1000 + 1); // Genera numeri casuali da 0 a 1000
    }
    trovaMassimoFor(array); //chiamata funzione trovaMassimoFor
    trovaMassimoSort(array);  //chiamata funzione trovaMassimoSort
    return 0; //ritorno del valore 0
}