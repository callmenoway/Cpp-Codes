#ifndef ANFORA_H
#define ANFORA_H

class Anfora {
    private:
    //dichiarazione delle variabili private
        int capacita;
        int stato;

    public:
    //dichiarazione dei metodi pubblici
        Anfora(int capacita, int stato);

        int getCapacita() const;
        int getStato() const;
        void svuota();
        void riempi();
        void svuotaNellAltra(Anfora &altra);
        bool CheckAnfora();
        bool isVuota() const;
        bool isPiena() const;
};

#endif