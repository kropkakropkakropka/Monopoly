#include <iostream>
#include <ostream>
#include <string.h>
#include <vector>
#include "include/Pole.h"
#include "include/Miasto.h"
#include "include/Gracz.h"
#include "include/Bank.h"
#include "include/PoleDoKupienia.h"
#include "include/Szansa.h"
#include "include/Koleje.h"
#include "include/Uslugi.h"
#include "include/Wiezenie.h"
#include "include/ParkingDarmowy.h"
#include "include/Policjant.h"
#include "include/Start.h"
#include "include/Strata.h"

using namespace std;
int main(){
    vector<Pole*> pola;

    //PoleDoKupienia pole1("Koleja", 100, 50, 10, 4);
    Start pole_start("Start", 400, 1);
    Miasto Londyn("Anglia", "Londyn",4500, 350, 400, 250, 50, 12, 3);

    //pola.push_back(&pole1);
    pola.push_back(&pole_start);
    pola.push_back(&Londyn);
}
