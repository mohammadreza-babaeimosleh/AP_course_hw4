
#ifndef UNIQUE_PTR
#define UNIQUE_PTR

template<typename T>
class UniquePtr
{
    public:
    UniquePtr(T* p);
    UniquePtr();
    ~UniquePtr();
    UniquePtr(const UniquePtr& ptr);
    UniquePtr<T>& operator=(const UniquePtr<T> ptr);
    T* get();
    T& operator*();

    private:
        T* _p;
};







#include "unique_ptr.hpp"

#endif //UNIQUE_PTR