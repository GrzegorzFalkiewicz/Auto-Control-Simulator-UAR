#include "UkladRegulacji.h"

UkladRegulacji::UkladRegulacji(const std::vector<double>& wspA, const std::vector<double>& wspB, int opoznienie, bool stan, double zakres,
    double k, double ti, double td,
    TypSygnalu typSygnalu, double amplituda, double okres, double wypelnienie)
    : model(wspA, wspB, opoznienie, stan , zakres),
    regulator(k, ti, td),
    generator(typSygnalu, amplituda, okres, wypelnienie, opoznienie),
    petla(&model, &regulator, &generator) {
}
double UkladRegulacji::symuluj(int krok) {
    double wynik = petla.symuluj(krok);
    return wynik;
}
ModelARX& UkladRegulacji::getModel() { return model; }
RegulatorPID& UkladRegulacji::getRegulator() { return regulator; }
Generator& UkladRegulacji::getGenerator() { return generator; }
