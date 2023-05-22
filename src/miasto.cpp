#include "../include/Miasto.h"
#include<iostream>


Miasto::Miasto(string kra, int koszt_dom, int koszt_hot, int il_w_kraju, int cena, int hip, int oplata, string naz, int nr)
    :PoleDoKupienia(cena, hip, oplata, naz, nr){
    ilosc_domow = 0;
    ilosc_hoteli = 0;
    kraj = kra;
    koszt_domu = koszt_dom;
    koszt_hotelu = koszt_hot;
    iloscj_w_kraju = il_w_kraju;
}

void Miasto::wykonaj_akcje(Gracz& gracz, Bank& bankier){
    cout<<"Gracz nr."<<gracz.nazwa<<" znajduje sie na polu "<< nazwa<<endl;
    if(nr_wlasciciela == -1){
        int wybor;
        cout<<"Czy chcesz kupic "<<nazwa<<", za "<< cena_zakupu <<" zlotych?"<<endl;
        cout<<"1.Tak 0.Nie"<<endl;
        do{
            cin>>wybor;
        }while (wybor < 0 || wybor > 1);
        if (wybor) {
            zakup_nieruchomosci(gracz, bankier);
        }
        return;
    }
    else{
        if(gracz.get_nr_gracza() != nr_wlasciciela){
            pobranie_oplaty_postojowej(gracz, bankier);
            return;
        }
        else{
            int wybor;
            cout<<"Chcesz postawic budowle?"<<endl;
            cout<<"1.Tak 0.Nie"<<endl;
            do{
                cin>>wybor;
            }while (wybor < 0 || wybor > 1);
            if (wybor) {
                stawianie_budowli("dom", gracz, bankier);
            }
            return;
        }
    }
}
string Miasto::get_kraj(){
    return kraj;
}


void Miasto::stawianie_budowli(string rodzaj, Gracz& wlasciciel, Bank& bankier){
    if (rodzaj == "dom") {
        bankier.zabierz_pieniadze(wlasciciel, koszt_domu);
        ilosc_domow++;
        oplata_postojowa += oplata_postojowa * ilosc_domow;
    }
    else if (rodzaj == "hotel" && ilosc_domow == 4) {
        bankier.zabierz_pieniadze(wlasciciel, koszt_hotelu);
        ilosc_hoteli++;
        ilosc_domow -= 4;
    }
}
