#include "mainwindow.h"
#include "./ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->splitter->setStretchFactor(0, 4);
    ui->splitter->setStretchFactor(1, 1);
    QFont mono_font("Monospace");
    mono_font.setFamily("Menlo");
    ui->textEdit->setFont(mono_font);
}

MainWindow::~MainWindow()
{
    delete ui;
}

