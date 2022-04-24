#ifndef SHARED_PTR
#define SHARED_PTR


template<typename T>
class SharedPtr
{
    public:
        SharedPtr(T* ptr);
        SharedPtr();




    private:
    T* _p; 
};

#include "shared_ptr.hpp"
#endif //SHARED_PTR