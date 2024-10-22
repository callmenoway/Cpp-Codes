#ifndef CODA_H
#define CODA_H

#include "scatole.h"
using namespace std;

//classe che rappresenta una coda circolare di scatole
class Coda {
private:
    Scatola** scatole; //array di puntatori a Scatola
    int testa; //indice di testa della coda
    int coda;  //indice di coda della coda
    int capacita; //capacità massima della coda

public:
    Coda(int maxCapacita); //costruttore con capacità massima
    ~Coda(); //distruttore per liberare la memoria
    void inserisci(Scatola* scatola); //inserisce una scatola in coda
    Scatola* preleva(); //preleva una scatola dalla testa della coda
    bool isEmpty() const; //verifica se la coda è vuota
    void visualizzaProssima() const; //visualizza la scatola in testa alla coda
};

#endif