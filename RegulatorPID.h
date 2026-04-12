#pragma once

class RegulatorPID {
private:
    double k, ti, td;
    double suma_uchybu;
    double poprzedniBladaWart;
    double wyj_p;
    double wyj_i;
    double wyj_d;
    bool tiPozaCalka = true;
public:
    RegulatorPID(double k, double ti, double td);
    ~RegulatorPID();

    void setTiPozaCalka(bool wartosc);
    bool getTiPozaCalka() const;
    void resetCzescI();

    double symuluj(double blad);
    double symulujProporcjonalny(double blad);
    double symulujCalkujacy(double blad);
    double symulujRozniczkujacy(double blad);

    void setK(double noweK);
    void setTi(double noweTi);
    void setTd(double noweTd);

    double getK() const;
    double getTi() const;
    double getTd() const;
    double getWyjP() const;
    double getWyjI() const;
    double getWyjD() const;
};
