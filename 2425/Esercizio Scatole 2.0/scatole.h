#ifndef SCATOLE_H
#define SCATOLE_H

#include <iostream>
#include <string>
using namespace std;

//classe che rappresenta una scatola con codice, peso e descrizione
class Scatola {
private:
    string codice;
    float peso;
    string descrizione;

public:
    Scatola(string c, float p, string d); //costruttore
    string getCodice() const; //restituisce il codice della scatola
    float getPeso() const; //restituisce il peso della scatola
    string getDescrizione() const; //restituisce la descrizione della scatola
    void visualizza() const; //visualizza i dati della scatola
};

#endif