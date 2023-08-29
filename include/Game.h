#include <iostream>
#include <vector>
#include "Miasto.h"
#include "Gracz.h"
#include "Bank.h"
#include "Pole.h"
#include "Szansa.h"
#include "Start.h"
#include "Strata.h"

using namespace std;

class Game {
private:
    vector<Pole*> pola;
    vector<Gracz*> gracze;
    Bank bankier;
    int number_of_players;

    void clearConsole();
    void init();
    void game();

public:
    void start() {
        game();
    }
    Game(int players) : number_of_players(players) {}
    ~Game() {
        for (Gracz* player : gracze) {
            delete player;
        }
    }
};