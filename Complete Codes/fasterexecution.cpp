/********************************************************************************************************************

Alcune librerie e funzioni potrebbero non essere disponibili su tutti i sistemi operativi.
Per problemi di compatibilità su linux e altri IDE, alcune funzioni potrebbero essere commentate.

********************************************************************************************************************/
#include <iostream>
#include <cstdlib>
#include <chrono>

using namespace std;
using namespace std::chrono;

//funzione input numero iniziale
void inputnumero(long long& N){
    cout << "Inserire un numero: ";
    cin >> N;
    return;
}

//funzione calcola somma con ciclo FOR
void calcolaSommaFor(long long N){
    long long temp = 0; //numero maggiore
    auto start = high_resolution_clock::now(); //start cronometro
    for(int i = 1; i <=N; i++){ //ciclo for per calcolare la somma
        temp = temp + i;
    }
    auto stop = high_resolution_clock::now(); //stop cronometro
    auto duration = duration_cast<microseconds>(stop - start);  //calcolo tempo di esecuzione
     
    cout << "Tempo di esecuzione ciclo FOR: " << duration.count() << " microsecondi" << endl; //stampa tempo di esecuzione
    //cout << temp << endl;
}

//funzione calcola somma con formula
void calcolaSommaFormula(long long N){
    long long temp = 0; //numero maggiore
    auto start = high_resolution_clock::now(); //start cronometro
    temp = (N*(N + 1))/2; //formula per calcolare la somma
    auto stop = high_resolution_clock::now(); //stop cronometro
    auto duration = duration_cast<microseconds>(stop - start); //calcolo tempo di esecuzione
     
    cout << "Tempo di esecuzione FORMULA: " << duration.count() << " microsecondi" << endl; //stampa tempo di esecuzione
    //cout << temp << endl;
}

int main() {
    long long N; //numero
    inputnumero(N); //chiamata funzione inputnumero
    calcolaSommaFor(N); //chiamata funzione calcolaSommaFor
    calcolaSommaFormula(N); //chiamata funzione calcolaSommaFormula
    return 0;
}