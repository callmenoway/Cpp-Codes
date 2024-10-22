#include <iostream>
#include "pila.h"

//costruttore che inizializza la pila con una capacità data
Pila::Pila(int maxCapacita) {
    capacita = maxCapacita;
    scatole = new Scatola*[capacita];
    top = -1; // La pila è inizialmente vuota
}

//distruttore che libera la memoria allocata per la pila
Pila::~Pila() {
    delete[] scatole;
}

//aggiunge una scatola in cima alla pila se non è piena
void Pila::push(Scatola* scatola) {
    if (top < capacita - 1) {
        scatole[++top] = scatola;
        cout << "Scatola inserita nella pila." << endl;
    } else {
        cout << "La pila e' piena." << endl;
    }
}

//rimuove e restituisce la scatola in cima alla pila se non è vuota
Scatola* Pila::pop() {
    if (!isEmpty()) {
        return scatole[top--];
    } else {
        cout << "La pila e' vuota." << endl;
        return nullptr;
    }
}

//verifica se la pila è vuota
bool Pila::isEmpty() const {
    return top == -1;
}

//visualizza i dati della scatola in cima alla pila
void Pila::visualizzaUltima() const {
    if (!isEmpty()) {
        scatole[top]->visualizza();
    } else {
        cout << "La pila e' vuota." << endl;
    }
}
