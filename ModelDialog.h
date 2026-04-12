#pragma once
#include <QDialog>
#include <QVector>

namespace Ui {
class ModelDialog;
}

class ModelDialog : public QDialog
{
    Q_OBJECT

public:
    explicit ModelDialog(QWidget *parent = nullptr);
    ~ModelDialog();

    QVector<double> getWspA() const;
    QVector<double> getWspB() const;
    int getOpoznienie() const;
    double getZaklocenie() const;
    bool isZaklocenieAktywne() const;
    void setZaklocenieAktywne(bool aktywne);
    void ustawPoczatkoweWartosci(const QVector<double>& wspA, const QVector<double>& wspB, int opoznienie, double zaklocenie);

private:
    Ui::ModelDialog *ui;
};
