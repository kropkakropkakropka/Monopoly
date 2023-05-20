#ifndef WIEZENIE_H
#define WIEZENIE_H
#include <iostream>
#include <string>
#include <vector>
#include "Gracz.h"

using namespace std;

class Wiezienie{
public:
    int nr_pola;
    vector<Gracz> wiezniowie;
    vector<Gracz> zwiedzajacy;

    Wiezienie(int nr_pola);
};
#endif