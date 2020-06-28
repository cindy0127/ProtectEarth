#include "opening.h"
#include "ui_opening.h"

Opening::Opening(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Opening)
{
    ui->setupUi(this);
}

Opening::~Opening()
{
    delete ui;
}
