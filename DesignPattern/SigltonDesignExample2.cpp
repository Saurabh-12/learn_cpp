// Implementation of Singleton Class 
# include <iostream>
# include <thread>
# include <chrono>



using namespace std;

class SingletonExample2{
    private:
    // member variables
     string name, loves;
     static SingletonExample2*
	// static pointer which will points 
    //to the instance of this class
    instancePtr; 
    // Default constructor
    SingletonExample2(){}
    
    public:
      // deleting copy constructor
      SingletonExample2(const SingletonExample2& obj) = delete;
        //Singletons should not be assignable.
      void operator = (const SingletonExample2& old) = delete;
/*
	getInstance() is a static method that returns an
	instance when it is invoked. It returns the same
	instance if it is invoked more than once as an instance
	of Singleton class is already created. It is static
	because we have to invoke this method without any object
	of Singleton class and static method can be invoked
	without object of class

	As constructor is private so we cannot create object of
	Singleton class without a static method as they can be
	called without objects. We have to create an instance of
	this Singleton class by using getInstance() method.
*/
    static SingletonExample2* getInstance() {
	// If there is no instance of class
	// then we can create an instance.
	   if (instancePtr == NULL){
	// We can access private members 
	// within the class.
	    instancePtr = new SingletonExample2(); 
	
	// returning the instance pointer
	    return instancePtr; 
	   }
	    else
	       {
	// if instancePtr != NULL that means 
	// the class already have an instance. 
	// So, we are returning that instance 
	// and not creating new one.
	      return instancePtr;
	    }
    }   

// sets values of member variables.
void setValues(string name, string loves) 
{
	this->name = name;
	this->loves = loves;
}

// prints values of member variables
void print() 
{
	cout << name << " Loves " << 
			loves << "." << endl;
}
};

// initializing instancePtr with NULL
SingletonExample2* SingletonExample2 ::instancePtr = NULL; 

// Driver code
int main()
{ 
    SingletonExample2* sks = SingletonExample2 ::getInstance(); 

// setting values of member variables.
   sks->setValues("Saurabh", "GeeksForGeeks"); 

// printing values of member variables.
sks ->print(); 

cout << "Address of GeeksForGeeks: " << sks << endl;

cout << endl; 

SingletonExample2* gfg = SingletonExample2 ::getInstance(); 

// setting values of member variables.
gfg->setValues("Vartika",
				"GeeksForGeeks"); 

// Printing values of member variables.
gfg->print(); 

cout << "Address of gfg: " << gfg << endl;
return 0;
}