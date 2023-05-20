#ifndef SZANSA_H
#define SZANSA_H
#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Szansa{
public:
    vector<string> zawartosc;
    int nr_pola;

    Szansa(vector<string> zawartosc, int nr_pola);
    void wylosuj_szanse();
};
#endif