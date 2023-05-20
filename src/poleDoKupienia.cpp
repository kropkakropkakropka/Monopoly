#include "../include/PoleDoKupienia.h"
#include "../include/Pole.h"

PoleDoKupienia::PoleDoKupienia(int cena, int hip, int oplata)
    : Pole(nazwa, nr_pola) {
    cena_zakupu = cena;
    hipoteka = hip;
    oplata_postojowa = oplata;
    nr_wlasciciela = -1; 
}
