#ifndef POLICJANT_H
#define POLICJANT_H
#include <iostream>
#include <string>
#include <vector>
#include "Gracz.h"
#include "Pole.h"

using namespace std;

class Policjant : public Pole{
public:
    int czas_kary;

    Policjant(int nr_pola);
    void wypad_do_paki(Gracz &karany);
};
#endif
