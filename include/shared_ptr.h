#ifndef SHARED_PTR
#define SHARED_PTR


template<typename T>
class SharedPtr
{
    public:
        SharedPtr(T* ptr);
        SharedPtr();
        ~SharedPtr();
        SharedPtr(const SharedPtr<T>& ptr);
        T* get();
        SharedPtr<T>& operator=(const SharedPtr<T> ptr);
        int use_count();
        T& operator*();
        T* operator->();
        void reset();
        void reset(T* ptr);
        operator bool();

    private:
    T* _p; 
    int* count;
};

#include "shared_ptr.hpp"
#endif //SHARED_PTR