#include "../include/PoleDoKupienia.h"
#include <iostream>

PoleDoKupienia::PoleDoKupienia(int cena, int hip, int oplata, string naz, int nr)
    : Pole(naz, nr) {
    cena_zakupu = cena;
    hipoteka = hip;
    oplata_postojowa = oplata;
    nr_wlasciciela = -1;
}
int PoleDoKupienia::informacja(int nr_obecnego){
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
    else if(nr_obecnego != nr_wlasciciela){
        return 2;
    }
    return 0;
}

void PoleDoKupienia::zakup_nieruchomosci(Gracz& kupiec, Bank& bankier) {
    if (nr_wlasciciela == -1) {
        if (kupiec.get_pieniadze() >= cena_zakupu) {
            bankier.zabierz_pieniadze(kupiec, cena_zakupu);

            nr_wlasciciela = kupiec.get_nr_gracza();

            cout << kupiec.nazwa << " zakupił nieruchomość " << nazwa << " za " << cena_zakupu << " zlotych.\n";
        }
        else {
            cout << "Brak wystarczających środków do zakupu nieruchomości.\n";
        }
    }
}

void PoleDoKupienia::sprzedaz_nieruchomosci(Gracz& wlasciciel, Bank &bankier){;
    if (nr_wlasciciela != -1) {

        bankier.daj_pieniadze(wlasciciel, cena_zakupu);

        nr_wlasciciela = -1;
    }
}

void PoleDoKupienia::pobranie_oplaty_postojowej(Gracz& postojownik, Bank& bankier, vector<Gracz*>& gracze) {
    // Sprawdź, czy pole ma właściciela
    if (nr_wlasciciela != -1) {
        if (postojownik.get_nr_gracza() != nr_wlasciciela) {
        
            if (postojownik.get_pieniadze() >= oplata_postojowa) {
    
                bankier.zabierz_pieniadze(postojownik, oplata_postojowa);

                bankier.daj_pieniadze(*gracze[nr_wlasciciela], oplata_postojowa);

                // Wyświetl komunikat o pobraniu opłaty postojowej
                cout << postojownik.nazwa << " płaci opłatę postojową w wysokości " << oplata_postojowa << " jednostek pieniądza właścicielowi " << gracze[nr_wlasciciela]->nazwa << ".\n";
            }
            else {
                cout << "Brak wystarczających środków do zapłacenia opłaty postojowej.\n";
            }
        }
    }
}

void PoleDoKupienia::stawianie_budowli(string rodzaj, Gracz &wlasciciel, Bank &bankier){}