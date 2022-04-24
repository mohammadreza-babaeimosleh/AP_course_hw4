template<typename T>
SharedPtr<T>::SharedPtr(T* ptr)
    : _p{ptr} 
{
    std::cout<< "sharedPtr constructor" << std::endl;
}


template<typename T>
T* make_shared(T ptr_destination)
{
    std::cout << "contructing shared through make" << std::endl;
    T* ptr{new T{ptr_destination}};
    return ptr;
}


template<typename T>
SharedPtr<T>::SharedPtr()
    : _p{nullptr}
{
    std::cout << "shared_ptr default constructor" << std::endl;
}


template<typename T>
SharedPtr<T>::~SharedPtr()
{
    std::cout << "shaedePtr distructor" << std::endl;
    delete _p;
    _p = nullptr;
}


template<typename T>
T* SharedPtr<T>::get()
{
    return _p;
}


template<typename T>
SharedPtr<T>::SharedPtr(const SharedPtr<T>& ptr)
{
    std::cout << "sharedPtr copy distructor" << std::endl;
    _p = ptr.get();
}
