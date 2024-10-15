#include <iostream>
#include "anfora.h"

using namespace std;

// funzione per svuotare completamente un'anfora
void svuotareAnfora(Anfora &anfora) {
    anfora.svuota();
    cout << "Anfora svuotata completamente." << endl;
}

// funzione per riempire completamente un'anfora
void riempireAnfora(Anfora &anfora) {
    anfora.riempi();
    cout << "Anfora riempita completamente." << endl;
}

// funzione per svuotare un'anfora nell'altra
void svuotareNellAltra(Anfora &anfora1, Anfora &anfora2) {
    anfora1.svuotaNellAltra(anfora2);
    cout << "Anfora svuotata nell\'altra anfora." << endl;
}

// funzione per sapere lo stato dell'anfora
void statoAnfora(const Anfora &anfora) {
    cout << "Stato dell\'anfora: " << anfora.getStato() << " litri." << endl;
}

// funzione per sapere se un'anfora sia vuota o piena
void vuotaOPiena(const Anfora &anfora) {
    if (anfora.isVuota()) {
        cout << "L'anfora e\' vuota." << endl;
    } else if (anfora.isPiena()) {
        cout << "L'anfora e\' piena." << endl;
    } else {
        cout << "L'anfora non e\' ne\' vuota ne\' piena." << endl;
    }
}

// funzione per il menu
void menu(Anfora &anfora5, Anfora &anfora3) {
    int selezione;
    do {
        cout << "1. Svuotare completamente un\'anfora\n";
        cout << "2. Riempire completamente un\'anfora\n";
        cout << "3. Svuotare un\'anfora nell\'altra\n";
        cout << "4. Sapere lo stato dell\'anfora\n";
        cout << "5. Sapere se un\'anfora sia vuota o piena\n";
        cout << "6. Esci\n";
        cout << "Scelta: ";
        cin >> selezione;

        switch (selezione) {
            case 1:
            // svuotare completamente un'anfora
                int anforaSvuotare;
                cout << "Scegli l\'anfora da svuotare (5 o 3 litri): ";
                cin >> anforaSvuotare;
                if (anforaSvuotare == 5) {
                    svuotareAnfora(anfora5);
                } else if (anforaSvuotare == 3) {
                    svuotareAnfora(anfora3);
                } else {
                    cout << "Scelta non valida!" << endl;
                }
                break;
            case 2:
            // riempire completamente un'anfora
                int anforaRiempire;
                cout << "Scegli l\'anfora da riempire (5 o 3 litri): ";
                cin >> anforaRiempire;
                if (anforaRiempire == 5) {
                    riempireAnfora(anfora5);
                } else if (anforaRiempire == 3) {
                    riempireAnfora(anfora3);
                } else {
                    cout << "Scelta non valida!" << endl;
                }
                break;
            case 3:
            // svuotare un'anfora nell'altra
                int anforaSvuotareNellAltra;
                cout << "Scegli l\'anfora da svuotare nell\'altra (5 o 3 litri): ";
                cin >> anforaSvuotareNellAltra;
                if (anforaSvuotareNellAltra == 5) {
                    svuotareNellAltra(anfora5, anfora3);
                } else if (anforaSvuotareNellAltra == 3) {
                    svuotareNellAltra(anfora3, anfora5);
                } else {
                    cout << "Scelta non valida!" << endl;
                }
                break;
            case 4:
            // sapere lo stato dell'anfora
                int anforaStato;
                cout << "Scegli l\'anfora di cui sapere lo stato (5 o 3 litri): ";
                cin >> anforaStato;
                if (anforaStato == 5) {
                    statoAnfora(anfora5);
                } else if (anforaStato == 3) {
                    statoAnfora(anfora3);
                } else {
                    cout << "Scelta non valida!" << endl;
                }
                break;
            case 5:
            // sapere se un'anfora sia vuota o piena
                int anforaVuotaPiena;
                cout << "Scegli l\'anfora di cui sapere se e\' vuota o piena (5 o 3 litri): ";
                cin >> anforaVuotaPiena;
                if (anforaVuotaPiena == 5) {
                    vuotaOPiena(anfora5);
                } else if (anforaVuotaPiena == 3) {
                    vuotaOPiena(anfora3);
                } else {
                    cout << "Scelta non valida!" << endl;
                }
                break;
            case 6:
            // uscita dal programma
                cout << "Uscita dal programma." << endl;
                break;
            default:
                // scelta non valida
                cout << "Scelta non valida!" << endl;
                break;
        }

        // controllo se l'anfora da 5 litri contiene 4 litri
        if (anfora5.CheckAnfora()) {
            cout << "Hai vinto! L'anfora da 5 litri contiene esattamente 4 litri." << endl;
            break;
        }

    } while (selezione != 6);
}

int main() {
    // creazione delle anfore
    Anfora anfora5(5, 0);
    Anfora anfora3(3, 0);

    // menu
    menu(anfora5, anfora3);

    return 0;
}