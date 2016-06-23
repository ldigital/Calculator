#ifndef CALCULATOR_H
#define CALCULATOR_H

#include <QMainWindow>
#include "calculator_data.h"
#include <QLCDNumber>

namespace Ui {
class Calculator;
}

class Calculator : public QMainWindow
{
    Q_OBJECT

public:   
    explicit Calculator(QWidget *parent = 0);
    ~Calculator();
    QLCDNumber * get_display(); //getter for LCD of calculator

private slots:
    void on_pushButton_clicked();
    void on_pushButton_2_clicked();
    void on_pushButton_3_clicked();
    void on_pushButton_4_clicked();
    void on_pushButton_5_clicked();
    void on_pushButton_6_clicked();
    void on_pushButton_7_clicked();
    void on_pushButton_8_clicked();
    void on_pushButton_9_clicked();
    void on_pushButton_10_clicked();
    void on_pushButton_11_clicked();
    void on_pushButton_12_clicked();
    void on_pushButton_13_clicked();
    void on_pushButton_14_clicked();
    void on_pushButton_15_clicked();
    void on_pushButton_16_clicked();
    void on_pushButton_17_clicked();
    void on_pushButton_18_clicked();

private:
    Ui::Calculator *ui;
    calculator_data send; //object to send data for processing
};

#endif // CALCULATOR_H
