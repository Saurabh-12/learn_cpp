#include <iostream>

int foo(int x)
{
    return x;
}

bool ascending(int x, int y)
{
    return x > y;
}

bool descending(int x, int y)
{
    return y > x;
}

bool evensFirst(int x, int y)
{
    // if x is even and y is odd, x goes first (no swap needed)
    if ((x % 2 == 0) && !(y % 2 == 0))
        return false;

    // if x is odd and y is even, y goes first (swap needed)
    if (!(x % 2 == 0) && (y % 2 == 0))
        return true;

    // otherwise sort in ascending order
    return ascending(x, y);
}

void printAray(int *array, int len)
{
    for (int i = 0; i < len; i++)
        std::cout << array[i] << " ";
    std::cout << "\n";
}

void selectionSort(int *array, int size, bool (*compFun)(int, int))
{
    for (int startIndex = 0; startIndex < size; ++startIndex)
    {
        // bestIndex is the index of the smallest/largest element we've encountered so far.
        int bestIndex = startIndex;

        // Look for smallest/largest element remaining in the array (starting at startIndex+1)
        for (int currentIndex = startIndex + 1; currentIndex < size; ++currentIndex)
        {
            // If the current element is smaller/larger than our previously found smallest
            if (compFun(array[bestIndex], array[currentIndex])) // COMPARISON DONE HERE
                // This is the new smallest/largest number for this iteration
                bestIndex = currentIndex;
        }

        // Swap our start element with our smallest/largest element
        std::swap(array[startIndex], array[bestIndex]);
    }
}

int main()
{

    //Calling a function using a function pointer
    int (*fcnPtr)(int) = foo; // assign fcnPtr to function foo
    int a = (*fcnPtr)(9);     // call function foo(5) through fcnPtr.
    std::cout << " a " << a << "\n";

    //The second way is via implicit dereference
    int b = fcnPtr(5); // call function foo(5) through fcnPtr.
    std::cout << " b " << b << "\n";

    //Passing functions as arguments to other functions
    //One of the most useful things to do with function pointers is pass a function as an argument
    //to another function. Functions used as arguments to another function are sometimes
    //called callback functions.
    int array[9] = {3, 7, 9, 5, 6, 1, 8, 2, 4};

    // Sort the array in descending order using the descending() function
    selectionSort(array, 9, descending);
    printAray(array, 9);

    // Sort the array in ascending order using the ascending() function
    selectionSort(array, 9, ascending);
    printAray(array, 9);

    selectionSort(array, 9, evensFirst);
    printAray(array, 9);

    return 0;
}

//Providing default functions
//void selectionSort(int *array, int size, bool (*comparisonFcn)(int, int) = ascending);