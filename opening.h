#ifndef OPENING_H
#define OPENING_H

#include <QMainWindow>

namespace Ui {
class Opening;
}

class Opening : public QMainWindow
{
    Q_OBJECT

public:
    explicit Opening(QWidget *parent = nullptr);
    ~Opening();

private:
    Ui::Opening *ui;
};

#endif // OPENING_H
