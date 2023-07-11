#include "../include/Pole.h"
#include<iostream>

using namespace std;

Pole::Pole(string naz, int nr)
    : nazwa(naz), nr_pola(nr) {}

int Pole::informacja(int nr_obecnego){
    cout<<"Znajdujesz sie na polu "<< nazwa<<endl;
    return 0;
}

int Pole::get_nr_pola() {
    return nr_pola;
}
