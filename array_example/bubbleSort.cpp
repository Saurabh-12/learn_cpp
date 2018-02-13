#include<iostream>
#include<algorithm>


int main()
{
    std::cout<<"welcome Saurabh\n";
    //const int length(9);
    int array[] = { 6, 3, 2, 9, 7, 1, 5, 4, 8 };
    const int length = sizeof(array) / sizeof(array[0]);

/*     for(int i = 0; i<length-i; i++)
    {
        
        for(int j = 0; j<length-1; j++)
        {
           // If the current element is larger than the element after it, swap them
            if (array[j] > array[j+1])
                std::swap(array[j], array[j+ 1]);
        }
    }
      // Now print our sorted array as proof it works
    for (int index = 0; index < length; ++index)
        std::cout << array[index] << ' '; */

        /**
         *Add two optimizations to the bubble sort algorithm you wrote in the previous quiz question:

       Notice how with each iteration of bubble sort, the biggest number remaining gets bubbled to the 
       end of the array. After the first iteration, the last array element is sorted. A
       fter the second iteration, the second to last array element is sorted too. 
       And so on… With each iteration, we don’t need to recheck elements that we know are already sorted. 
       Change your loop to not re-check elements that are already sorted.

        If we go through an entire iteration without doing a swap, then we know the array must already 
        be sorted. Implement a check to determine whether any swaps were made this iteration, 
        and if not, terminate the loop early. If the loop was terminated early, print on which 
        iteration the sort ended early. **/

// Step through each element of the array except the last
    for (int iteration = 0; iteration < length-1; ++iteration)
    {
        // Account for the fact that the last element is already sorted with each subsequent iteration
        // so our array "ends" one element sooner
        int endOfArrayIndex(length - iteration);
 
        bool swapped(false); // Keep track of whether any elements were swapped this iteration
 
        // Search through all elements up to the end of the array - 1
        // The last element has no pair to compare against
        for (int currentIndex = 0; currentIndex < endOfArrayIndex - 1; ++currentIndex)
        {
            // If the current element is larger than the element after it
            if (array[currentIndex] > array[currentIndex + 1])
            {
                // Swap them
                std::swap(array[currentIndex], array[currentIndex + 1]);
                swapped = true;
            }
        }
 
        // If we haven't swapped any elements this iteration, we're done early
        if (!swapped)
        {
            // iteration is 0 based, but counting iterations is 1-based.  So add 1 here to adjust.
            std::cout << "Early termination on iteration: " << iteration+1 << '\n';
            break;
        }
    }

    // Now print our sorted array as proof it works
    for (int index = 0; index < length; ++index)
        std::cout << array[index] << ' ';


    return 0;
}