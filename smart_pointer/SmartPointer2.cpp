#include<iostream>

template<class T>
class SmartPointer2
{
private:
    T *m_ptr;
public:
    SmartPointer2(T *ptr = nullptr) : m_ptr(ptr)
    {

    }

    // A copy constructor that implements move semantics
    SmartPointer2(SmartPointer2 &sptr2)
    {
        m_ptr = sptr2.m_ptr;   // transfer our dumb pointer from the source to our local object
        sptr2.m_ptr = nullptr; // make sure the source no longer owns the pointer
    }

    SmartPointer2 &operator=(SmartPointer2 &aaa)
    {
        if (&aaa == this)
            return *this;

        delete m_ptr;      // make sure we deallocate any pointer the destination is already holding first
        m_ptr = aaa.m_ptr;   // then transfer our dumb pointer from the source to the local object
        aaa.m_ptr = nullptr; // make sure the source no longer owns the pointer
        return *this;
    }

    ~SmartPointer2()
    {
        delete m_ptr;
    }

    T& operator*() const { return *m_ptr; }
	T* operator->() const { return m_ptr; }
	bool isNull() const { return m_ptr == nullptr;  }
};

class Resource
{
public:
	Resource() { std::cout << "Resource acquired\n"; }
	~Resource() { std::cout << "Resource destroyed\n"; }
};

int main()
{
	SmartPointer2<Resource> res1(new Resource);
	SmartPointer2<Resource> res2; // Start as nullptr
 
	std::cout << "res1 is " << (res1.isNull() ? "null\n" : "not null\n");
	std::cout << "res2 is " << (res2.isNull() ? "null\n" : "not null\n");
 
	res2 = res1; // res2 assumes ownership, res1 is set to null
 
	std::cout << "Ownership transferred\n";
 
	std::cout << "res1 is " << (res1.isNull() ? "null\n" : "not null\n");
	std::cout << "res2 is " << (res2.isNull() ? "null\n" : "not null\n");
 
	return 0;
}
