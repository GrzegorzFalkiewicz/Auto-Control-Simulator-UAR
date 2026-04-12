#include "MainWindow.h"
#include "ui_MainWindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent),
    ui(new Ui::MainWindow),
    uklad(nullptr),
    timer(new QTimer(this)),
    typSygnalu(TypSygnalu::SkokJednostkowy),
    zaklocenieWlaczone(false),
    poziomZaklocenia(0.0)
{
    ui->setupUi(this);
    connect(timer, &QTimer::timeout, this, &MainWindow::aktualizujSymulacje);
    ui->signalTypeComboBox->addItem("Skok jednostkowy");
    ui->signalTypeComboBox->addItem("Sygnał prostokątny");
    ui->signalTypeComboBox->addItem("Sygnał sinusoidalny");
    connect(ui->signalTypeComboBox, QOverload<int>::of(&QComboBox::currentIndexChanged), this, &MainWindow::on_signalTypeComboBox_currentIndexChanged);
    connect(ui->spinBoxInterwal, &QSpinBox::editingFinished, this, &MainWindow::on_spinBoxInterwal_editingFinished);
    connect(ui->spinBoxK, &QDoubleSpinBox::editingFinished, this, &MainWindow::on_spinBoxK_editingFinished);
    connect(ui->spinBoxTi, &QDoubleSpinBox::editingFinished, this, &MainWindow::on_spinBoxTi_editingFinished);
    connect(ui->spinBoxTd, &QDoubleSpinBox::editingFinished, this, &MainWindow::on_spinBoxTd_editingFinished);

    connect(ui->spinBoxAmplituda, &QDoubleSpinBox::editingFinished, this, &MainWindow::on_spinBoxAmplituda_editingFinished);
    connect(ui->spinBoxOkres, &QDoubleSpinBox::editingFinished, this, &MainWindow::on_spinBoxOkres_editingFinished);
    connect(ui->spinBoxWypelnienie, &QDoubleSpinBox::editingFinished, this, &MainWindow::on_spinBoxWypelnienie_editingFinished);

    connect(ui->saveButton, &QPushButton::clicked, this, &MainWindow::saveConfiguration);
    connect(ui->loadButton, &QPushButton::clicked, this, &MainWindow::loadConfiguration);

    chart = new QChart();
    series = new QLineSeries();
    series->setName("Wartość regulowana");
    seriesSetpoint = new QLineSeries();
    seriesSetpoint->setName("Wartość zadana");
    seriesSetpoint->setColor(Qt::red);
    chart->addSeries(series);
    chart->addSeries(seriesSetpoint);
    axisX = new QValueAxis();
    axisX->setTitleText("Krok symulacji");
    axisX->setLabelFormat("%d");
    axisX->setTickCount(10);
    axisX->setRange(0, 50);
    axisY = new QValueAxis();
    axisY->setTitleText("Wartość sygnału");
    axisY->setLabelFormat("%.2f");
    axisY->setRange(-10, 10);
    chart->addAxis(axisX, Qt::AlignBottom);
    chart->addAxis(axisY, Qt::AlignLeft);
    series->attachAxis(axisX);
    series->attachAxis(axisY);
    seriesSetpoint->attachAxis(axisX);
    seriesSetpoint->attachAxis(axisY);
    chartView = new QChartView(chart);
    chartView->setRenderHint(QPainter::Antialiasing);
    ui->verticalLayout->addWidget(chartView);

    chartPID = new QChart();
    seriesP = new QLineSeries();
    seriesP->setName("Składowa P");
    seriesP->setColor(Qt::blue);
    seriesI = new QLineSeries();
    seriesI->setName("Składowa I");
    seriesI->setColor(Qt::green);
    seriesD = new QLineSeries();
    seriesD->setName("Składowa D");
    seriesD->setColor(Qt::magenta);
    chartPID->addSeries(seriesP);
    chartPID->addSeries(seriesI);
    chartPID->addSeries(seriesD);
    axisXPID = new QValueAxis();
    axisXPID->setTitleText("Krok symulacji");
    axisXPID->setLabelFormat("%d");
    axisXPID->setTickCount(10);
    axisXPID->setRange(0, 50);
    axisYPID = new QValueAxis();
    axisYPID->setTitleText("Wartość sygnału");
    axisYPID->setLabelFormat("%.2f");
    axisYPID->setRange(-10, 10);
    chartPID->addAxis(axisXPID, Qt::AlignBottom);
    chartPID->addAxis(axisYPID, Qt::AlignLeft);
    seriesP->attachAxis(axisXPID);
    seriesP->attachAxis(axisYPID);
    seriesI->attachAxis(axisXPID);
    seriesI->attachAxis(axisYPID);
    seriesD->attachAxis(axisXPID);
    seriesD->attachAxis(axisYPID);
    chartViewPID = new QChartView(chartPID);
    chartViewPID->setRenderHint(QPainter::Antialiasing);
    ui->verticalLayoutPID->addWidget(chartViewPID);

    chartUchyb = new QChart();
    seriesUchyb = new QLineSeries();
    seriesUchyb->setName("Uchyb");
    seriesUchyb->setColor(Qt::darkRed);
    chartUchyb->addSeries(seriesUchyb);
    axisXUchyb = new QValueAxis();
    axisXUchyb->setTitleText("Krok symulacji");
    axisXUchyb->setLabelFormat("%d");
    axisXUchyb->setTickCount(10);
    axisXUchyb->setRange(0, 50);
    axisYUchyb = new QValueAxis();
    axisYUchyb->setTitleText("Wartość sygnału");
    axisYUchyb->setLabelFormat("%.2f");
    axisYUchyb->setRange(-10, 10);
    chartUchyb->addAxis(axisXUchyb, Qt::AlignBottom);
    chartUchyb->addAxis(axisYUchyb, Qt::AlignLeft);
    seriesUchyb->attachAxis(axisXUchyb);
    seriesUchyb->attachAxis(axisYUchyb);
    chartViewUchyb = new QChartView(chartUchyb);
    chartViewUchyb->setRenderHint(QPainter::Antialiasing);
    ui->verticalLayoutUchyb->addWidget(chartViewUchyb);
}

