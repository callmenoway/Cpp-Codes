#include <iostream>

#include "queue.h"
#include "stack.h"

using namespace std;

//funzione per inserire materiale nella coda
void inserisciMateriale(Queue &queue) {
    int codice;
    cout << "Inserisci il codice del materiale: ";
    cin >> codice;
    InQueue(queue, codice);
    cout << "Inserito nella coda: " << Front(queue) << endl;
}

//funzione per spostare materiale dalla coda alla pila
void spostaMateriale(Queue &queue, Stack &pila1, Stack &pila2, Stack &pila3) {
    if (!EmptyQueue(queue)) {
        int box = Front(queue);
        DeQueue(queue);
        int pilaScelta;
        cout << "Scegli la pila (1, 2, 3): ";
        cin >> pilaScelta;
        if (pilaScelta == 1) {
            Push(pila1, box);
            cout << "Spostato dalla coda alla pila 1: " << Top(pila1) << endl;
        } else if (pilaScelta == 2) {
            Push(pila2, box);
            cout << "Spostato dalla coda alla pila 2: " << Top(pila2) << endl;
        } else if (pilaScelta == 3) {
            Push(pila3, box);
            cout << "Spostato dalla coda alla pila 3: " << Top(pila3) << endl;
        } else {
            cout << "Pila non valida!" << endl;
        }
    } else {
        cout << "La coda è vuota!" << endl;
    }
}

//funzione per estrarre materiale dalla pila
void estraiMateriale(Stack &pila1, Stack &pila2, Stack &pila3) {
    int pilaScelta;
    cout << "Scegli la pila (1, 2, 3): ";
    cin >> pilaScelta;
    if (pilaScelta == 1 && !EmptyStack(pila1)) {
        int box = Top(pila1);
        Pop(pila1);
        cout << "Estratto dalla pila 1: " << box << endl;
    } else if (pilaScelta == 2 && !EmptyStack(pila2)) {
        int box = Top(pila2);
        Pop(pila2);
        cout << "Estratto dalla pila 2: " << box << endl;
    } else if (pilaScelta == 3 && !EmptyStack(pila3)) {
        int box = Top(pila3);
        Pop(pila3);
        cout << "Estratto dalla pila 3: " << box << endl;
    } else {
        cout << "Pila non valida o vuota!" << endl;
    }
}

//MENU GESTIONALE MAGAZZINO
void menu() {
    Queue queue;
    Stack pila1, pila2, pila3;
    initQueue(queue);
    initStack(pila1);
    initStack(pila2);
    initStack(pila3);

    int scelta;
    do {
        system("cls");
        cout << "GESTIONALE MAGAZZINO\n";
        cout << "1. Inserisci materiale nella coda\n";
        cout << "2. Sposta materiale dalla coda alla pila\n";
        cout << "3. Estrai materiale dalla pila\n";
        cout << "4. Esci\n";
        cout << "Scelta: ";
        cin >> scelta;

        switch (scelta) {
            case 1:
                inserisciMateriale(queue);
                break;
            case 2:
                spostaMateriale(queue, pila1, pila2, pila3);
                break;
            case 3:
                estraiMateriale(pila1, pila2, pila3);
                break;
            case 4:
                cout << "Uscita dal programma." << endl;
                break;
            default:
                cout << "Scelta non valida!" << endl;
                break;
        }
    } while (scelta != 4);
}

int main() {
    menu();
    return 0;
}