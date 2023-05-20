#ifndef BANK_H
#define BANK_H

#include <iostream>
#include <string>

using namespace std;
class Gracz;
class Bank{
public:
    Bank(int ilosc_graczy);
    void zabierz_pieniadze(Gracz &Ggracz, int ilosc);
    void daj_pieniadze(Gracz &Ggracz, int ilosc);
    void get_pieniadze_banku();
private:
    int pieniadze_w_banku;
};

#endif
