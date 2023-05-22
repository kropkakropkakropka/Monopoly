#ifndef RYZYKO_H
#define RYZYKO_H
#include "Bank.h"
#include "Gracz.h"
#include "Pole.h"

using namespace std;

class Ryzyko : public Pole{
public:
    virtual int wykonaj_akcje(int nr_gracz);
    void odbierz_pieniadze(Gracz &nagradzany, Bank &bankier);
private:
    int strata;
};
#endif
