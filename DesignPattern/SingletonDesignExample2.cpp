// Implementation of Singleton Class 
# include <iostream>
# include <thread>
# include <chrono>



using namespace std;

class SingletonExample2
{
private:
	// member variables
	string name;
	int ranks;

	// Private constructor to prevent instantiation
	SingletonExample2() {}

	// Private destructor to prevent deletion
	~SingletonExample2() {}

public:
	// deleting copy constructor
	SingletonExample2(const SingletonExample2 &obj) = delete;
	// Singletons should not be assignable.
	void operator=(const SingletonExample2 &old) = delete;

	// Static member function to access the singleton instance
    static SingletonExample2& getInstance() {
        // Guaranteed to be initialized only once
        // Static local variable ensures thread safety in C++11 and later
        static SingletonExample2 instance;
        return instance;
    }

	// sets values of member variables.
	void setValues(string name, int rnk)
	{
		this->name = name;
		this->ranks = rnk;
	}

	// prints values of member variables
	void print()
	{
		cout << name << " Loves " << ranks << "." << endl;
	}
};

// Driver code
int main()
{
	SingletonExample2 &sks = SingletonExample2 ::getInstance();

	// setting values of member variables.
	sks.setValues("Saurabh", 101);

	// printing values of member variables.
	sks.print();

	cout << "Address of GeeksForGeeks: " << &sks << endl;

	cout << endl;

	SingletonExample2 &gfg = SingletonExample2 ::getInstance();

	// setting values of member variables.
	gfg.setValues("Vartika", 210);

	// Printing values of member variables.
	gfg.print();

	cout << "Address of gfg: " << &gfg << endl;
	return 0;
}