#include "Miasto.h"

Miasto::Miasto(string kra, string naz, int cena, int koszt_dom, int koszt_hot, int hip, int oplata, int nr, int il_w_kr){
    wlasciciel = nullptr;
    ilosc_domow = 0;
    ilosc_hoteli = 0;

    kraj = kra;
    nazwa = naz;
    cena_zakupu = cena;
    koszt_domu = koszt_dom;
    koszt_hotelu = koszt_hot;
    hipoteka = hip;
    oplata_postojowa = oplata;
    nr_pola = nr;
    iloscj_w_kraju = il_w_kr;
}

void Miasto::zakup_nieruchomosci(Gracz &kupiec,  Bank &bankier){
    if (wlasciciel == nullptr && kupiec.pozycja == nr_pola) {
        bankier.zabierz_pieniadze(kupiec, cena_zakupu);
        wlasciciel = &kupiec;
    }
}

void Miasto::sprzedaz_nieruchomosci(Bank bankier){
    if (wlasciciel != nullptr) {

        bankier.daj_pieniadze(*wlasciciel, cena_zakupu);

        wlasciciel = nullptr;
    }
}


void Miasto::pobranie_oplaty_postojowej(Gracz &postojownik, Bank bankier){
    if (wlasciciel != nullptr && &postojownik != wlasciciel && postojownik.pozycja == nr_pola) {
        bankier.zabierz_pieniadze(postojownik, oplata_postojowa);
        bankier.daj_pieniadze(*wlasciciel, oplata_postojowa);
    }
}

void Miasto::stawianie_budowli(string rodzaj, Bank bankier){
    if (rodzaj == "dom") {
        bankier.zabierz_pieniadze(*wlasciciel, koszt_domu);
        ilosc_domow++;
        oplata_postojowa += oplata_postojowa * ilosc_domow;
    }
    else if (rodzaj == "hotel" && ilosc_domow == 4) {
        bankier.zabierz_pieniadze(*wlasciciel, koszt_hotelu);
        ilosc_hoteli++;
        ilosc_domow -= 4;
    }
}
