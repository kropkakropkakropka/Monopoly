#ifndef KOLEJE_H
#define KOLEJE_H
#include <iostream>
#include <string>
#include <vector>
#include "Gracz.h"
#include "Bank.h"

using namespace std;


class Koleje : public Pole{
    public:
        Koleje(string naz, int cena, int hip, int oplata, int nr);
};

#endif
