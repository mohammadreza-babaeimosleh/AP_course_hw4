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
