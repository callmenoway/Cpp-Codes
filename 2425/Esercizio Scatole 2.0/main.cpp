#include <iostream>
#include "scatole.h"
#include "coda.h"
#include "pila.h"

using namespace std;

//funzione di menu per gestire le operazioni disponibili
void menu(Coda &coda, Pila &pila1, Pila &pila2, Pila &pila3) {
    int scelta;
    do {
        cout << "\nMenu:\n";
        cout << "1. Inserisci scatola nella coda\n";
        cout << "2. Sposta scatola dalla coda alla pila\n";
        cout << "3. Estrai scatola da una pila\n";
        cout << "4. Visualizza scatola in coda\n";
        cout << "5. Esci\n";
        cout << "Scelta: ";
        cin >> scelta;

        switch (scelta) {
            case 1: {
                //inserimento di una nuova scatola nella coda
                string codice, descrizione;
                float peso;
                cout << "Inserisci codice: ";
                cin >> codice;
                cout << "Inserisci peso: ";
                cin >> peso;
                cout << "Inserisci descrizione: ";
                cin.ignore();
                getline(cin, descrizione);

                Scatola* scatola = new Scatola(codice, peso, descrizione);
                coda.inserisci(scatola);
                break;
            }
            case 2: {
                //spostamento di una scatola dalla coda a una delle pile
                int numPila;
                cout << "Scegli la pila (1, 2, 3): ";
                cin >> numPila;

                Scatola* scatola = coda.preleva();
                if (scatola != nullptr) {
                    if (numPila == 1) pila1.push(scatola);
                    else if (numPila == 2) pila2.push(scatola);
                    else if (numPila == 3) pila3.push(scatola);
                    else cout << "Pila non valida." << endl;
                }
                break;
            }
            case 3: {
                //estrazione di una scatola da una delle pile
                int numPila;
                cout << "Scegli la pila (1, 2, 3): ";
                cin >> numPila;

                Scatola* scatola = nullptr;
                if (numPila == 1) scatola = pila1.pop();
                else if (numPila == 2) scatola = pila2.pop();
                else if (numPila == 3) scatola = pila3.pop();
                else cout << "Pila non valida." << endl;

                if (scatola != nullptr) {
                    scatola->visualizza();
                    delete scatola; //libera la memoria dopo l'estrazione
                }
                break;
            }
            case 4:
                //visualizzazione della prossima scatola in coda
                coda.visualizzaProssima();
                break;
            case 5:
                cout << "Uscita dal programma.\n";
                break;
            default:
                cout << "Scelta non valida.\n";
        }
    } while (scelta != 5);
}

int main() {
    //creazione della coda e delle pile
    Coda coda(10);
    Pila pila1(10);
    Pila pila2(10);
    Pila pila3(10);

    //avvio del menu per gestire le operazioni
    menu(coda, pila1, pila2, pila3);

    return 0;
}
