#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "graphics.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    connect(ui->pushButton0,SIGNAL(clicked(bool)),this,SLOT(enter_symbols()));
    connect(ui->pushButton1,SIGNAL(clicked(bool)),this,SLOT(enter_symbols()));
    connect(ui->pushButton2,SIGNAL(clicked(bool)),this,SLOT(enter_symbols()));
    connect(ui->pushButton3,SIGNAL(clicked(bool)),this,SLOT(enter_symbols()));
    connect(ui->pushButton4,SIGNAL(clicked(bool)),this,SLOT(enter_symbols()));
    connect(ui->pushButton5,SIGNAL(clicked(bool)),this,SLOT(enter_symbols()));
    connect(ui->pushButton6,SIGNAL(clicked(bool)),this,SLOT(enter_symbols()));
    connect(ui->pushButton7,SIGNAL(clicked(bool)),this,SLOT(enter_symbols()));
    connect(ui->pushButton8,SIGNAL(clicked(bool)),this,SLOT(enter_symbols()));
    connect(ui->pushButton9,SIGNAL(clicked(bool)),this,SLOT(enter_symbols()));
    connect(ui->pushButtonSkobka1,SIGNAL(clicked(bool)),this,SLOT(enter_symbols()));
    connect(ui->pushButtonSkobka2,SIGNAL(clicked(bool)),this,SLOT(enter_symbols()));
    connect(ui->pushButtonX,SIGNAL(clicked(bool)),this,SLOT(enter_symbols()));
    connect(ui->pushButtonAC,SIGNAL(clicked(bool)),this,SLOT(reset_label()));
    connect(ui->pushButtonStepeni,SIGNAL(clicked(bool)),this,SLOT(enter_symbols()));
    connect(ui->pushButtonDiv,SIGNAL(clicked(bool)),this,SLOT(enter_symbols()));
    connect(ui->pushButtonMul,SIGNAL(clicked(bool)),this,SLOT(enter_symbols()));
    connect(ui->pushButtonSub,SIGNAL(clicked(bool)),this,SLOT(enter_symbols()));
    connect(ui->pushButtonSin,SIGNAL(clicked(bool)),this,SLOT(enter_symbols()));
    connect(ui->pushButtonCos,SIGNAL(clicked(bool)),this,SLOT(enter_symbols()));
    connect(ui->pushButtonTan,SIGNAL(clicked(bool)),this,SLOT(enter_symbols()));
    connect(ui->pushButtonAtan,SIGNAL(clicked(bool)),this,SLOT(enter_symbols()));
    connect(ui->pushButtonAcos,SIGNAL(clicked(bool)),this,SLOT(enter_symbols()));
    connect(ui->pushButtonAsin,SIGNAL(clicked(bool)),this,SLOT(enter_symbols()));
    connect(ui->pushButtonAdd,SIGNAL(clicked(bool)),this,SLOT(enter_symbols()));
    connect(ui->pushButtonLog,SIGNAL(clicked(bool)),this,SLOT(enter_symbols()));
    connect(ui->pushButtonSqrt,SIGNAL(clicked(bool)),this,SLOT(enter_symbols()));
    connect(ui->pushButtonMod,SIGNAL(clicked(bool)),this,SLOT(enter_symbols()));
    connect(ui->pushButtonRavno,SIGNAL(clicked(bool)),this,SLOT(calc()));
    connect(ui->pushButtonLn,SIGNAL(clicked(bool)),this,SLOT(enter_symbols()));
    connect(ui->pushButtonGrapihcs,SIGNAL(clicked(bool)),this,SLOT(get_graphics()));
    connect(ui->pushButtonDot,SIGNAL(clicked(bool)),this,SLOT(enter_symbols()));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::calc() {
    QString str1 = ui->labelText->text();
    QByteArray ba = str1.toLocal8Bit();
    char *c_str2 = ba.data();
    double result = calc_parser(c_str2);
    ui->labelAnswer->setText(QString::number(result));
    reset_label();
}

void MainWindow::reset_label() {
    ui->labelText->setText("");
}

void MainWindow::enter_symbols() {
    QPushButton* button = (QPushButton*)sender();
    ui->labelText->setText(ui->labelText->text() + button->text());
}

void MainWindow::get_graphics() {
    Graphics graphics;
    graphics.setLabel(ui->labelText->text());
    graphics.setModal(true);
    graphics.exec();
}
