#include <calculator.h>
#include <ui_calculator.h>
#include <calculator_data.h>
#include <vector>
#include <sstream>

//This is class solely for processing data from the ui. It recieves data sent by the signals, procceses it, then saves to a static
//variable for retrieval by the ui.

/*data is stored and displayed as a string. This is because we need to create a stream of data when displaying what the user has input
in real time (like a normal calculator). To do this I decided to save all button character strings to a vector to represent each character
then when displaying I can link each string to the next without performing sum of data -- which is what would happen if I had used double
 to start with.*/

std::string calculator_data::_streamDisplay;
QString calculator_data::_Q_display_sum;

void calculator_data::set_vec(std::string val){
    _vec.push_back(val);
    for(unsigned int i = 0; i < _vec.size(); i++){
        val = _vec[i];
    }
    _streamDisplay += val;
}

//the above code handles all streaming of user input ready to be displayed back
//the code below is activated whenever the = sign is pressed to get the sum of data.

void calculator_data::process_data(){
    std::string vector_contents; //save contents of vector to a string for further processing
    std::string display_sum;
    double num1, num2, sum;
    std::string first, second;  //need to split the string into two halves to get the two numbers
    bool is_found_add = false;
    bool is_found_subtract = false;
    bool is_found_multiply = false;
    bool is_found_divide = false;

    for(unsigned int i = 0; i < _vec.size(); i++){
        vector_contents += _vec[i];
    }

    for(unsigned int i = vector_contents.find("+", 0); i != std::string::npos; i = vector_contents.find("+", i)){
        i++;
        is_found_add = true;
    }

    if(is_found_add){
       first = vector_contents.substr(0, vector_contents.find("+")); //start from beginning of store string, and copy contents of up to the operator. this will be the first number
       second = vector_contents.substr(vector_contents.find("+") + 1, std::string::npos); //from the operator, copy the rest of the contents till end of string. this will create second number.
       std::istringstream(first) >> num1; //now we need to convert the new numbers to numeric types for calculation
       std::istringstream(second) >> num2;
       sum = add(num1, num2); //when these numbers are numeric types they can be sent to the corresponding function for computation, and the result of that function will be saved in sum variable.
       std::ostringstream convert_to_string; //we need to convert the sum which is numeric, back to a string to be used in calling function, so we need to create object from ostringstream
       convert_to_string << sum; //read the numeric sum into the sstream to create string version of sum
       display_sum = convert_to_string.str(); //finally, copy the sstream object (which is a string) to the string passed by reference from the calling function. this will take immediate affect on that variable
    }

    //repeat process for all other operators...
    for(unsigned int i = vector_contents.find("-", 0); i != std::string::npos; i = vector_contents.find("-", i)){
        i++;
        is_found_subtract = true;
    }

    if(is_found_subtract){
       first = vector_contents.substr(0, vector_contents.find("-"));
       second = vector_contents.substr(vector_contents.find("-") + 1, std::string::npos);
       std::istringstream(first) >> num1;
       std::istringstream(second) >> num2;
       sum = subtract(num1, num2);
       std::ostringstream convert_to_string;
       convert_to_string << sum;
       display_sum = convert_to_string.str();
    }

    for(unsigned int i = vector_contents.find("*", 0); i != std::string::npos; i = vector_contents.find("*", i)){
           i++;
           is_found_multiply = true;
    }

    if(is_found_multiply){
       first = vector_contents.substr(0, vector_contents.find("*"));
       second = vector_contents.substr(vector_contents.find("*") + 1, std::string::npos);
       std::istringstream(first) >> num1;
       std::istringstream(second) >> num2;
       sum = multiply(num1, num2);
       std::ostringstream convert_to_string;
       convert_to_string << sum;
       display_sum = convert_to_string.str();
    }

    for(unsigned int i = vector_contents.find("/", 0); i != std::string::npos; i = vector_contents.find("/", i)){
         i++;
         is_found_divide = true;
    }

    if(is_found_divide){
        first = vector_contents.substr(0, vector_contents.find("/"));
        second = vector_contents.substr(vector_contents.find("/") + 1, std::string::npos);
        std::istringstream(first) >> num1;
        std::istringstream(second) >> num2;
        sum = divide(num1, num2);
        std::ostringstream convert_to_string;
        convert_to_string << sum;
           display_sum = convert_to_string.str();
       }

       _Q_display_sum = QString::fromStdString(display_sum);

}

void calculator_data::clear(){
    _vec.erase(_vec.begin(), _vec.end());
    std::string clear_all;

    for(unsigned int i = 0; i < _vec.size(); i++){
        clear_all += _vec[i];
    }
      _streamDisplay = clear_all;
}

void calculator_data::backspace(){
    if(_vec.size() > 0){
       _vec.pop_back();
       std::string backspace;

        for(unsigned int i = 0; i < _vec.size(); i++){
               backspace += _vec[i];
        }
        _streamDisplay = backspace;
     }
}

double calculator_data::add(double num1, double num2){
    double sum = num1 + num2;
    return sum;
}

double calculator_data::subtract(double num1, double num2){
    double sum = num1 - num2;
    return sum;
}

double calculator_data::multiply(double num1, double num2){
    double sum = num1 * num2;
    return sum;
}

double calculator_data::divide(double num1, double num2){
    double sum = num1 / num2;
    return sum;
}

std::vector<std::string> calculator_data::get_vec(){
    return _vec;
}

std::string calculator_data::get_streamDisplay(){
    return _streamDisplay;
}

QString calculator_data::get_Q_display_sum(){
    return _Q_display_sum;
}
