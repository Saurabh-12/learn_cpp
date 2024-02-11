#include<iostream>

template<class T>
class SmartPointer3
{
    T *m_ptr;

    public:
    SmartPointer3(T *ptr = nullptr) : m_ptr(ptr)
    {

    }
    ~SmartPointer3()
    {
        delete m_ptr;
    }

    // Copy constructor
	// Do deep copy of a.m_ptr to m_ptr
    SmartPointer3(const SmartPointer3& aRef)
    {
        m_ptr = new T;
		*m_ptr = *aRef.m_ptr;
    }

    // Copy assignment
	// Do deep copy of a.m_ptr to m_ptr
    SmartPointer3& operator=(const SmartPointer3& aRef)
    {
        // Self-assignment detection
		if (&aRef == this)
			return *this;
 
		// Release any resource we're holding
		delete m_ptr;
 
		// Copy the resource
		m_ptr = new T;
		*m_ptr = *aRef.m_ptr;
 
		return *this;
    }

	T& operator*() const { return *m_ptr; }
	T* operator->() const { return m_ptr; }
	bool isNull() const { return m_ptr == nullptr; }

};

class Resource
{
    public:
	Resource() { std::cout << "Resource acquired\n"; }
	~Resource() { std::cout << "Resource destroyed\n"; }

};

SmartPointer3<Resource> generateResource()
{
	SmartPointer3<Resource> res(new Resource);
	return res; // this return value will invoke the copy constructor
}

int main()
{

    SmartPointer3<Resource> mainres;
	mainres = generateResource(); // this assignment will invoke the copy assignment

    return 0;
}
/****
 * When this program is run, it prints:

Resource acquired
Resource acquired
Resource destroyed
Resource acquired
Resource destroyed
Resource destroyed
(Note: You may only get 4 outputs if your compiler elides the return value from function generateResource())

That’s a lot of resource creation and destruction going on for such a simple program! What’s going on here?

Let’s take a closer look. There are 6 key steps that happen in this program (one for each printed message):

1) Inside generateResource(), local variable res is created and initialized with a dynamically allocated Resource, which causes the first “Resource acquired”.
2) Res is returned back to main() by value. We return by value here because res is a local variable -- it can’t be returned by address or reference because res will be destroyed when generateResource() ends. So res is copy constructed into a temporary object. Since our copy constructor does a deep copy, a new Resource is allocated here, which causes the second “Resource acquired”.
3) Res goes out of scope, destroying the originally created Resource, which causes the first “Resource destroyed”.
4) The temporary object is assigned to mainres by copy assignment. Since our copy assignment also does a deep copy, a new Resource is allocated, causing yet another “Resource acquired”.
5) The assignment expression ends, and the temporary object goes out of expression scope and is destroyed, causing a “Resource destroyed”.
6) At the end of main(), mainres goes out of scope, and our final “Resource destroyed” is displayed.
**/