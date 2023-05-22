#include "../include/Pole.h"
#include<iostream>

using namespace std;

Pole::Pole(string naz, int nr)
    : nazwa(naz), nr_pola(nr) {}

void Pole::wykonaj_akcje(Gracz& gracz, Bank& bankier){
    cout<<"Gracz nr."<<gracz.nazwa<<" znajduje sie na polu "<< nazwa<<endl;
    return;
}

int Pole::get_nr_pola() {
    return nr_pola;
}
