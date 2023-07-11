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
    cout<<"Ilosc oczek wyrzucona: "<<ilosc_oczek<<endl;
    return;
}

void Gracz::wykonaj_ruch(){
    pozycja += ilosc_oczek;
    if (pozycja >= 6) {
        pozycja = 0;
        nalezy_sie_premia = true;
    }
}

int Gracz::get_pieniadze(){ return pieniadze;}
int Gracz::get_pozycja(){ return pozycja;}
int Gracz::get_ilosc_oczek(){return ilosc_oczek;}
int Gracz::get_nr_gracza(){ return nr_gracza;}
bool Gracz::get_nalezy(){return nalezy_sie_premia;}
void Gracz::set_nalezy(bool wartosc){nalezy_sie_premia = wartosc;}