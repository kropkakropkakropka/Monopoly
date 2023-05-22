#include <iostream>
#include <vector>
#include "include/Miasto.h"
#include "include/Gracz.h"
#include "include/Bank.h"
#include "include/Pole.h"
#include "include/Szansa.h"
#include "include/Koleje.h"
#include "include/Uslugi.h"
#include "include/ParkingDarmowy.h"
#include "include/Start.h"
#include "include/Strata.h"

using namespace std;
int main(){
    vector<Pole*> pola;
    vector<Gracz*> gracze;

    Gracz pierwszy("Kuba", 0);
    Gracz drugi("Pawel", 1);
    Gracz trzeci("Marek", 2);

    gracze.push_back(&pierwszy);
    gracze.push_back(&drugi);
    gracze.push_back(&trzeci);

    PoleDoKupienia koleja(350, 30, 35, "Koleja wschodnia", 0);
    Miasto Londyn("Anglia", 320, 400, 3, 500, 30, 45,"Londyn", 1);
    Miasto Wieden("Anglia", 320, 400, 3, 500, 30, 45,"Wieden", 2);
    Miasto Test("Anglia", 320, 400, 3, 500, 30, 45,"Test", 3);
    Miasto Siema("Anglia", 320, 400, 3, 500, 30, 45,"Siema", 4);
    Miasto Aha("Anglia", 320, 400, 3, 500, 30, 45,"Aha", 5);

    pola.push_back(&koleja);
    pola.push_back(&Londyn);
    pola.push_back(&Wieden);
    pola.push_back(&Test);
    pola.push_back(&Siema);
    pola.push_back(&Aha);

    Bank bankier(3);
    bool koniecGry = false;
    int aktualny_gracz_index = 0;
    while (!koniecGry) {
        // Pobierz aktualnego gracza
        Gracz* aktualnyGracz = gracze[aktualny_gracz_index];

        // Wykonaj rzut kostką dla aktualnego gracza
        aktualnyGracz->rzut_kostka();

        // Przesuń gracza na nową pozycję
        aktualnyGracz->wykonaj_ruch();

        // Pobierz pole, na którym znajduje się gracz
        Pole* aktualne_pole = pola[aktualnyGracz->get_pozycja()];

        // Wykonaj akcję związane z polem
        aktualne_pole->wykonaj_akcje(*aktualnyGracz, bankier);

        // Przełącz na następnego gracza
        aktualny_gracz_index++;
        if (aktualny_gracz_index >= 3) {
            aktualny_gracz_index = 0;
        }

        // Sprawdź warunek zakończenia gry (np. bankructwo graczy)
        // Jeśli warunek zakończenia gry jest spełniony, ustaw koniecGry na true
        // W przeciwnym razie gra kontynuuje się

        // Wyświetl informacje na temat stanu gry, ruchu gracza itp.

        // Zaimplementuj opóźnienie lub zdarzenia, aby umożliwić obserwowanie rozgrywki
    }

    // Wyświetl informację o zakończeniu gry i zwycięzcy

    return 0;
}
