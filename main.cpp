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

        //In the first approach, where you create instances of PoleDoKupienia and Miasto on the stack, 
        //you are storing pointers to these objects in the pola vector. 
        //The problem with this approach is that these objects are local to the init() function, 
        //and their memory gets deallocated as soon as the function scope ends.

        //In the second approach, where you create instances of Miasto using the new keyword and store pointers to them in the pola vector, 
        //the objects are allocated on the heap. 
        //This means that the objects' memory is not deallocated until you explicitly delete them. 
    
        pola.push_back(new Miasto("Anglia", 320, 400, 3, 500, 30, 45, "Wieden", 0));
        pola.push_back(new Miasto("Anglia", 320, 400, 3, 500, 30, 45, "Wieden", 1));
        pola.push_back(new Miasto("Anglia", 320, 400, 3, 500, 30, 45, "Wieden", 2));
        pola.push_back(new Miasto("Anglia", 320, 400, 3, 500, 30, 45, "Wieden", 3));
        pola.push_back(new Miasto("Anglia", 320, 400, 3, 500, 30, 45, "Wieden", 4));
        pola.push_back(new Miasto("Anglia", 320, 400, 3, 500, 30, 45, "Wieden", 5));
        pola.push_back(new Miasto("Anglia", 320, 400, 3, 500, 30, 45, "Wieden", 6));

    }

    void game() {
        init();
        Bank bankier;
        bankier.set_pieniadze_banku(30000 - (number_of_players * 3000));

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
            //cout<<aktualne_pole->nazwa;
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
    Game game(3);
    game.start();
    return 0;
}
