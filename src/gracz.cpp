#include "../include/Gracz.h"
#include "../include/Bank.h"
#include <cstddef>
#include <iostream>
#include <cstdlib>
#include <ctime>

Gracz::Gracz(string naz, int nr_g){
    nazwa = naz;
    pieniadze = 3000;
    pozycja = 0;
    wiezienie = 0;
    ilosc_oczek = 0;
    nr_gracza = nr_g;
}

void Gracz::rzut_kostka(){
    srand(time(NULL));
    ilosc_oczek = rand() % 5 + 1;
    cout<<nazwa<<" wyrzucil "<<ilosc_oczek<<" oczek"<<endl;
    return;
}

void Gracz::wykonaj_ruch(){
    pozycja += ilosc_oczek;
    pozycja %= 6;
    cout<<nazwa<<" przechodzi na pole nr."<< pozycja<<endl;
}

int Gracz::get_pozycja(){
    return pozycja;
}

int Gracz::get_nr_gracza(){
    return nr_gracza;
}

int Gracz::get_pieniadze(){
    return pieniadze;
}
