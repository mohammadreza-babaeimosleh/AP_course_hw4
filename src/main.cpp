#include <iostream>
#include <gtest/gtest.h>
#include "unique_ptr.h"
#include <memory>

int main(int argc, char **argv)
{
    if (true) // make false to run unit-tests
    {
        UniquePtr<int> ptr1{new int{10}};
        UniquePtr<int> ptr2{new int{11}};
        UniquePtr<int> ptr{new int{10}};
        
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