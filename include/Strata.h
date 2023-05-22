#ifndef STRATA_H
#define STRATA_H
#include "Bank.h"
#include "Gracz.h"
#include "Pole.h"

using namespace std;

class Strata : public Pole{
public:
    Strata(int kar, string naz, int nr);
    virtual void wykonaj_akcje(int nr_gracz);
    void odbierz_kare(Gracz &karany, Bank &bankier);
private:
    int kara;
};
#endif
