template<typename T>
UniquePtr<T>::UniquePtr(T* ptr) //constructor
    : _p{ ptr }
{
}


template<typename T>
UniquePtr<T>::UniquePtr() //defualt constructor
    : _p{ nullptr }
{
}


template<typename T>
T* make_unique(T ptr_destination) //external function
{
    T* ptr{ new T{ ptr_destination } };
    return ptr;
}


template<typename T>
UniquePtr<T>::~UniquePtr() // destructor
{
    delete _p;
    _p = nullptr;
}


template<typename T>
T* UniquePtr<T>::get() //getter
{
    return _p;
}


template<typename T>
T& UniquePtr<T>::operator*() 
{
    return *_p;
}


template<typename T>
T* UniquePtr<T>::operator->()
{
    return _p;
}


template<typename T>
void UniquePtr<T>::reset()
{
    delete _p;
    _p = nullptr; // for avoiding double free error
}


template<typename T>
void UniquePtr<T>::reset(T* ptr)
{
    reset();
    _p = ptr;
}


template<typename T>
UniquePtr<T>::operator bool()
{
    if(_p == nullptr)
    {
        return false;
    }
    else
    {
        return true;
    }
}


template<typename T>
T* UniquePtr<T>::release()
{
    T* tmp{ _p }; 
    _p = nullptr;
    return tmp;
}







