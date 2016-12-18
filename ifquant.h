#ifndef IFQUANT_H
#define IFQUANT_H

#include <QMainWindow>

namespace Ui {
class ifquant;
}

class ifquant : public QMainWindow
{
    Q_OBJECT

public:
    explicit ifquant(QWidget *parent = 0);
    ~ifquant();

private:
    Ui::ifquant *ui;
};

#endif // IFQUANT_H
