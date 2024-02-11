#include <iostream>

int main()
{
    int fibonacci[] = {0, 1, 1, 2, 3, 5, 8, 13, 21, 34, 55, 89};
    for (int number : fibonacci)    // iterate over array fibonacci
        std::cout << number << ' '; // we access the array element for this iteration 
                                    //through variable number

std::cout<<"\n...............................................................\n";
//For each loops and the auto keyword
for (auto number : fibonacci) // type is auto, so number has its type deduced from the fibonacci array
       std::cout << number << ' ';

std::cout<<"\n...............................................................\n";
//For-each loops and references
    int array[5] = { 9, 7, 5, 3, 1 };
    for (auto element: array) // element will be a copy of the current array element
        std::cout << element << ' ';
std::cout<<"\n";
 // Copying array elements can be expensive, and most of the time we really just want to refer
 // to the original element. Fortunately, we can use references for this 
 // The ampersand makes element a reference to the actual array element,
 // preventing a copy from being made   
     for (auto &element: array) 
        std::cout << element << ' ';
std::cout<<"\n...............................................................\n";
//Rule: Use references or const references for your element declaration in for-each loops for performance reasons.
std::cout << "\n";
for(const auto &ele : fibonacci)
{
    std::cout << ele <<" ";
}

std::cout << "\n";
// Max score example
int len = 5;
int scores[] = { 84, 92, 76, 81, 56 };
int maxScore = 0;
for(const auto &scoe : scores)
{
    if(scoe>maxScore)
    {
        maxScore = scoe;
    }
}
std::cout << "MaxScore " << maxScore;


    return 0;
}