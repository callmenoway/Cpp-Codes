#include "anfora.h"

// costruttore
Anfora::Anfora(int c, int s) : capacita(c), stato(s) { }

// restituisce la capacità dell'anfora
int Anfora::getCapacita() const {
    return capacita;
}
// restituisce lo stato dell'anfora
int Anfora::getStato() const {
    return stato;
}

// svuota l'anfora
void Anfora::svuota() {
    stato = 0;
}

// riempie l'anfora
void Anfora::riempi() {
    stato = capacita;
}

// svuota l'anfora nell'altra
void Anfora::svuotaNellAltra(Anfora &altra) {
    int spazioDisponibile = altra.getCapacita() - altra.getStato();
    if (stato <= spazioDisponibile) {
        altra.stato += stato;
        stato = 0;
    } else {
        stato -= spazioDisponibile;
        altra.stato = altra.getCapacita();
    }
}

// controlla se l'anfora contiene 4 litri
bool Anfora::CheckAnfora() {
    return stato == 4;
}

// controlla se l'anfora è vuota
bool Anfora::isVuota() const {
    return stato == 0;
}

// controlla se l'anfora è piena
bool Anfora::isPiena() const {
    return stato == capacita;
}