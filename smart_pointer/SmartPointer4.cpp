#include<iostream>

template<class T>
class SmartPointer4
{
    T * m_ptr;

    public:
    SmartPointer4(T *ptr = nullptr) : m_ptr(ptr)
    {

    }

    ~SmartPointer4()
    {
        delete m_ptr;
    }

    // Move constructor
	// Transfer ownership of a.m_ptr to m_ptr
    SmartPointer4(SmartPointer4&& arref) : m_ptr(arref.m_ptr)
    {
        arref.m_ptr = nullptr;
    }

	// Move assignment
	// Transfer ownership of a.m_ptr to m_ptr
    SmartPointer4& operator=(SmartPointer4&& arref)
    {
        // Self-assignment detection
		if (&arref == this)
			return *this;
 
		// Release any resource we're holding
        
		delete m_ptr;
 
		// Transfer ownership of a.m_ptr to m_ptr
		m_ptr = arref.m_ptr;
		arref.m_ptr = nullptr; // we'll talk more about this line below
 
		return *this;
    } 

    T& operator*() const { return *m_ptr;}
    T* operator->() const {return m_ptr; }
    bool isNull() const { return m_ptr == nullptr; }

};

class Resource
{
    public:
	Resource() { std::cout << "Resource acquired\n"; }
	~Resource() { std::cout << "Resource destroyed\n"; }

};

SmartPointer4<Resource> generateResource()
{
	SmartPointer4<Resource> res(new Resource);
	return res; // this return value will invoke the move constructor
}


int main()
{
    SmartPointer4<Resource> mainres;
	mainres = generateResource(); // this assignment will invoke the move assignment

    return 0;
}