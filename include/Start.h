#ifndef START_H
#define START_H

#include <iostream>
#include <string>
#include "Gracz.h"
#include "Pole.h"

using namespace std;

class Start: public Pole{
public:
    int premia;
    Start(string nazwa, int premia, int nr_pola);
    void przyznaj_premie(Gracz &przyznawca);
};
#endif