MainWindow::~MainWindow() {
    delete ui;
}

void MainWindow::on_startButton_clicked()
{
    double k = ui->spinBoxK->value();
    double ti = ui->spinBoxTi->value();
    double td = ui->spinBoxTd->value();
    double amplituda = ui->spinBoxAmplituda->value();
    double okres = ui->spinBoxOkres->value();
    double wypelnienie = ui->spinBoxWypelnienie->value();

    if (ti == 0.0) {
        ti = 0.1;
    }

    std::vector<double> vecA(wspAstart.begin(), wspAstart.end());
    std::vector<double> vecB(wspBstart.begin(), wspBstart.end());
    bool stan = zaklocenieStart != 0.0;

    uklad = new UkladRegulacji(vecA, vecB, opoznienieStart, stan, zaklocenieStart, k, ti, td, typSygnalu, amplituda, okres, wypelnienie);
    ui->startButton->hide();
}

void MainWindow::on_wznowButton_clicked()
{
    int interwal = ui->spinBoxInterwal->value();
    timer->start(interwal);
}

void MainWindow::aktualizujSymulacje()
{
    if (uklad) {
        double wartoscZadana = uklad->getGenerator().generuj(krok);
        double wynik = uklad->symuluj(krok);
        double uchyb = wartoscZadana - wynik;
        double wyjP = uklad->getRegulator().getWyjP();
        double wyjI = uklad->getRegulator().getWyjI();
        double wyjD = uklad->getRegulator().getWyjD();
        series->append(krok, wynik);
        seriesSetpoint->append(krok, wartoscZadana);
        seriesP->append(krok, wyjP);
        seriesI->append(krok, wyjI);
        seriesD->append(krok, wyjD);
        seriesUchyb->append(krok, uchyb);
        const int windowSize = 50;
        const int followThreshold = static_cast<int>(windowSize * 0.95);
        int minX = (krok > followThreshold) ? krok - followThreshold : 0;
        int maxX = minX + windowSize;
        axisX->setRange(minX, maxX);
        axisXPID->setRange(minX, maxX);
        axisXUchyb->setRange(minX, maxX);
        auto adjustYAxis = [minX, maxX](QLineSeries* series, QValueAxis* axisY) {
            double minY = std::numeric_limits<double>::max();
            double maxY = std::numeric_limits<double>::lowest();
            const auto& points = series->pointsVector();
            for (int i = std::max(0, static_cast<int>(points.size()) - windowSize); i < points.size(); ++i) {
                const auto& point = points[i];
                if (point.x() >= minX && point.x() <= maxX) {
                    minY = std::min(minY, point.y());
                    maxY = std::max(maxY, point.y());
                }
            }
            double absMax = std::max(std::abs(minY), std::abs(maxY));
            double margin = absMax * 0.2;
            if (absMax == 0) {
                absMax = 1;
            }
            axisY->setRange(-absMax - margin, absMax + margin);
        };
        adjustYAxis(series, axisY);
        adjustYAxis(seriesP, axisYPID);
        adjustYAxis(seriesD, axisYPID);
        adjustYAxis(seriesI, axisYPID);
        adjustYAxis(seriesUchyb, axisYUchyb);
        krok++;
        const int maxPoints = 1000;
        if (series->count() > maxPoints) {
            series->removePoints(0, series->count() - maxPoints);
            seriesSetpoint->removePoints(0, seriesSetpoint->count() - maxPoints);
            seriesP->removePoints(0, seriesP->count() - maxPoints);
            seriesI->removePoints(0, seriesI->count() - maxPoints);
            seriesD->removePoints(0, seriesD->count() - maxPoints);
            seriesUchyb->removePoints(0, seriesUchyb->count() - maxPoints);
        }
    }
}
void MainWindow::on_stopButton_clicked()
{
    timer->stop();
}

