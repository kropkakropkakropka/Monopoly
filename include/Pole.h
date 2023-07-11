#ifndef POLE_H
#define POLE_H
#include <string>
#include "Gracz.h"
#include "Bank.h"

using namespace std;

class Pole
{
public:
    string nazwa;
    Pole(string naz, int nr);
    virtual int informacja(int nr_obecnego);
    virtual void zakup_nieruchomosci(Gracz& kupiec, Bank& bankier) = 0;
    virtual void sprzedaz_nieruchomosci(Gracz& wlasciciel, Bank &bankier) = 0;
    virtual void pobranie_oplaty_postojowej(Gracz &postojownik, Bank &bankier, vector<Gracz*>& gracze) = 0;
    virtual void stawianie_budowli(string rodzaj, Gracz& wlasciciel, Bank& bankier)= 0;
    int get_nr_pola();
protected:
    int nr_pola;
};

#endif // POLE_H
