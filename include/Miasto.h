#ifndef MIASTO_H
#define MIASTO_H
#include "PoleDoKupienia.h"

using namespace std;


class Miasto : public PoleDoKupienia{
    public:
        Miasto(string kra, int koszt_dom, int koszt_hot, int il_w_kraju, int cena, int hip, int oplata, string naz, int nr);

        void stawianie_budowli(string rodzaj, Bank bankier);
        virtual void wykonaj_akcje(int nr_gracz);
        string get_kraj();
        int get_iloscj_w_kraju();
        int get_koszt_domu();
        int get_koszt_hotelu();
        int get_ilosc_domow();
        int get_ilosc_hoteli();
    private:
        string kraj;
        int iloscj_w_kraju;
        int koszt_domu;
        int koszt_hotelu;

        int ilosc_domow;
        int ilosc_hoteli;
};

#endif
