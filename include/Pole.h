#ifndef POLE_H
#define POLE_H
#include <iostream>
#include <string>

using namespace std;

class Pole
{
    public:
        string nazwa;
        Pole(string naz, int nr);
        int get_nr_pola();
    protected:
        int nr_pola;
};

#endif // POLE_H
