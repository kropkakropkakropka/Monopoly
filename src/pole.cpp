#include "../include/Pole.h"

using namespace std;
Pole::Pole(string naz, int nr)
    : nazwa(naz), nr_pola(nr) {}

int Pole::get_nr_pola() {
    return nr_pola;
}