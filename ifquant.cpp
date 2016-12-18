#include "ifquant.h"
#include "ui_ifquant.h"

ifquant::ifquant(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::ifquant)
{
    ui->setupUi(this);
}

ifquant::~ifquant()
{
    delete ui;
}
