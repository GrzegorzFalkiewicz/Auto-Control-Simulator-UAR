#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#pragma once

#include <QMainWindow>
#include <QTimer>
#include <QComboBox>
#include <QtCharts/QChartView>
#include <QtCharts/QLineSeries>
#include <QtCharts/QValueAxis>
#include "UkladRegulacji.h"
#include <QFileDialog>
#include "ModelDialog.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
private slots:
    void on_startButton_clicked();
    void on_stopButton_clicked();
    void on_resetButton_clicked();
    void on_wznowButton_clicked();
    void on_signalTypeComboBox_currentIndexChanged(int index);
    void aktualizujSymulacje();
    void on_spinBoxK_editingFinished();
    void on_spinBoxTi_editingFinished();
    void on_spinBoxTd_editingFinished();
    void on_spinBoxAmplituda_editingFinished();
    void on_spinBoxOkres_editingFinished();
    void on_spinBoxWypelnienie_editingFinished();
    void on_spinBoxInterwal_editingFinished();
    void saveConfiguration();
    void loadConfiguration();
    void on_pushButtonARX_clicked();
    void on_pushButtonResetCalka_clicked();
    void on_comboBoxSposobCalkowania_currentIndexChanged(int index);

private:
    int krok = 0;
    Ui::MainWindow *ui;
    UkladRegulacji *uklad;
    QTimer *timer;
    TypSygnalu typSygnalu;

    QVector<double> wspAstart = {0.0, 0.0, 0.0};
    QVector<double> wspBstart = {0.0, 0.0, 0.0};
    int opoznienieStart = 1;
    double zaklocenieStart = 0.0;

    bool zaklocenieWlaczone = false;
    double poziomZaklocenia = 0.0;

    QChart *chart;
    QChartView *chartView;
    QLineSeries *series;
    QLineSeries *seriesSetpoint;
    QValueAxis *axisX;
    QValueAxis *axisY;

    QChart *chartPID;
    QChartView *chartViewPID;
    QLineSeries *seriesP;
    QLineSeries *seriesI;
    QLineSeries *seriesD;
    QValueAxis *axisXPID;
    QValueAxis *axisYPID;

    QChart *chartUchyb;
    QChartView *chartViewUchyb;
    QLineSeries *seriesUchyb;
    QValueAxis *axisXUchyb;
    QValueAxis *axisYUchyb;
};
#endif // MAINWINDOW_H
