#include "chooselevelscene.h"
#include "ui_chooselevelscene.h"

ChooseLevelScene::ChooseLevelScene(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::ChooseLevelScene)
{
    ui->setupUi(this);
}

ChooseLevelScene::~ChooseLevelScene()
{
    delete ui;
}
