#ifndef SZANSA_H
#define SZANSA_H
#include "Bank.h"
#include "Gracz.h"
#include "Pole.h"

using namespace std;

class Szansa : public Pole{
public:
    virtual void wykonaj_akcje(int nr_gracz);
    void przyznaj_nagrode(Gracz &nagradzany, Bank &bankier);
private:
    int nagroda;
};
#endif
