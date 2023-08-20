#include "../include/Bank.h"
#include "../include/Gracz.h"

void Bank::zabierz_pieniadze(Gracz &Ggracz, int ilosc){
    Ggracz.pieniadze -= ilosc;
    pieniadze_w_banku += ilosc;
}

void Bank::daj_pieniadze(Gracz &Ggracz, int ilosc){
    Ggracz.pieniadze += ilosc;
    pieniadze_w_banku -= ilosc;
}

void Bank::set_pieniadze_banku(int pieniadze){
    pieniadze_w_banku = pieniadze;
}