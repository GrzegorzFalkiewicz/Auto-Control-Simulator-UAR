/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.6.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDoubleSpinBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QGridLayout *gridLayout;
    QGridLayout *gridLayout_2;
    QLabel *label_5;
    QLabel *label_6;
    QDoubleSpinBox *spinBoxTi;
    QDoubleSpinBox *spinBoxK;
    QDoubleSpinBox *spinBoxTd;
    QLabel *label_7;
    QVBoxLayout *verticalLayoutPID;
    QVBoxLayout *verticalLayoutUchyb;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QPushButton *startButton;
    QPushButton *wznowButton;
    QPushButton *stopButton;
    QPushButton *resetButton;
    QGridLayout *gridLayout_3;
    QDoubleSpinBox *spinBoxAmplituda;
    QLabel *label_8;
    QLabel *label_10;
    QDoubleSpinBox *spinBoxWypelnienie;
    QDoubleSpinBox *spinBoxOkres;
    QLabel *label_9;
    QGridLayout *gridLayout_5;
    QSpinBox *spinBoxInterwal;
    QComboBox *signalTypeComboBox;
    QLabel *label_14;
    QVBoxLayout *verticalLayout_2;
    QPushButton *saveButton;
    QPushButton *loadButton;
    QHBoxLayout *horizontalLayout_2;
    QPushButton *pushButtonARX;
    QComboBox *comboBoxSposobCalkowania;
    QPushButton *pushButtonResetCalka;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(1280, 720);
        MainWindow->setMinimumSize(QSize(1280, 720));
        MainWindow->setMaximumSize(QSize(3840, 2160));
        QFont font;
        font.setFamilies({QString::fromUtf8("Arial")});
        font.setBold(true);
        MainWindow->setFont(font);
        MainWindow->setLayoutDirection(Qt::LayoutDirection::LeftToRight);
        MainWindow->setAutoFillBackground(true);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        gridLayout = new QGridLayout(centralwidget);
        gridLayout->setObjectName("gridLayout");
        gridLayout_2 = new QGridLayout();
        gridLayout_2->setObjectName("gridLayout_2");
        label_5 = new QLabel(centralwidget);
        label_5->setObjectName("label_5");
        label_5->setAutoFillBackground(true);
        label_5->setAlignment(Qt::AlignmentFlag::AlignCenter);

        gridLayout_2->addWidget(label_5, 0, 1, 1, 1);

        label_6 = new QLabel(centralwidget);
        label_6->setObjectName("label_6");
        label_6->setMaximumSize(QSize(16777215, 300));
        label_6->setAutoFillBackground(true);
        label_6->setAlignment(Qt::AlignmentFlag::AlignCenter);

        gridLayout_2->addWidget(label_6, 0, 2, 1, 1);

        spinBoxTi = new QDoubleSpinBox(centralwidget);
        spinBoxTi->setObjectName("spinBoxTi");
        spinBoxTi->setAutoFillBackground(true);
        spinBoxTi->setMinimum(-100.000000000000000);
        spinBoxTi->setMaximum(100.000000000000000);
        spinBoxTi->setSingleStep(0.100000000000000);
        spinBoxTi->setValue(5.000000000000000);

        gridLayout_2->addWidget(spinBoxTi, 1, 2, 1, 1);

        spinBoxK = new QDoubleSpinBox(centralwidget);
        spinBoxK->setObjectName("spinBoxK");
        spinBoxK->setAutoFillBackground(true);
        spinBoxK->setMinimum(-100.000000000000000);
        spinBoxK->setMaximum(100.000000000000000);
        spinBoxK->setSingleStep(0.100000000000000);
        spinBoxK->setValue(0.500000000000000);

        gridLayout_2->addWidget(spinBoxK, 1, 1, 1, 1);

        spinBoxTd = new QDoubleSpinBox(centralwidget);
        spinBoxTd->setObjectName("spinBoxTd");
        spinBoxTd->setAutoFillBackground(true);
        spinBoxTd->setMinimum(-100.000000000000000);
        spinBoxTd->setMaximum(100.000000000000000);
        spinBoxTd->setSingleStep(0.100000000000000);
        spinBoxTd->setValue(0.200000000000000);

        gridLayout_2->addWidget(spinBoxTd, 1, 3, 1, 1);

        label_7 = new QLabel(centralwidget);
        label_7->setObjectName("label_7");
        QSizePolicy sizePolicy(QSizePolicy::Policy::Preferred, QSizePolicy::Policy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(label_7->sizePolicy().hasHeightForWidth());
        label_7->setSizePolicy(sizePolicy);
        label_7->setMinimumSize(QSize(0, 50));
        label_7->setLayoutDirection(Qt::LayoutDirection::LeftToRight);
        label_7->setAutoFillBackground(true);
        label_7->setFrameShape(QFrame::Shape::NoFrame);
        label_7->setAlignment(Qt::AlignmentFlag::AlignCenter);

        gridLayout_2->addWidget(label_7, 0, 3, 1, 1);


        gridLayout->addLayout(gridLayout_2, 3, 0, 1, 1);

        verticalLayoutPID = new QVBoxLayout();
        verticalLayoutPID->setObjectName("verticalLayoutPID");

        gridLayout->addLayout(verticalLayoutPID, 3, 1, 2, 1);

        verticalLayoutUchyb = new QVBoxLayout();
        verticalLayoutUchyb->setObjectName("verticalLayoutUchyb");

        gridLayout->addLayout(verticalLayoutUchyb, 3, 2, 2, 1);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName("verticalLayout");
        verticalLayout->setSizeConstraint(QLayout::SizeConstraint::SetDefaultConstraint);

        gridLayout->addLayout(verticalLayout, 0, 1, 3, 2);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName("horizontalLayout");
        startButton = new QPushButton(centralwidget);
        startButton->setObjectName("startButton");
        startButton->setMinimumSize(QSize(0, 100));
        startButton->setAutoFillBackground(true);

        horizontalLayout->addWidget(startButton);

        wznowButton = new QPushButton(centralwidget);
        wznowButton->setObjectName("wznowButton");
        wznowButton->setMinimumSize(QSize(0, 100));
        wznowButton->setAutoFillBackground(true);

        horizontalLayout->addWidget(wznowButton);

        stopButton = new QPushButton(centralwidget);
        stopButton->setObjectName("stopButton");
        stopButton->setMinimumSize(QSize(0, 100));
        stopButton->setAutoFillBackground(true);

        horizontalLayout->addWidget(stopButton);

        resetButton = new QPushButton(centralwidget);
        resetButton->setObjectName("resetButton");
        resetButton->setMinimumSize(QSize(0, 100));
        resetButton->setAutoFillBackground(true);

        horizontalLayout->addWidget(resetButton);


        gridLayout->addLayout(horizontalLayout, 4, 0, 1, 1);

        gridLayout_3 = new QGridLayout();
        gridLayout_3->setObjectName("gridLayout_3");
        spinBoxAmplituda = new QDoubleSpinBox(centralwidget);
        spinBoxAmplituda->setObjectName("spinBoxAmplituda");
        spinBoxAmplituda->setMinimumSize(QSize(134, 23));
        spinBoxAmplituda->setDecimals(2);
        spinBoxAmplituda->setMaximum(100.000000000000000);
        spinBoxAmplituda->setSingleStep(0.100000000000000);
        spinBoxAmplituda->setValue(1.000000000000000);

        gridLayout_3->addWidget(spinBoxAmplituda, 1, 0, 1, 1);

        label_8 = new QLabel(centralwidget);
        label_8->setObjectName("label_8");
        QSizePolicy sizePolicy1(QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Minimum);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(label_8->sizePolicy().hasHeightForWidth());
        label_8->setSizePolicy(sizePolicy1);
        label_8->setMinimumSize(QSize(134, 123));
        label_8->setLayoutDirection(Qt::LayoutDirection::LeftToRight);
        label_8->setAutoFillBackground(true);
        label_8->setLineWidth(2);
        label_8->setAlignment(Qt::AlignmentFlag::AlignCenter);

        gridLayout_3->addWidget(label_8, 0, 0, 1, 1);

        label_10 = new QLabel(centralwidget);
        label_10->setObjectName("label_10");
        label_10->setMinimumSize(QSize(134, 123));
        label_10->setAutoFillBackground(true);
        label_10->setAlignment(Qt::AlignmentFlag::AlignCenter);

        gridLayout_3->addWidget(label_10, 0, 2, 1, 1);

        spinBoxWypelnienie = new QDoubleSpinBox(centralwidget);
        spinBoxWypelnienie->setObjectName("spinBoxWypelnienie");
        spinBoxWypelnienie->setMinimumSize(QSize(134, 23));
        spinBoxWypelnienie->setMaximum(1.000000000000000);
        spinBoxWypelnienie->setSingleStep(0.010000000000000);
        spinBoxWypelnienie->setValue(0.500000000000000);

        gridLayout_3->addWidget(spinBoxWypelnienie, 1, 2, 1, 1);

        spinBoxOkres = new QDoubleSpinBox(centralwidget);
        spinBoxOkres->setObjectName("spinBoxOkres");
        spinBoxOkres->setMinimumSize(QSize(135, 23));
        spinBoxOkres->setMinimum(0.000000000000000);
        spinBoxOkres->setMaximum(100.000000000000000);
        spinBoxOkres->setSingleStep(0.100000000000000);
        spinBoxOkres->setValue(10.000000000000000);

        gridLayout_3->addWidget(spinBoxOkres, 1, 1, 1, 1);

        label_9 = new QLabel(centralwidget);
        label_9->setObjectName("label_9");
        label_9->setMinimumSize(QSize(135, 123));
        label_9->setAutoFillBackground(true);
        label_9->setAlignment(Qt::AlignmentFlag::AlignCenter);

        gridLayout_3->addWidget(label_9, 0, 1, 1, 1);


        gridLayout->addLayout(gridLayout_3, 0, 0, 1, 1);

        gridLayout_5 = new QGridLayout();
        gridLayout_5->setObjectName("gridLayout_5");
        gridLayout_5->setSizeConstraint(QLayout::SizeConstraint::SetMinimumSize);
        spinBoxInterwal = new QSpinBox(centralwidget);
        spinBoxInterwal->setObjectName("spinBoxInterwal");
        spinBoxInterwal->setMinimumSize(QSize(0, 60));
        spinBoxInterwal->setAutoFillBackground(true);
        spinBoxInterwal->setMinimum(50);
        spinBoxInterwal->setMaximum(1000);
        spinBoxInterwal->setValue(200);

        gridLayout_5->addWidget(spinBoxInterwal, 0, 2, 1, 1);

        signalTypeComboBox = new QComboBox(centralwidget);
        signalTypeComboBox->setObjectName("signalTypeComboBox");
        signalTypeComboBox->setMinimumSize(QSize(0, 60));
        signalTypeComboBox->setAutoFillBackground(true);

        gridLayout_5->addWidget(signalTypeComboBox, 0, 0, 1, 1);

        label_14 = new QLabel(centralwidget);
        label_14->setObjectName("label_14");
        label_14->setMinimumSize(QSize(0, 60));
        label_14->setLayoutDirection(Qt::LayoutDirection::RightToLeft);
        label_14->setAutoFillBackground(true);
        label_14->setAlignment(Qt::AlignmentFlag::AlignCenter);

        gridLayout_5->addWidget(label_14, 0, 1, 1, 1);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName("verticalLayout_2");
        saveButton = new QPushButton(centralwidget);
        saveButton->setObjectName("saveButton");

        verticalLayout_2->addWidget(saveButton);

        loadButton = new QPushButton(centralwidget);
        loadButton->setObjectName("loadButton");

        verticalLayout_2->addWidget(loadButton);


        gridLayout_5->addLayout(verticalLayout_2, 0, 3, 1, 1);


        gridLayout->addLayout(gridLayout_5, 1, 0, 1, 1);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        pushButtonARX = new QPushButton(centralwidget);
        pushButtonARX->setObjectName("pushButtonARX");
        pushButtonARX->setMinimumSize(QSize(0, 80));

        horizontalLayout_2->addWidget(pushButtonARX);

        comboBoxSposobCalkowania = new QComboBox(centralwidget);
        comboBoxSposobCalkowania->addItem(QString());
        comboBoxSposobCalkowania->addItem(QString());
        comboBoxSposobCalkowania->setObjectName("comboBoxSposobCalkowania");
        comboBoxSposobCalkowania->setMinimumSize(QSize(0, 80));

        horizontalLayout_2->addWidget(comboBoxSposobCalkowania);

        pushButtonResetCalka = new QPushButton(centralwidget);
        pushButtonResetCalka->setObjectName("pushButtonResetCalka");
        pushButtonResetCalka->setMinimumSize(QSize(0, 80));

        horizontalLayout_2->addWidget(pushButtonResetCalka);


        gridLayout->addLayout(horizontalLayout_2, 2, 0, 1, 1);

        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 1280, 19));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "UAR - PROJEKT", nullptr));
        label_5->setText(QCoreApplication::translate("MainWindow", "k", nullptr));
        label_6->setText(QCoreApplication::translate("MainWindow", "Ti", nullptr));
        label_7->setText(QCoreApplication::translate("MainWindow", "Td", nullptr));
        startButton->setText(QCoreApplication::translate("MainWindow", "ZADAJ ", nullptr));
        wznowButton->setText(QCoreApplication::translate("MainWindow", "START", nullptr));
        stopButton->setText(QCoreApplication::translate("MainWindow", "STOP", nullptr));
        resetButton->setText(QCoreApplication::translate("MainWindow", "RESET", nullptr));
        label_8->setText(QCoreApplication::translate("MainWindow", "AMPLITUDA", nullptr));
        label_10->setText(QCoreApplication::translate("MainWindow", "WYPELNIENIE", nullptr));
        label_9->setText(QCoreApplication::translate("MainWindow", "OKRES", nullptr));
        label_14->setText(QCoreApplication::translate("MainWindow", "INTERWA\305\201", nullptr));
        saveButton->setText(QCoreApplication::translate("MainWindow", "ZAPISZ", nullptr));
        loadButton->setText(QCoreApplication::translate("MainWindow", "WGRAJ", nullptr));
        pushButtonARX->setText(QCoreApplication::translate("MainWindow", "ARX", nullptr));
        comboBoxSposobCalkowania->setItemText(0, QCoreApplication::translate("MainWindow", "Ti poza ca\305\202k\304\205", nullptr));
        comboBoxSposobCalkowania->setItemText(1, QCoreApplication::translate("MainWindow", "Ti pod ca\305\202k\304\205", nullptr));

        pushButtonResetCalka->setText(QCoreApplication::translate("MainWindow", "Resetuj cz\304\231\305\233\304\207 ca\305\202kuj\304\205c\304\205", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
