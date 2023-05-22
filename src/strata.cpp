#include "../include/Strata.h"
#include<iostream>

using namespace std;

Strata::Strata(int kar, string naz, int nr)
    : Pole(naz, nr){
    kara = kar;
}

int Strata::wykonaj_akcje(int nr_gracz){
    cout<<"Gracz nr."<<nr_gracz<<" znajduje sie na polu "<< nazwa<<endl;
    cout<<"Mususz zaplacic "<< kara <<" zlotych kary"<<endl;
}

void Strata::odbierz_kare(Gracz &karany, Bank &bankier){
    bankier.zabierz_pieniadze(karany, kara);
}
