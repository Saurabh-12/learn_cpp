#include<iostream>
#include<cassert>

class InitList
{
    private:
    // give this class some initial state for this example
    int m_list[10] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };

    public:
    int& operator[](const int index);
    const int& operator[](const int index) const;

};

// for non-const objects: can be used for assignment
int& InitList::operator[](const int index)
{
    assert(index >= 0 && index < 10);
    return m_list[index];
}

// for const objects: can only be used for access
const int& InitList::operator[](const int index) const
{
    assert(index >= 0 && index < 10);
    return m_list[index];
}

int main()
{
    InitList list;
    list[2] = 3; // okay: calls non-const version of operator[]
    std::cout << list[2];
 
    const InitList clist;
    clist[2] = 3; // compile error: calls const version of operator[], which returns a const reference.  Cannot assign to this.
    std::cout << clist[2];

    InitList *plist = new InitList;
    plist [2] = 3; // error: this will assume we're accessing index 2 of an array of IntLists
    delete plist;

//Rule: Make sure you’re not trying to call an overloaded operator[] on a pointer to an object.
    InitList *p1list = new InitList;
    (*p1list)[2] = 3; // get our IntList object, then call overloaded operator[]
    delete p1list;
    //Above one is ugly and error prone. Better yet, don’t set pointers to your objects if you don’t have to.
 
    return 0;
}
