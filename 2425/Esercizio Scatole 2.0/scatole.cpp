#include "scatole.h"

//inizializza una scatola con i parametri forniti
Scatola::Scatola(string c, float p, string d) : codice(c), peso(p), descrizione(d) {}

//restituisce il codice della scatola
string Scatola::getCodice() const {
    return codice;
}

//restituisce il peso della scatola
float Scatola::getPeso() const {
    return peso;
}

//restituisce la descrizione della scatola
string Scatola::getDescrizione() const {
    return descrizione;
}

//visualizza i dati della scatola
void Scatola::visualizza() const {
    cout << "Codice: " << codice << ", Peso: " << peso << " kg, Descrizione: " << descrizione << endl;
}