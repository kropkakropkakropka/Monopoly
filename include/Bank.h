#ifndef BANK_H
#define BANK_H

#include <iostream>
#include <string>

using namespace std;
class Gracz;
class Bank{
public:
    void zabierz_pieniadze(Gracz &Ggracz, int ilosc);
    void daj_pieniadze(Gracz &Ggracz, int ilosc);
    int get_pieniadze_banku();
    void set_pieniadze_banku(int pieniadze);
private:
    int pieniadze_w_banku;
};

#endif
