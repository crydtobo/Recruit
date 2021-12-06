#include "calc.h"

/*
Fucntions for Calculator in PRN
*/

bool Calculator::isOp(const char &ch)
{
    if (ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '^')
        return true;
    return false;
}

bool Calculator::isNum(const char &ch)
{
    if (ch >= '0' && ch <= '9')
        return true;
    return false;
}

bool Calculator::isOp(const std::string &ch)
{
    if ((ch.compare("sin") == 0) || (ch.compare("cos") == 0) || (ch.compare("ctg") == 0) ||
        (ch.compare("tg") == 0) || (ch.compare("log") == 0) || (ch.compare("log") == 0))
        return true;
    return false;
}

double Calculator::operation(const double &a, const double &b, const char &op)
{
    //perform
    switch (op)
    {
    case '+':
    {
        return a + b;
    }
    break;
    case '-':
    {
        return a - b;
    }
    break;
    case '*':
    {
        return a * b;
    }
    break;
    case '/':
    {
        if (b == 0)
            throw "Division by zero is impossible in this arithmetic!";
        return a / b;
    }
    break;
    case '^':
    {
        return std::pow(a, b);
    }
    break;
    default:
    {
        std::cout << "Unknow operand: " << op << std::endl;
        return 0.0;
    }
    }
    return 0.0;
}

// function to evaluate logarithm a base-b
double Calculator::log(const double &a, const double &b)
{
    return std::log2(a) / std::log2(b);
}

double Calculator::operation(const double &a, const std::string &op)
{
    //perform
    if (op == "sin")
        return std::sin(a);
    else if (op == "cos")
        return std::cos(a);
    else if (op == "tg")
        return std::tan(a);
    else if (op == "ctg")
        return std::atan(a);
    else if (op == "log")
        return std::log(a);
    else
    {
        std::cout << "Unknow operand: " << op << std::endl;
    }
    return 0.0;
}

double scanNum(char ch)
{
    double value;
    value = ch;
    return double(value - '0'); //return double from character
}

double Calculator::parseInput()
{
    double a, b;
    int i = 0, flaga = 0;
    std::string::iterator it;

    for (it = input.begin(); it != input.end(); it++)
    {
        if (isOp(*it) != false)
        {
            a = rpn.top();
            rpn.pop();
            b = rpn.top();
            rpn.pop();
            rpn.push(operation(b, a, *it));
            flaga = 1;
        }
        else if (isNum(*it) != false)
        {
            rpn.push(scanNum(*it));
            flaga = 1;
        }
        else if (*it != ' ' && ((i + 2) != input.size()))
        {
            std::string subOp = input.substr(i, i + 2);
            if (isOp(subOp) != false)
            {
                a = rpn.top();
                rpn.pop();
                rpn.push(operation(a, subOp));
            }
        }
        flaga = 0;
        i++;
    }
    return rpn.top();
}