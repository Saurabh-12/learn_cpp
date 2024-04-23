#include <iostream>
#include <vector>

using std::vector;
using std::cout;
using std::endl;
using std::cin;


// passing vector in function as const reference to avoid an expensive copy will be made if pass by value is used.
void passByReference(const vector<int>& v) {
    cout << "passByReference() called" << endl;
    for (int a : v) {
        cout << a << " ";
    }
    printf("\n");
}

template <typename T>
void passByRef(const std::vector<T>& arr)
{
    std::cout << arr[0] << '\n';
}

/* void passByRefAuto(const auto& arr) // abbreviated function template
{
    std::cout << arr[0] << '\n';
} */

template <typename T>
void printElement(vector<T>& arr, int index) {
    if (index < 0 || index >= arr.size()) {
        std::cout << "Index out of bounds" << '\n';
        return;
    } else 
       std::cout <<"The element has value "<< arr[index] << '\n';
}


int main () {
    vector<int> v;

    v.push_back(10);
    v.push_back(20);
    v.push_back(30);
    v.push_back(40);
    v.push_back(50);

    for (int i = 0; i < v.size(); i++) {
        cout << v[i] << " ";
    }
    printf("\n");

    cout << "v.size() = " << v.size() << endl;
    cout << "v.capacity() = " << v.capacity() << endl;
    cout << "v.empty() = " << v.empty() << endl;
    cout << "v.front() = " << v.front() << endl;
    cout << "v.back() = " << v.back() << endl;

    cout << "v[0] = " << v[0] << endl;
    cout << "v[1] = " << v[1] << endl;
    cout << "v[2] = " << v[2] << endl;
    cout << "v[3] = " << v[3] << endl;
    cout << "v[4] = " << v[4] << endl;
    cout << "v[5] = " << v[5] << endl;
    cout << "v[6] = " << v[6] << endl;
    cout << "v[7] = " << v[7] << endl;
    cout << "v[8] = " << v[8] << endl;
    cout << "v[9] = " << v[9] << endl;
    cout << "v[10] = " << v[10] << endl;
    cout << "v[11] = " << v[11] << endl;
    cout << "v.size() = " << v.size() << endl;
    cout << "v.capacity() = " << v.capacity() << endl;


    vector<int> primeNumber = {2,3,5,7,11,13,17,19,23,29,31,37,41,43,47,53,59,61,67,71,73,79,83,89,97};

    vector<int> firstTenPrimeNumber {2,3,5,7,11,13,17,19,23,29};

    // vector insert example
    primeNumber.insert(primeNumber.begin() + 2, 101);
    primeNumber.insert(primeNumber.cbegin(), 106);
    primeNumber.insert(primeNumber.begin() + 5, 102);
    primeNumber.insert(primeNumber.cend(), 103);

    for (auto a : primeNumber) {
        cout << a << " ";
    }
    printf("\n");

    passByReference(firstTenPrimeNumber);

    vector<double> dbl{ 1.1, 2.2, 3.3 };
    //passByReference(dbl); // compile error: std::vector<double> is not convertible to std::vector<int>
    passByRef(dbl);
    passByRef(firstTenPrimeNumber);

    //passByRefAuto(dbl);
    //passByRefAuto(firstTenPrimeNumber);

    printf("\n");
    std::vector<int> intVect { 0, 1, 2, 3, 4 };
    printElement(intVect, 2);
    printElement(intVect, 5);

    printf("\n");
    std::vector<double> doubleVect { 1.1, 2.2, 3.3 };
    printElement(doubleVect, 0);
    printElement(doubleVect, -1);
    printf("\n");

    cout << "primeNumber.size() = " << primeNumber.size() << endl;
    cout << "primeNumber.capacity() = " << primeNumber.capacity() << endl;
    cout << "primeNumber.empty() = " << primeNumber.empty() << endl;
    cout << "primeNumber.front() = " << primeNumber.front() << endl;
    cout << "primeNumber.back() = " << primeNumber.back() << endl;
    cout << "primeNumber[0] = " << primeNumber[0] << endl;

    cout << "Sum of First five prime numbers = " << primeNumber[0]+primeNumber[1]+primeNumber[2]+primeNumber[3]+primeNumber[4]<< endl;


    vector<char> vowels = {'a','e','i','o','u'};
    cout << "vowels.size() = " << vowels.size() << endl;
    cout << "vowels.capacity() = " << vowels.capacity() << endl;
    for(char c : vowels) {
        cout << c << " ";
    }
    printf("\n");
    printf("\nSaurabh Sharma\n");

    //creating fix length vector
    vector<int> vectorOf10Elements(10);
    for(int a : vectorOf10Elements) {
        cout << a << " ";
    }
    printf("\n");

    //creating vector of 10 elements with initial value 10
    vector<int> vectorOf10ElementsWithInitialValue(10, 10);
    vectorOf10ElementsWithInitialValue[3] = 30;
    vectorOf10ElementsWithInitialValue[5] = 50;
    for(int a : vectorOf10ElementsWithInitialValue) {
        cout << a << " ";
    }
    printf("\n");

    vector <int> v2 = {10, 2};
    cout << "v2.size() = " << v2.size() << endl;
    cout << "v2.capacity() = " << v2.capacity() << endl;
    for (int a : v2) {
        cout << a << " ";
    }
    printf("\n");

    //const vector example
   // const vector<int> constVector = {10, 20, 30};
    const vector<int> constVector{10, 20, 30, 40};
    cout << "constVector.size() = " << constVector.size() << endl;
    cout << "constVector.capacity() = " << constVector.capacity() << endl;
    const int kk = 40;
    //constVector.push_back(kk);
    for (int a : constVector) {
        cout << a << " ";
    }
    printf("\n");

    struct vect {
       // vector<int> v(10);// compile error: direct initialization not allowed for member default initializers
        std::vector<int> v{ std::vector<int>(8) }; // ok
        vector<int> v2 = {1,2,3,4,5}; // ok
        vector<int> v3{1,2,3,4,5,6,7,8,9,10}; // ok
        //vector<int> v4(10, 10); // Not ok

        //vect() {};
    };
    vect vect1;
    vect1.v2.push_back(10);
    vect1.v3.push_back(15);
    vect1.v.push_back(10);

 
    for (int a : vect1.v) {
        cout << a << " ";
    }
    printf("\n");
    for (int a : vect1.v2) {
        cout << a << " ";
    }
    printf("\n");

    for (int a : vect1.v3) {
        cout << a << " ";
    }    
    printf("\n");

struct Person {
  std::string name;
  int age;
  std::string address;

  Person(std::string name, int age, std::string address) : 
    name(name), age(age), address(address) {}

};

vector<Person> people;
people.push_back(Person("John Doe Sr", 30, "123 Main Street"));
people.push_back(Person("Jane Doe Jr", 25, "456 Elm Street"));

for (Person person : people)
    cout << person.name << " " << person.age << " " << person.address << endl;

/* cout << "Enter 3 integers:"<<endl;
vector<int> intInput(3);
cin >> intInput[0] >> intInput[1] >> intInput[2];
cout<< "Sum of the integers entered is: "<< intInput[0] + intInput[1] + intInput[2]<<endl;
cout <<"product of the integers entered is: "<< intInput[0] * intInput[1] * intInput[2]<<endl; */

// vector at() example
vector<bool> boolVector(5);
boolVector.at(0) = true;
boolVector.at(1) = false;
boolVector.at(2) = true;
boolVector.at(3) = false;
boolVector.at(4) = true;
boolVector.front() =  false;

for (int i = 0; i < boolVector.size(); i++)
    cout << boolVector.at(i) << " ";

//boolVector.at(6); terminate called after throwing an instance of 'std::out_of_range'
printf("\n");


    return 0;
}
