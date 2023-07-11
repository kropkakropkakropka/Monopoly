#ifndef POLEDOKUPIENIA_H
#define POLEDOKUPIENIA_H
#include "Pole.h"
#include "Gracz.h"
#include "Bank.h"
using namespace std;

class PoleDoKupienia : public Pole{
    public:
        virtual int informacja(int nr_obecnego);
        virtual void zakup_nieruchomosci(Gracz& kupiec, Bank& bankier);
        virtual void sprzedaz_nieruchomosci(Gracz& wlasciciel, Bank &bankier);
        virtual void pobranie_oplaty_postojowej(Gracz &postojownik, Bank &bankier, vector<Gracz*>& gracze);
        virtual void stawianie_budowli(string rodzaj, Gracz& wlasciciel, Bank& bankier);
        PoleDoKupienia(int cena, int hip, int oplata, string naz, int nr);

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
