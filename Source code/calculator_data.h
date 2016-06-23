#ifndef CALCULATOR_DATA
#define CALCULATOR_DATA
#include <calculator.h>
#include <ui_calculator.h>
#include <vector>
#include <QLCDNumber>

//This is class solely for processing data from the ui. It recieves data sent by the signals, procceses it, then saves to a static
//variable for retrieval by the ui.

class calculator_data{

    public:
        calculator_data(){}
        ~calculator_data(){}
        void set_vec(std::string val);
        void process_data();
        double add(double num1, double num2);
        double subtract(double num1, double num2);
        double multiply(double num1, double num2);
        double divide(double num1, double num2);
        std::vector<std::string> get_vec();
        std::string get_streamDisplay();
        QString get_Q_display_sum();
        void clear();
        void backspace();

    private:
        calculator_data(const calculator_data & source){}
        calculator_data & operator=(const calculator_data & source){}
        std::vector<std::string> _vec;
        static std::string _streamDisplay;
        static QString _Q_display_sum;
        double _num1;
        double _num2;
};

#endif // CALCULATOR_DATA
