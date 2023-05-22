#ifndef POLE_H
#define POLE_H
#include <string>
#include "Gracz.h"
#include "Bank.h"
using namespace std;

class Pole
{
public:
    string nazwa;
    Pole(string naz, int nr);
    virtual void wykonaj_akcje(Gracz& gracz, Bank& bankier);
    int get_nr_pola();
protected:
    int nr_pola;
};

#endif // POLE_H