void MainWindow::on_resetButton_clicked()
{
    if (uklad) {
        krok = 0;
        timer->stop();
        series->clear();
        seriesSetpoint->clear();
        axisX->setRange(0, 50);
        axisY->setRange(-10, 10);
        seriesP->clear();
        seriesI->clear();
        seriesD->clear();
        axisXPID->setRange(0, 50);
        axisYPID->setRange(-10, 10);
        seriesUchyb->clear();
        axisXUchyb->setRange(0,50);
        axisYUchyb->setRange(-10,10);
    }
    delete uklad;
    uklad = nullptr;
    ui->spinBoxK->setValue(0.0);
    ui->spinBoxTi->setValue(0.1);
    ui->spinBoxTd->setValue(0.0);
    ui->spinBoxAmplituda->setValue(0.0);
    ui->spinBoxOkres->setValue(0.0);
    ui->spinBoxWypelnienie->setValue(0.0);
    ui->signalTypeComboBox->setCurrentIndex(0);
    ui->startButton->show();
    wspAstart = {0.0, 0.0, 0.0};
    wspBstart = {0.0, 0.0, 0.0};
    opoznienieStart = 1;
    zaklocenieStart = 0.0;
}

void MainWindow::on_pushButtonARX_clicked() {
    ModelDialog dialog(this);
    dialog.ustawPoczatkoweWartosci(wspAstart, wspBstart, opoznienieStart, zaklocenieStart);
    dialog.setZaklocenieAktywne(zaklocenieStart > 0.0);

    if (dialog.exec() == QDialog::Accepted) {
        wspAstart = dialog.getWspA();
        wspBstart = dialog.getWspB();
        opoznienieStart = dialog.getOpoznienie();
        zaklocenieStart = dialog.isZaklocenieAktywne() ? dialog.getZaklocenie() : 0.0;

        if (uklad) {
            uklad->getModel().setWspA(std::vector<double>(wspAstart.begin(), wspAstart.end()));
            uklad->getModel().setWspB(std::vector<double>(wspBstart.begin(), wspBstart.end()));
            uklad->getModel().setOpoznienie(opoznienieStart);
            uklad->getModel().ustawPoziomZaklocenia(zaklocenieStart);
            uklad->getModel().wlaczZaklocenie(zaklocenieStart > 0.0);
        }
    }
}

void MainWindow::on_signalTypeComboBox_currentIndexChanged(int index)
{
    switch (index) {
    case 0: typSygnalu = TypSygnalu::SkokJednostkowy; break;
    case 1: typSygnalu = TypSygnalu::Prostokatny; break;
    case 2: typSygnalu = TypSygnalu::Sinusoidalny; break;
    default: typSygnalu = TypSygnalu::SkokJednostkowy; break;
    }
    if (uklad) {
        uklad->getGenerator().setTypSygnalu(typSygnalu);
    }
}

void MainWindow::on_pushButtonResetCalka_clicked() {
    if (uklad) {
        uklad->getRegulator().resetCzescI();
    }
}

void MainWindow::on_comboBoxSposobCalkowania_currentIndexChanged(int index) {
    if (uklad) {
        bool poza = (index == 0);
        uklad->getRegulator().setTiPozaCalka(poza);
    }
}

void MainWindow::on_spinBoxK_editingFinished() {
    if (uklad) {
        uklad->getRegulator().setK(ui->spinBoxK->value());
    }
}

void MainWindow::on_spinBoxTi_editingFinished() {
    if (uklad) {
        uklad->getRegulator().setTi(ui->spinBoxTi->value());
    }
}

void MainWindow::on_spinBoxTd_editingFinished() {
    if (uklad) {
        uklad->getRegulator().setTd(ui->spinBoxTd->value());
    }
}

void MainWindow::on_spinBoxAmplituda_editingFinished() {
    if (uklad) {
        uklad->getGenerator().setAmplituda(ui->spinBoxAmplituda->value());
    }
}

void MainWindow::on_spinBoxOkres_editingFinished() {
    if (uklad) {
        uklad->getGenerator().setOkres(ui->spinBoxOkres->value());
    }
}

