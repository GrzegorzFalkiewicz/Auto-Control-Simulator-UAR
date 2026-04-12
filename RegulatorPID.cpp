#include "RegulatorPID.h"
#include <iostream>

RegulatorPID::RegulatorPID(double k, double ti, double td)
    : k(k), ti(ti), td(td), suma_uchybu(0.0), poprzedniBladaWart(0.0), tiPozaCalka(false) {}

double RegulatorPID::symuluj(double blad) {
    wyj_p = k * blad;

    if (ti > 0.0)
    {
        if (tiPozaCalka)
        {
            suma_uchybu += blad;
            wyj_i = suma_uchybu / ti;
        } else
        {
            suma_uchybu += blad / ti;
            wyj_i = suma_uchybu;
        }
    } else
    {
        wyj_i = 0.0;
    }

    wyj_d = td * (blad - poprzedniBladaWart);
    poprzedniBladaWart = blad;
    double wyjscie = wyj_p + wyj_i + wyj_d;
    return wyjscie;
}

void RegulatorPID::setTiPozaCalka(bool wartosc) {
    if (ti > 0.0 && tiPozaCalka != wartosc) {
        if (wartosc)
        {
            suma_uchybu *= ti;
        }
        else {
            suma_uchybu /= ti;
        }
    }
    tiPozaCalka = wartosc;
}

bool RegulatorPID::getTiPozaCalka() const { return tiPozaCalka; }

void RegulatorPID::resetCzescI() { suma_uchybu = 0.0; }

void RegulatorPID::setK(double noweK) { k = noweK; }
void RegulatorPID::setTi(double noweTi) { ti = noweTi; }
void RegulatorPID::setTd(double noweTd) { td = noweTd; }

double RegulatorPID::getK() const { return k; }
double RegulatorPID::getTi() const { return ti; }
double RegulatorPID::getTd() const { return td; }

double RegulatorPID::getWyjP() const { return wyj_p; }
double RegulatorPID::getWyjI() const { return wyj_i; }
double RegulatorPID::getWyjD() const { return wyj_d; }

RegulatorPID::~RegulatorPID() {}
