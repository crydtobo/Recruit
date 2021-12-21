#include <iostream>
#include <optional>
#include <string>
#include <thread>
#include <gtest/gtest.h>
#include <stack>
#include "my_stack.h"

//zdefiniuj sciezke do pliku/folderu ktpory chcesz sprawdzic 
#define pathToChechFile "/home/dawid/Projects/CodingGame/"


int main(int argc, char **argv)
{
    std::cout << "Task1" << std::endl;
    try{
        auto [files, folders] = numbersOfFilesAndFolders(pathToChechFile);
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