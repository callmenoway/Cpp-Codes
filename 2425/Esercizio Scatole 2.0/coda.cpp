#include <iostream>
#include "coda.h"

//costruttore che inizializza la coda con una capacità data
Coda::Coda(int maxCapacita) {
    capacita = maxCapacita;
    scatole = new Scatola*[capacita];
    testa = 0;
    coda = 0;
}

//distruttore che libera la memoria allocata per la coda
Coda::~Coda() {
    delete[] scatole;
}

//inserisce una scatola nella coda se non è piena
void Coda::inserisci(Scatola* scatola) {
    if ((coda + 1) % capacita != testa) {
        scatole[coda] = scatola;
        coda = (coda + 1) % capacita; // Aggiorna la coda in modo circolare
        cout << "Scatola inserita nella coda." << endl;
    } else {
        cout << "La coda e' piena, non e' possibile inserire altre scatole." << endl;
    }
}

//preleva una scatola dalla testa della coda se non è vuota
Scatola* Coda::preleva() {
    if (!isEmpty()) {
        Scatola* scatola = scatole[testa];
        testa = (testa + 1) % capacita; // Aggiorna la testa in modo circolare
        return scatola;
    } else {
        cout << "La coda e' vuota." << endl;
        return nullptr;
    }
}

//verifica se la coda è vuota
bool Coda::isEmpty() const {
    return testa == coda;
}

//visualizza i dati della scatola in testa alla coda
void Coda::visualizzaProssima() const {
    if (!isEmpty()) {
        scatole[testa]->visualizza();
    } else {
        cout << "La coda e' vuota." << endl;
    }
}
