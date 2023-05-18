#ifndef USLUGI_H
#define USLUGI_H
#include <iostream>
#include <string>
#include <vector>
#include "Gracz.h"
#include "Bank.h"

using namespace std;


class Uslugi : public Pole{
    public:
        Uslugi(string naz, int cena, int hip, int oplata, int nr);
};

#endif
