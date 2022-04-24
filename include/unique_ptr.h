
#ifndef UNIQUE_PTR
#define UNIQUE_PTR

template<typename T>
class UniquePtr
{
    public:
    UniquePtr(T* ptr);
    UniquePtr();
    ~UniquePtr();
    UniquePtr(const UniquePtr<T>&) = delete;
    UniquePtr<T>& operator=(const UniquePtr<T>) = delete;
    T* get();
    T& operator*();
    T* operator->();
    void reset();
    void reset(T* ptr);
    operator bool();
    T* release();

  

    private:
        T* _p;
};







#include "unique_ptr.hpp"

#endif //UNIQUE_PTR