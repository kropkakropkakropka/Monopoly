#include "Bank.h"
#include "Gracz.h"
Bank::Bank(int ilosc_graczy){
    int  pieniadze_w_banku = 30000 - (ilosc_graczy * 3000);
}

void Bank::zabierz_pieniadze(Gracz &Ggracz, int ilosc){
    Ggracz.pieniadze -= ilosc;
    pieniadze_w_banku += ilosc;
}

void Bank::daj_pieniadze(Gracz &Ggracz, int ilosc){
    Ggracz.pieniadze += ilosc;
    pieniadze_w_banku -= ilosc;
}
