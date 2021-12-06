#include <gtest/gtest.h>
#include <iostream>

#include "calc.h"

TEST(test, t1){
    std::string post = "53+62/*35*+";
    Calculator c1(post);
    double a = 4, b = 8, c = 0;
    try{
        ASSERT_TRUE(c1.parseInput() == 39);
    }
    catch (const char *error){
        std::cerr << error << std::endl;
    }
    ASSERT_TRUE(c1.operation(a, b, '+') == (a + b));
    ASSERT_TRUE(c1.operation(a, b, '-') == (a - b));
    try{
        ASSERT_TRUE(c1.operation(a, b, '/') == (a / b));
        ASSERT_TRUE(c1.operation(a, c, '/'));
    }
    catch (const char *error){
        std::cerr << error << std::endl;
    }
    ASSERT_TRUE(c1.operation(a, b, '*') == (a * b));
    ASSERT_TRUE(c1.operation(a, b, '^') == std::pow(a, b));
    ASSERT_TRUE(c1.operation(a, "sin") == std::sin(a));

    ASSERT_TRUE(c1.operation(a, b, '+') == 12);
    ASSERT_TRUE(c1.operation(a, b, '-') == (-4));
    ASSERT_TRUE(c1.operation(a, b, '/') == 0.5);
}
TEST(test, basic_operations){
    std::string post = "53+62/*35*+";
    Calculator c1(post);
    try{
        ASSERT_TRUE(c1.parseInput() == 39);
    }
    catch (const char *error){
        std::cerr << error << std::endl;
    }
}

TEST(test, sin){
    std::string post = "3sin60+43-*";
    Calculator c1(post);
    bool is_valid = (c1.parseInput() == 6);
    ASSERT_TRUE(is_valid) << "Bledne obliczenia -> 3sin60+43-*";
}

TEST(test, log){
    std::string post = "3log1000*23+-";
    Calculator c1(post);
    bool is_valid = (c1.parseInput() == -5)  ;
    ASSERT_TRUE(is_valid) << "Bledne obliczenia -> 3log1000*23+-*";
}
