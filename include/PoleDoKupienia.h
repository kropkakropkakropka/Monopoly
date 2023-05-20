#ifndef POLEDOKUPIENIA_H
#define POLEDOKUPIENIA_H

#include <iostream>
#include <string>
#include "Pole.h"

using namespace std;
class Gracz;
class Bank;

class PoleDoKupienia : public Pole{
    public:
        void zakup_nieruchomosci(Gracz &kupiec, Bank &bankier);
        void sprzedaz_nieruchomosci(Bank bankier);
        void pobranie_oplaty_postojowej(Gracz &postojownik, Bank bankier);

        PoleDoKupienia(int cena, int hip, int oplata);

        int get_hipoteka();
        int get_oplata_postojowa();
        int get_cena_zakupu();
        int get_nr_wlasciciela();
    protected:
        int nr_wlasciciela;
        int cena_zakupu;
        int hipoteka;
        int oplata_postojowa;
};

#endif // POLEDOKUPIENIA_H
