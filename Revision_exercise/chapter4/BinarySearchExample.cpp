#include<iostream>
#include<cassert>

int binarySearch(int *array, int target, int min, int max)
{
        assert(array); // make sure array exists
 
	while (min <= max)
	{
		// implement this iteratively
		int midpoint = min + ((max-min) / 2); // this way of calculating midpoint avoids overflow
 
		if (array[midpoint] > target)
		{
			// if array[midpoint] > target, then we know the number must be in the lower half of the array
			// we can use midpoint - 1 as the upper index, since we don't need to retest the midpoint next iteration
			max = midpoint - 1;
		}
		else if (array[midpoint] < target)
		{
			// if array[midpoint] < target, then we know the number must be in the upper half of the array
			// we can use midpoint + 1 as the lower index, since we don't need to retest the midpoint next iteration
			min = midpoint + 1;
		}
		else
			return midpoint;
	}
	
	return -1;
}

int main()
{

    int array[] = { 3, 6, 8, 12, 14, 17, 20, 21, 26, 32, 36, 37, 42, 44, 48 };
 
    // We're going to test a bunch of values to see if they produce the expected results
    const int numTestValues = 9;
    // Here are the test values
    int testValues[numTestValues] = { 0, 3, 12, 13, 22, 26, 43, 44, 49 };
    // And here are the expected results for each value
    int expectedValues[numTestValues] = { -1, 0, 3, -1, -1, 8, -1, 13, -1 };
 
    // Loop through all of the test values
    for (int count=0; count < numTestValues; ++count)
    {
        // See if our test value is in the array
        int index = binarySearch(array, testValues[count], 0, 14);
        // If it matches our expected value, then great!
        if (index == expectedValues[count])
             std::cout << "test value " << testValues[count] << " passed!\n";
        else // otherwise, our binarySearch() function must be broken
             std::cout << "test value " << testValues[count] << " failed.  There's something wrong with your code!\n";
    }

    return 0;
}