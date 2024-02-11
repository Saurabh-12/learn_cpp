#include <iostream>

template <class T>
class SmartPointer1
{
    T *m_ptr;

  public:
    // Pass in a pointer to "own" via the constructor
    SmartPointer1(T *ptr = nullptr) : m_ptr(ptr)
    {
    }
    // The destructor will make sure it gets deallocated
    ~SmartPointer1()
    {
        delete m_ptr;
    }

    // Overload dereference and operator-> so we can use Auto_ptr1 like m_ptr.
	T& operator*() const { return *m_ptr; }
	T* operator->() const { return m_ptr; }
};

class Resource
{
  public:
    Resource() { std::cout << "Resource acquired\n"; }
    ~Resource() { std::cout << "Resource destroyed\n"; }
    void sayHi() { std::cout << "Hi\n"; }
};

void someFunction()
{
    SmartPointer1<Resource> ptr(new Resource); // ptr now owns the Resource
 
    int x;
    std::cout << "Enter an integer: ";
    std::cin >> x;
 
    if (x == 0)
        return; // the function returns early
 
    // do stuff with ptr here
    ptr->sayHi();
}

int main()
{
    //2nd Example
    someFunction();

    //Firtst Example
    SmartPointer1<Resource> res(new Resource); // Note the allocation of memory here
 
        // ... but no explicit delete needed
 
	// Also note that the Resource in angled braces doesn't need a * symbol, since that's supplied by the template
 
	return 0;
} // res goes out of scope here, and destroys the allocated Resource for us