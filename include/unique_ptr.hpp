template<typename T>
UniquePtr<T>::UniquePtr(T* ptr)
    : _p{ ptr }
{
    std::cout << "unique_ptr constructor" << std::endl;
}


template<typename T>
UniquePtr<T>::UniquePtr()
    : _p{nullptr}
{
    std::cout << "unique_ptr default constructor" << std::endl;
}


template<typename T>
T* make_unique(T ptr_destination)
{
    std::cout << "contructing through make" << std::endl;
    T* ptr{new T{ptr_destination}};
    return ptr;
}


template<typename T>
UniquePtr<T>::~UniquePtr()
{
    std::cout << "unique_ptr distructor" << std::endl;
    delete _p;
    _p = nullptr;
}


template<typename T>
T* UniquePtr<T>::get()
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
    _p = nullptr;
}


template<typename T>
void UniquePtr<T>::reset(T* ptr)
{
    reset();
    _p = ptr;
}




