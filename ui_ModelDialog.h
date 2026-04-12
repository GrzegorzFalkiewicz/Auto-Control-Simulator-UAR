/********************************************************************************
** Form generated from reading UI file 'ModelDialog.ui'
**
** Created by: Qt User Interface Compiler version 6.6.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MODELDIALOG_H
#define UI_MODELDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAbstractButton>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QDoubleSpinBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_ModelDialog
{
public:
    QVBoxLayout *verticalLayout_6;
    QHBoxLayout *horizontalLayout;
    QVBoxLayout *verticalLayout;
    QLabel *labelA1;
    QLabel *labelA2;
    QLabel *labelA3;
    QVBoxLayout *verticalLayout_3;
    QDoubleSpinBox *spinBoxA1;
    QDoubleSpinBox *spinBoxA2;
    QDoubleSpinBox *spinBoxA3;
    QVBoxLayout *verticalLayout_2;
    QLabel *labelB1;
    QLabel *labelB2;
    QLabel *labelB3;
    QVBoxLayout *verticalLayout_4;
    QDoubleSpinBox *spinBoxB1;
    QDoubleSpinBox *spinBoxB2;
    QDoubleSpinBox *spinBoxB3;
    QVBoxLayout *verticalLayout_5;
    QHBoxLayout *horizontalLayout_2;
    QLabel *labelOpoznienie;
    QSpinBox *spinBoxOpoznienie;
    QHBoxLayout *horizontalLayout_3;
    QCheckBox *checkBoxZaklocenie;
    QDoubleSpinBox *doubleSpinBoxZaklocenie;
    QDialogButtonBox *buttonBox;

    void setupUi(QDialog *ModelDialog)
    {
        if (ModelDialog->objectName().isEmpty())
            ModelDialog->setObjectName("ModelDialog");
        ModelDialog->resize(392, 284);
        verticalLayout_6 = new QVBoxLayout(ModelDialog);
        verticalLayout_6->setObjectName("verticalLayout_6");
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName("horizontalLayout");
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName("verticalLayout");
        labelA1 = new QLabel(ModelDialog);
        labelA1->setObjectName("labelA1");

        verticalLayout->addWidget(labelA1);

        labelA2 = new QLabel(ModelDialog);
        labelA2->setObjectName("labelA2");

        verticalLayout->addWidget(labelA2);

        labelA3 = new QLabel(ModelDialog);
        labelA3->setObjectName("labelA3");

        verticalLayout->addWidget(labelA3);


        horizontalLayout->addLayout(verticalLayout);

        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setObjectName("verticalLayout_3");
        spinBoxA1 = new QDoubleSpinBox(ModelDialog);
        spinBoxA1->setObjectName("spinBoxA1");
        spinBoxA1->setMinimum(-10.000000000000000);
        spinBoxA1->setMaximum(10.000000000000000);
        spinBoxA1->setSingleStep(0.050000000000000);

        verticalLayout_3->addWidget(spinBoxA1);

        spinBoxA2 = new QDoubleSpinBox(ModelDialog);
        spinBoxA2->setObjectName("spinBoxA2");
        spinBoxA2->setMinimum(-10.000000000000000);
        spinBoxA2->setMaximum(10.000000000000000);
        spinBoxA2->setSingleStep(0.050000000000000);

        verticalLayout_3->addWidget(spinBoxA2);

        spinBoxA3 = new QDoubleSpinBox(ModelDialog);
        spinBoxA3->setObjectName("spinBoxA3");
        spinBoxA3->setMinimum(-10.000000000000000);
        spinBoxA3->setMaximum(10.000000000000000);
        spinBoxA3->setSingleStep(0.050000000000000);

        verticalLayout_3->addWidget(spinBoxA3);


        horizontalLayout->addLayout(verticalLayout_3);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName("verticalLayout_2");
        labelB1 = new QLabel(ModelDialog);
        labelB1->setObjectName("labelB1");

        verticalLayout_2->addWidget(labelB1);

        labelB2 = new QLabel(ModelDialog);
        labelB2->setObjectName("labelB2");

        verticalLayout_2->addWidget(labelB2);

        labelB3 = new QLabel(ModelDialog);
        labelB3->setObjectName("labelB3");

        verticalLayout_2->addWidget(labelB3);


        horizontalLayout->addLayout(verticalLayout_2);

        verticalLayout_4 = new QVBoxLayout();
        verticalLayout_4->setObjectName("verticalLayout_4");
        spinBoxB1 = new QDoubleSpinBox(ModelDialog);
        spinBoxB1->setObjectName("spinBoxB1");
        spinBoxB1->setSingleStep(0.050000000000000);

        verticalLayout_4->addWidget(spinBoxB1);

        spinBoxB2 = new QDoubleSpinBox(ModelDialog);
        spinBoxB2->setObjectName("spinBoxB2");
        spinBoxB2->setSingleStep(0.050000000000000);

        verticalLayout_4->addWidget(spinBoxB2);

        spinBoxB3 = new QDoubleSpinBox(ModelDialog);
        spinBoxB3->setObjectName("spinBoxB3");
        spinBoxB3->setSingleStep(0.050000000000000);

        verticalLayout_4->addWidget(spinBoxB3);


        horizontalLayout->addLayout(verticalLayout_4);


        verticalLayout_6->addLayout(horizontalLayout);

        verticalLayout_5 = new QVBoxLayout();
        verticalLayout_5->setObjectName("verticalLayout_5");
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        labelOpoznienie = new QLabel(ModelDialog);
        labelOpoznienie->setObjectName("labelOpoznienie");

        horizontalLayout_2->addWidget(labelOpoznienie);

        spinBoxOpoznienie = new QSpinBox(ModelDialog);
        spinBoxOpoznienie->setObjectName("spinBoxOpoznienie");
        spinBoxOpoznienie->setMinimum(1);
        spinBoxOpoznienie->setMaximum(100);

        horizontalLayout_2->addWidget(spinBoxOpoznienie);


        verticalLayout_5->addLayout(horizontalLayout_2);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName("horizontalLayout_3");
        checkBoxZaklocenie = new QCheckBox(ModelDialog);
        checkBoxZaklocenie->setObjectName("checkBoxZaklocenie");

        horizontalLayout_3->addWidget(checkBoxZaklocenie);

        doubleSpinBoxZaklocenie = new QDoubleSpinBox(ModelDialog);
        doubleSpinBoxZaklocenie->setObjectName("doubleSpinBoxZaklocenie");
        doubleSpinBoxZaklocenie->setMaximum(1.000000000000000);
        doubleSpinBoxZaklocenie->setSingleStep(0.010000000000000);

        horizontalLayout_3->addWidget(doubleSpinBoxZaklocenie);


        verticalLayout_5->addLayout(horizontalLayout_3);


        verticalLayout_6->addLayout(verticalLayout_5);

        buttonBox = new QDialogButtonBox(ModelDialog);
        buttonBox->setObjectName("buttonBox");
        buttonBox->setOrientation(Qt::Orientation::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::StandardButton::Cancel|QDialogButtonBox::StandardButton::Ok);

        verticalLayout_6->addWidget(buttonBox);


        retranslateUi(ModelDialog);
        QObject::connect(buttonBox, &QDialogButtonBox::accepted, ModelDialog, qOverload<>(&QDialog::accept));
        QObject::connect(buttonBox, &QDialogButtonBox::rejected, ModelDialog, qOverload<>(&QDialog::reject));

        QMetaObject::connectSlotsByName(ModelDialog);
    } // setupUi

    void retranslateUi(QDialog *ModelDialog)
    {
        ModelDialog->setWindowTitle(QCoreApplication::translate("ModelDialog", "Dialog", nullptr));
        labelA1->setText(QCoreApplication::translate("ModelDialog", "A1", nullptr));
        labelA2->setText(QCoreApplication::translate("ModelDialog", "A2", nullptr));
        labelA3->setText(QCoreApplication::translate("ModelDialog", "A3", nullptr));
        labelB1->setText(QCoreApplication::translate("ModelDialog", "B1", nullptr));
        labelB2->setText(QCoreApplication::translate("ModelDialog", "B2", nullptr));
        labelB3->setText(QCoreApplication::translate("ModelDialog", "B3", nullptr));
        labelOpoznienie->setText(QCoreApplication::translate("ModelDialog", "Op\303\263\305\272nienie:", nullptr));
        checkBoxZaklocenie->setText(QCoreApplication::translate("ModelDialog", "Zak\305\202\303\263cenie:", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ModelDialog: public Ui_ModelDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MODELDIALOG_H
