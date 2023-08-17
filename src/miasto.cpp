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

int Miasto::informacja(int nr_obecnego){
    cout<<"Znajdujesz sie na polu "<< nazwa<<endl;
    if(nr_wlasciciela == -1){
        int wybor;
        cout<<"Czy chcesz kupic "<<nazwa<<", za "<< cena_zakupu <<" zlotych?"<<endl;
        cout<<"1.Tak 0.Nie"<<endl;
        do{
            cin>>wybor;
        }while (wybor < 0 || wybor > 1);
        if (wybor) {
            return 1;
        }
        return 0;
    }
    else{
        if(nr_obecnego != nr_wlasciciela){
            return 2;
        }
        else{
            int wybor;
            if (ilosc_domow == 4) {
                cout<<"Chcesz postawic hotel?"<<endl;
                do{
                    cin>>wybor;
                }while (wybor < 0 || wybor > 1);    
                if (wybor) {
                    return 4;
                }
                return 0;
            }
            cout<<"Chcesz postawic dom?"<<endl;
            cout<<"1.Tak 0.Nie"<<endl;
            do{
                cin>>wybor;
            }while (wybor < 0 || wybor > 1);
            if (wybor) {
                return 3;
            }
            return 0;
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
        ilosc_domow = 0;
    }
}
