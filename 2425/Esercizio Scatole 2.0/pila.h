#ifndef PILA_H
#define PILA_H

#include "scatole.h"
using namespace std;

//classe che rappresenta una pila di scatole
class Pila {
private:
    Scatola** scatole; //array di puntatori a Scatola
    int top; //indice dell'elemento in cima alla pila
    int capacita; //capacità massima della pila

public:
    Pila(int maxCapacita); //costruttore con capacità massima
    ~Pila(); //distruttore per liberare la memoria
    void push(Scatola* scatola); //inserisce una scatola in cima alla pila
    Scatola* pop(); //rstrae una scatola dalla cima della pila
    bool isEmpty() const; //verifica se la pila è vuota
    void visualizzaUltima() const; //visualizza la scatola in cima alla pila
};

#endif