#ifndef POLE_H
#define POLE_H
#include <string>

using namespace std;

class Pole
{
public:
    string nazwa;
    Pole(string naz, int nr);
    virtual void wykonaj_akcje(int nr_gracz);
    int get_nr_pola();
protected:
    int nr_pola;
};

#endif // POLE_H
