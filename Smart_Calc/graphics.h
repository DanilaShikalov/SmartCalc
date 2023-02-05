#ifndef GRAPHICS_H
#define GRAPHICS_H

#include <QDialog>
#include <QtCharts>

extern "C" {
#include "../graph.h"
}

namespace Ui {
class Graphics;
}

class Graphics : public QDialog
{
    Q_OBJECT

public:
    explicit Graphics(QWidget *parent = nullptr);
    ~Graphics();

private:
    Ui::Graphics *ui;

    QChart *chrt;


private slots:
public: void setLabel(const QString& x);
};

#endif // GRAPHICS_H
