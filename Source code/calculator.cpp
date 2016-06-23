#include <calculator.h>
#include <ui_calculator.h>
#include <sstream>
#include <QLCDNumber>

//This class is simply for ui purposes, and does not process data to do with the calculator functionality.
Calculator::Calculator(QWidget *parent):
    QMainWindow(parent),
    ui(new Ui::Calculator)
{
    ui->setupUi(this);
}

Calculator::~Calculator()
{
    delete ui;
}

void Calculator::on_pushButton_clicked(){
  /*send is an object to calculator_data class where all processing takes place.
    retrieved data needs to be converted from std::string to QString before it can be displayed.
    QLCDNumber class does not display some symbols and letters*/
    send.set_vec("1");
    QString qstr = QString::fromStdString(send.get_streamDisplay());
    ui->lcdNumber->display(qstr);
}

void Calculator::on_pushButton_2_clicked(){
    send.set_vec("2");
    QString qstr = QString::fromStdString(send.get_streamDisplay());
    ui->lcdNumber->display(qstr);
}

void Calculator::on_pushButton_3_clicked(){
    send.set_vec("3");
    QString qstr = QString::fromStdString(send.get_streamDisplay());
    ui->lcdNumber->display(qstr);
}

void Calculator::on_pushButton_4_clicked(){
   send.set_vec("4");
   QString qstr = QString::fromStdString(send.get_streamDisplay());
   ui->lcdNumber->display(qstr);
}

void Calculator::on_pushButton_5_clicked(){
   send.set_vec("5");
   QString qstr = QString::fromStdString(send.get_streamDisplay());
   ui->lcdNumber->display(qstr);
}

void Calculator::on_pushButton_6_clicked(){
   send.set_vec("6");
   QString qstr = QString::fromStdString(send.get_streamDisplay());
   ui->lcdNumber->display(qstr);
}

void Calculator::on_pushButton_7_clicked(){
   send.set_vec("7");
   QString qstr = QString::fromStdString(send.get_streamDisplay());
   ui->lcdNumber->display(qstr);
}

void Calculator::on_pushButton_8_clicked(){
   send.set_vec("8");
   QString qstr = QString::fromStdString(send.get_streamDisplay());
   ui->lcdNumber->display(qstr);
}

void Calculator::on_pushButton_9_clicked(){
   send.set_vec("9");
   QString qstr = QString::fromStdString(send.get_streamDisplay());
   ui->lcdNumber->display(qstr);
}

void Calculator::on_pushButton_10_clicked(){
    send.set_vec("0");
    QString qstr = QString::fromStdString(send.get_streamDisplay());
    ui->lcdNumber->display(qstr);
}

void Calculator::on_pushButton_11_clicked(){
    send.set_vec("+");
    QString qstr = QString::fromStdString(send.get_streamDisplay());
    ui->lcdNumber->display(qstr);
}

void Calculator::on_pushButton_12_clicked(){
    send.set_vec("-");
    QString qstr = QString::fromStdString(send.get_streamDisplay());
    ui->lcdNumber->display(qstr);
}

void Calculator::on_pushButton_13_clicked(){
    send.set_vec("*");
    QString qstr = QString::fromStdString(send.get_streamDisplay());
    ui->lcdNumber->display(qstr);
}

void Calculator::on_pushButton_14_clicked(){
    send.set_vec("/");
    QString qstr = QString::fromStdString(send.get_streamDisplay());
    ui->lcdNumber->display(qstr);
}

void Calculator::on_pushButton_15_clicked(){
    send.set_vec("=");
    send.process_data(); //when the user wants to find the sum the actual processing of data begins
    ui->lcdNumber->display(send.get_Q_display_sum());
}

void Calculator::on_pushButton_16_clicked(){
    send.set_vec(".");
    QString qstr = QString::fromStdString(send.get_streamDisplay());
    ui->lcdNumber->display(qstr);
}

void Calculator::on_pushButton_17_clicked(){
    send.clear();
    QString qstr = QString::fromStdString(send.get_streamDisplay());
    ui->lcdNumber->display(qstr);
}

void Calculator::on_pushButton_18_clicked(){
    send.backspace();
    QString qstr = QString::fromStdString(send.get_streamDisplay());
    ui->lcdNumber->display(qstr);
}

QLCDNumber * Calculator::get_display(){
    return ui->lcdNumber;
}
