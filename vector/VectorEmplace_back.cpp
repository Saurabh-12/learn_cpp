# include <iostream>
# include <vector>
# include <chrono>

using namespace std;


/*
We should use push_back when:
we already have a copy of the element that you want to insert into the vector.
we object you want to insert is cheap to copy.
The object has a non-explicit copy constructor
*/

/*
You should use emplace_back when:

You have the arguments to construct the object, but not the object itself.
The object is expensive to copy.
The object has a non-explicit constructor that takes the same arguments as you want to pass to emplace_back
*/

/*
In short, you can’t use emplace_back every where instead of push_back 
because it's not always the most efficient or convenient option

*/

struct Test {
    int a, b;

    Test(int x, int y) : a(x), b(y) {};
};

int main () {

    vector<Test> v1;
    vector<Test> v2;
    
    auto start = std::chrono::high_resolution_clock::now();

    for (int i = 0; i < 100000; ++i)
    {
        v1.push_back(Test(i, i));
    }

    auto end = std::chrono::high_resolution_clock::now();

    std::cout << "push_back took "
              << std::chrono::duration_cast<std::chrono::microseconds>(end - start).count()
              << " microseconds\n";


    start = std::chrono::high_resolution_clock::now();

    for (int i = 0; i < 100000; ++i)
    {
        v2.emplace_back(i, i);
    }

    end = std::chrono::high_resolution_clock::now();
    
    std::cout << "emplace_back took "
              << std::chrono::duration_cast<std::chrono::microseconds>(end - start).count()
              << " microseconds\n";

    return 0;
}