#include <iostream>
#include <vector>
#include <cmath>
#include <string>
#include <stack>

class Calculator
{
public:
    Calculator(const std::string &in) : input(in) {}

    bool isOp(const char &ch);
    bool isOp(const std::string &ch);
    bool isNum(const char &ch);

    double operation(const double &a, const double &b, const char &op);
    double operation(const double &a, const std::string &op);

    //log
    double log(const double &a, const double &b);
    
    //stack
    std::stack<double> rpn;
    double parseInput();

private:
    std::string input;
};