void MainWindow::on_spinBoxWypelnienie_editingFinished() {
    if (uklad) {
        uklad->getGenerator().setWypelnienie(ui->spinBoxWypelnienie->value());
    }
}

void MainWindow::on_spinBoxInterwal_editingFinished() {
    if (timer->isActive()) {
        timer->setInterval(ui->spinBoxInterwal->value());
    }
}

void MainWindow::saveConfiguration() {
    QString fileName = QFileDialog::getSaveFileName(this, "Zapisz konfigurację", "", "Pliki tekstowe (*.txt)");
    if (fileName.isEmpty()) return;

    QFile file(fileName);
    if (!file.open(QIODevice::WriteOnly | QIODevice::Text)) return;

    QTextStream out(&file);
    out << "Amplituda=" << ui->spinBoxAmplituda->value() << "\n";
    out << "Okres=" << ui->spinBoxOkres->value() << "\n";
    out << "Wypelnienie=" << ui->spinBoxWypelnienie->value() << "\n";
    out << "TypSygnalu=" << ui->signalTypeComboBox->currentIndex() << "\n";
    out << "K=" << ui->spinBoxK->value() << "\n";
    out << "Ti=" << ui->spinBoxTi->value() << "\n";
    out << "Td=" << ui->spinBoxTd->value() << "\n";
    out << "Interwal=" << ui->spinBoxInterwal->value() << "\n";
    out << "Zaklocenie=" << zaklocenieStart << "\n";
    out << "Opoznienie=" << opoznienieStart << "\n";

    for (int i = 0; i < wspAstart.size(); ++i)
        out << "A" << (i + 1) << "=" << wspAstart[i] << "\n";
    for (int i = 0; i < wspBstart.size(); ++i)
        out << "B" << (i + 1) << "=" << wspBstart[i] << "\n";

    file.close();
}

void MainWindow::loadConfiguration() {
    QString fileName = QFileDialog::getOpenFileName(this, "Wczytaj konfigurację", "", "Pliki tekstowe (*.txt)");
    if (fileName.isEmpty()) return;

    QFile file(fileName);
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) return;

    QTextStream in(&file);
    while (!in.atEnd()) {
        QString line = in.readLine();
        QStringList parts = line.split('=');
        if (parts.size() == 2) {
            QString key = parts[0].trimmed();
            double value = parts[1].trimmed().toDouble();

            if (key == "Amplituda") {
                ui->spinBoxAmplituda->setValue(value);
                if (uklad) uklad->getGenerator().setAmplituda(value);
            }
            else if (key.startsWith("A")) {
                bool ok;
                int index = key.mid(1).toInt(&ok) - 1;
                if (ok && index >= 0 && index < wspAstart.size())
                    wspAstart[index] = value;
            }
            else if (key.startsWith("B")) {
                bool ok;
                int index = key.mid(1).toInt(&ok) - 1;
                if (ok && index >= 0 && index < wspBstart.size())
                    wspBstart[index] = value;
            }
            else if (key == "K") {
                ui->spinBoxK->setValue(value);
                if (uklad) uklad->getRegulator().setK(value);
            }
            else if (key == "Ti") {
                ui->spinBoxTi->setValue(value);
                if (uklad) uklad->getRegulator().setTi(value);
            }
            else if (key == "Td") {
                ui->spinBoxTd->setValue(value);
                if (uklad) uklad->getRegulator().setTd(value);
            }
            else if (key == "Interwal") {
                ui->spinBoxInterwal->setValue(static_cast<int>(value));
                if (timer->isActive()) timer->setInterval(static_cast<int>(value));
            }
            else if (key == "Okres") {
                ui->spinBoxOkres->setValue(value);
                if (uklad) uklad->getGenerator().setOkres(value);
            }
            else if (key == "Wypelnienie") {
                ui->spinBoxWypelnienie->setValue(value);
                if (uklad) uklad->getGenerator().setWypelnienie(value);
            }
            else if (key == "TypSygnalu") {
                int index = static_cast<int>(value);
                ui->signalTypeComboBox->setCurrentIndex(index);
                if (uklad) {
                    switch (index) {
                    case 0: typSygnalu = TypSygnalu::SkokJednostkowy; break;
                    case 1: typSygnalu = TypSygnalu::Prostokatny; break;
                    case 2: typSygnalu = TypSygnalu::Sinusoidalny; break;
                    default: typSygnalu = TypSygnalu::SkokJednostkowy; break;
                    }
                    uklad->getGenerator().setTypSygnalu(typSygnalu);
                }
            }
            else if (key == "Zaklocenie") {
                zaklocenieStart = value;
            }
            else if (key == "Opoznienie") {
                opoznienieStart = static_cast<int>(value);
            }
        }
    }

    file.close();
}
