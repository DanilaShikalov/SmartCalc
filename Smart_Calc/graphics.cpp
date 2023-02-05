#include "graphics.h"
#include "ui_graphics.h"

QString text;

Graphics::Graphics(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Graphics)
{
    ui->setupUi(this);

    chrt = new QChart;
        ui->vchrt->setChart(chrt);
        chrt->setTitle(text);
        QValueAxis *axisX = new QValueAxis;
        axisX->setRange(0, 10000);
        axisX->setTickCount(11);
        axisX->setLabelFormat("%.2f");
        // ось Y
        QValueAxis *axisY = new QValueAxis;
        axisY->setRange(-2.15, 2.15);
        axisY->setTickCount(3);
        axisY->setLabelFormat("%g");
        QLineSeries* series = new QLineSeries();
        QByteArray ba = text.toLocal8Bit();
        char *c_str2 = ba.data();
        int error = 0;
        for(int i = 0; i < 10000; i++)
        {
            series->append(i, parser_polish(c_str2, (double) i / 100, &error));
        }
        text = "";
        chrt->addSeries(series);
        chrt->setAxisX(axisX, series);
        chrt->setAxisY(axisY, series);
}

Graphics::~Graphics()
{
    delete ui;
}

void Graphics::setLabel(const QString& x)
{
    text = x;
}
