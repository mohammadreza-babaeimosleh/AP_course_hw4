#include <iostream>
#include <gtest/gtest.h>
#include "unique_ptr.h"
#include <memory>

int main(int argc, char **argv)
{
    if (true) // make false to run unit-tests
    {
        UniquePtr<double> ptr{new double{1.567}};
        double *tmp{ptr.release()};
        std::cout << *tmp << std::endl; // output: 1.567
        delete tmp; // manual deletion
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