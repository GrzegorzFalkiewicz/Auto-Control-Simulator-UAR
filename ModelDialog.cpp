#include "ModelDialog.h"
#include "ui_ModelDialog.h"

ModelDialog::ModelDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ModelDialog)
{
    ui->setupUi(this);
    ui->doubleSpinBoxZaklocenie->setSingleStep(0.01);
    ui->spinBoxOpoznienie->setMinimum(1);
}

ModelDialog::~ModelDialog()
{
    delete ui;
}

QVector<double> ModelDialog::getWspA() const {
    return { ui->spinBoxA1->value(), ui->spinBoxA2->value(), ui->spinBoxA3->value() };
}

QVector<double> ModelDialog::getWspB() const {
    return { ui->spinBoxB1->value(), ui->spinBoxB2->value(), ui->spinBoxB3->value() };
}

int ModelDialog::getOpoznienie() const {
    return ui->spinBoxOpoznienie->value();
}

double ModelDialog::getZaklocenie() const {
    return ui->doubleSpinBoxZaklocenie->value();
}

void ModelDialog::ustawPoczatkoweWartosci(const QVector<double>& wspA, const QVector<double>& wspB, int opoznienie, double zaklocenie)
{
    ui->spinBoxA1->setValue(wspA[0]);
    ui->spinBoxA2->setValue(wspA[1]);
    ui->spinBoxA3->setValue(wspA[2]);

    ui->spinBoxB1->setValue(wspB[0]);
    ui->spinBoxB2->setValue(wspB[1]);
    ui->spinBoxB3->setValue(wspB[2]);

    ui->spinBoxOpoznienie->setValue(opoznienie);
    ui->doubleSpinBoxZaklocenie->setValue(zaklocenie);
}

bool ModelDialog::isZaklocenieAktywne() const {
    return ui->checkBoxZaklocenie->isChecked();
}

void ModelDialog::setZaklocenieAktywne(bool aktywne) {
    ui->checkBoxZaklocenie->setChecked(aktywne);
}
