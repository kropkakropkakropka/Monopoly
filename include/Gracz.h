#ifndef GRACZ_H
#define GRACZ_H

#include <iostream>
#include <string>
#include <vector>
#include "Bank.h"

using namespace std;

class Gracz{
public:
    string nazwa;

    Gracz(string naz, int nr_g);
    void rzut_kostka();
    void wykonaj_ruch();

    friend void Bank::zabierz_pieniadze(Gracz &Ggracz, int ilosc);
    friend void Bank::daj_pieniadze(Gracz &Ggracz, int ilosc);

    int get_nr_gracza();
    int get_pieniadze();
    int get_pozycja();
    int get_ilosc_oczek();
    int get_wiezienie();

private:
    int nr_gracza;
    int pieniadze;
    int pozycja;
    int ilosc_oczek;
    int wiezienie;
};

#endif
