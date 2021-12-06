#include <iostream>
#include <optional>
#include <string>
#include <thread>
#include <gtest/gtest.h>
#include <stack>
#include "my_stack.h"

int main(int argc, char **argv)
{
    std::cout << "Task1" << std::endl;
    try{
        auto result = open_file("/david/projects");
    }
    catch(...){
        std::cout << "Blędna ścieżka!\nPodaj poprawną ;)" <<std::endl;
    }
    
    //GoogleTest
    std::cout << "Task2" << std::endl;
    testing::InitGoogleTest(&argc, argv);
    auto ret = RUN_ALL_TESTS();

    return ret;
}