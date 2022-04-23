#include <iostream>
#include <gtest/gtest.h>
#include "unique_ptr.h"
#include <memory>

int main(int argc, char **argv)
{
    if (true) // make false to run unit-tests
    {
        UniquePtr<int> ptr{new int{10}};
        UniquePtr<int> ptr1{make_unique<int>(10)};
        // //std::cout<< *ptr << std::endl;
        // int a = 5;
        // int* p = &a;
        
    }
    else
    {
        ::testing::InitGoogleTest(&argc, argv);
        std::cout << "RUNNING TESTS ..." << std::endl;
        int ret{RUN_ALL_TESTS()};
        if (!ret)
            std::cout << "<<<SUCCESS>>>" << std::endl;
        else
            std::cout << "FAILED" << std::endl;
    }
    return 0;   
}