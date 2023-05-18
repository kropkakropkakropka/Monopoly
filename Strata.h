#ifndef STRATA_H
#define STRATA_H
#include <iostream>
#include <string>
#include "Bank.h"
#include "Gracz.h"
#include "Pole.h"

using namespace std;

class Strata : public Pole{
public:
    Strata(int kara, int nr_pola);
    void odbierz_kare(Gracz &karany, Bank &bankier);
private:
    int kara;
};
#endif
