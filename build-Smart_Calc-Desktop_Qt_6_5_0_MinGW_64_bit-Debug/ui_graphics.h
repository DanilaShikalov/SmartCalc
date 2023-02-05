/********************************************************************************
** Form generated from reading UI file 'graphics.ui'
**
** Created by: Qt User Interface Compiler version 6.5.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_GRAPHICS_H
#define UI_GRAPHICS_H

#include <QtCharts/QChartView>
#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>

QT_BEGIN_NAMESPACE

class Ui_Graphics
{
public:
    QChartView *vchrt;

    void setupUi(QDialog *Graphics)
    {
        if (Graphics->objectName().isEmpty())
            Graphics->setObjectName("Graphics");
        Graphics->resize(1160, 644);
        vchrt = new QChartView(Graphics);
        vchrt->setObjectName("vchrt");
        vchrt->setGeometry(QRect(0, 0, 1161, 641));

        retranslateUi(Graphics);

        QMetaObject::connectSlotsByName(Graphics);
    } // setupUi

    void retranslateUi(QDialog *Graphics)
    {
        Graphics->setWindowTitle(QCoreApplication::translate("Graphics", "Dialog", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Graphics: public Ui_Graphics {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_GRAPHICS_H
