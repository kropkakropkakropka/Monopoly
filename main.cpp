#include <iostream>
#include <vector>
#include "include/Miasto.h"
#include "include/Gracz.h"
#include "include/Bank.h"
#include "include/Pole.h"
#include "include/Szansa.h"
#include "include/Start.h"
#include "include/Strata.h"

using namespace std;

class Game {
private:
    vector<Pole*> pola;
    vector<Gracz*> gracze;
    Bank bankier;
    int number_of_players;

    void clearConsole() {
        cin.ignore();
        cout << "Naciśnij klawisz Enter, aby kontynuować...";
        cin.ignore();
        #ifdef _WIN32 //na windowsie zeby dzialalo
            system("cls");
        #else
            system("clear");
        #endif
    }
    void init() {
        for (int i = 0; i < number_of_players; ++i) {
            string name;
            cout << "Podaj imie gracza nr." << i + 1 << ": ";
            cin >> name;
            gracze.push_back(new Gracz(name, i));
        }

        PoleDoKupienia koleja(350, 30, 35, "Koleja wschodnia", 0);
        Miasto Londyn("Anglia", 320, 400, 3, 500, 30, 45, "Londyn", 1);
        Miasto Wieden("Anglia", 320, 400, 3, 500, 30, 45, "Wieden", 2);
        Miasto Test("Anglia", 320, 400, 3, 500, 30, 45, "Test", 3);
        Miasto Siema("Anglia", 320, 400, 3, 500, 30, 45, "Siema", 4);
        Miasto Aha("Anglia", 320, 400, 3, 500, 30, 45, "Aha", 5);

        pola.push_back(&koleja);
        pola.push_back(&Londyn);
        pola.push_back(&Wieden);
        pola.push_back(&Test);
        pola.push_back(&Siema);
        pola.push_back(&Aha);
    }

    void game() {
        init();
        Bank bankier(number_of_players);

        bool koniecGry = false;
        int aktualny_gracz_index = 0;

        while (!koniecGry) {
            Gracz* aktualnyGracz = gracze[aktualny_gracz_index];
            cout << "Ruch gracza: " << aktualnyGracz->nazwa << endl;
            cout << aktualnyGracz->nazwa << " posiada " << aktualnyGracz->get_pieniadze() << " zlotych" << endl;

            aktualnyGracz->rzut_kostka();
            aktualnyGracz->wykonaj_ruch();

            if (aktualnyGracz->get_nalezy()) {
                bankier.daj_pieniadze(*aktualnyGracz, 400);
                cout << "Przyznano premie za przejscie pola start" << endl;
                aktualnyGracz->set_nalezy(false);
            }

            Pole* aktualne_pole = pola[aktualnyGracz->get_pozycja()];

            int info = aktualne_pole->informacja(aktualnyGracz->get_nr_gracza());

            switch (info) {
                case 1:
                    aktualne_pole->zakup_nieruchomosci(*aktualnyGracz, bankier);
                    break;
                case 2:
                    aktualne_pole->pobranie_oplaty_postojowej(*aktualnyGracz, bankier, gracze);
                    break;
                case 3:
                    aktualne_pole->stawianie_budowli("dom", *aktualnyGracz, bankier);
                    break;
                case 4:
                    aktualne_pole->stawianie_budowli("hotel", *aktualnyGracz, bankier);
                    break;
                case 5:
                    bankier.daj_pieniadze(*aktualnyGracz, 400);
                    break;
                case 6:
                    bankier.zabierz_pieniadze(*aktualnyGracz, 400);
                    break;
                default:
                    break;
            }

            aktualny_gracz_index++;
            if (aktualny_gracz_index >= gracze.size()) {
                aktualny_gracz_index = 0;
            }

            clearConsole();
        }
    }

public:
    void start() {
        game();
    }
    Game(int players) : number_of_players(players) {
        // Constructor to set the number of players
    }
    ~Game() {
        for (Gracz* player : gracze) {
            delete player;
        }
    }
};

int main() {
    Game game(5);
    game.start();
    return 0;
}
