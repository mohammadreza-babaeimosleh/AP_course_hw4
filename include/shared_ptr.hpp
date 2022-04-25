template<typename T>
SharedPtr<T>::SharedPtr(T* ptr)
    : _p{ptr} 
    , count{ new int{1} }
{
    std::cout<< "sharedPtr constructor" << std::endl;
}


template<typename T>
T* make_shared(T ptr_destination)
{
    std::cout << "contructing shared through make" << std::endl;
    T* ptr{ new T{ ptr_destination } };
    return ptr;
}


template<typename T>
SharedPtr<T>::SharedPtr()
    : _p{ nullptr }
    , count{ new int{0} }
{
    std::cout << "shared_ptr default constructor" << std::endl;
}


template<typename T>
SharedPtr<T>::~SharedPtr()
{
    std::cout << "sharedPtr distructor" << std::endl;
    *count = *count - 1;
    if(*count == 0)
    {
        delete _p;
        _p = nullptr;
    }
    else
    {
        _p = nullptr;
    }
}


template<typename T>
T* SharedPtr<T>::get()
{
    return _p;
}


template<typename T>
SharedPtr<T>::SharedPtr(const SharedPtr<T>& ptr)
{
    std::cout << "sharedPtr copy constructor" << std::endl;
    _p = ptr._p;
    count = ptr.count;
    *count = *count + 1;
}


template<typename T>
SharedPtr<T>& SharedPtr<T>::operator=(const SharedPtr<T> ptr)
{
    std::cout << "sharedPtr = operator" << std::endl;
    if(this == &ptr)
    {
        return *this;
    }

    if(_p != ptr._p)
    {
        if(*count == 1)
        {
            delete _p;
            _p = ptr._p;
            delete count;
        }
        count = ptr.count ;
        *count = *count + 1;
    }

    return *this;

}


template<typename T>
int SharedPtr<T>::use_count()
{
    return *count;
}


template<typename T>
T& SharedPtr<T>::operator*()
{
    return *_p;
}


template<typename T>
T* SharedPtr<T>::operator->()
{
    return _p;
}


template<typename T>
void SharedPtr<T>::reset()
{
    if(*count == 1 )
    {
        delete _p;
        delete count;
    }
    count = new int{0};
    _p = nullptr;
}


template<typename T>
void SharedPtr<T>::reset(T* ptr)
{
    reset();
    _p = ptr;
    *count = *count + 1;
}


template<typename T>
SharedPtr<T>::operator bool()
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



