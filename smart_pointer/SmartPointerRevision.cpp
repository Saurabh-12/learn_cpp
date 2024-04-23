# include<iostream>
# include<memory>

using namespace std;


/*
   Smart pointer basically free up memory automatically

   A Smart Pointer is a wrapper class over a pointer with an operator like * and -> overloaded. 
   The objects of the smart pointer class look like normal pointers. But, unlike Normal Pointers, 
   it can deallocate and free destroyed object memory

   Smart pointers are wrappers around raw pointers that act much like the raw pointers they wrap, but that avoid many of their pitfalls

    Smart pointers can do virtually everything raw pointers can, but with far fewer opportunities for error.

    There are four smart pointers in C++11: 
    std::auto_ptr, 
    std::unique_ptr, 
    std::shared_ptr, and 
    std::weak_ptr. 
    All are designed to help manage the lifetimes of dynamically allocated objects, 
    i.e., to avoid resource leaks by ensuring that such objects are destroyed in the appropriate manner at the appropriate time (including in the event of exceptions).



   std::auto_ptr is depricated and should not be used. std::auto_ptr is a deprecated leftover from C++98.

   We should use std::unique_ptr or std::shared_ptr

   std::unique_ptr is used when we want to have a single owner of the object.


*/

// First basic example od smart pointer
class SmartPointer1 {
    int *ptr; //actual pointer

    public:
      explicit SmartPointer1(int *p = NULL) {
        ptr = p;
        std::cout<<"constructor called"<<std::endl;
        }
      //destructor to delete the pointer automatically when it goes out of scope
      ~SmartPointer1() { 
        delete(ptr);
        std::cout<<"Destructor called"<<std::endl;
        }

      //overloading dereferencing operatore 
      int& operator*() { return *ptr;}

      //delete copy constructor 
      SmartPointer1(const SmartPointer1& p) = delete;
      //delete assignment operator
      SmartPointer1& operator=(const SmartPointer1& p) = delete;
};
// using template create create above example
template<class T>
class SmartPointer {
    T *ptr; // actual pointer or built-in pointer
    public:
      explicit SmartPointer(T *p = NULL) {ptr = p;}
      ~SmartPointer(){delete ptr;}

      T& operator*() {return *ptr;}

      // Overloading arrow operator so that members of T can be accessed like a pointer (useful if T represents a class or struct or union type)
      T* operator->() {return ptr;}

      //delete copy constructor
      SmartPointer(const SmartPointer& P) = delete;
      //delete assignment operator
      SmartPointer& operator=(const SmartPointer& P) = delete;

};





int main() {
    SmartPointer1 sp1(new int());
    *sp1 = 100;
    std::cout<<*sp1<<std::endl;

    SmartPointer<float> sp2(new float());
    float ff = 3.147f;
    *sp2 = ff;
    cout<<*sp2<<endl;

    double dd = 34.67890;
    double *dp = &dd;

    return 0;
}

