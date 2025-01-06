#include<iostream>
#include<algorithm>

void selectionSortAsendind(int *arr, int length)
{
    for (int startIndex = 0; startIndex < length; ++startIndex)
    {
        int smallestIndex = startIndex;

        for (int currentIndex = startIndex + 1; currentIndex < length; ++currentIndex)
        {
            // If we've found an element that is smaller than our previously found smallest
            if (arr[currentIndex] < arr[smallestIndex])
                // then keep track of it
                smallestIndex = currentIndex;
        }
        // smallestIndex is now the smallest element in the remaining array
        // swap our start element with our smallest element (this sorts it into the correct place)
        std::swap(arr[startIndex], arr[smallestIndex]);
    }
}

void selectionSortDesending(int *arr, int length)
{
    for (int i = 0; i < length; i++)
    {
        int largestIndext = i;

        for (int j = i + 1; j < length; j++)
        {
            if (arr[j] > arr[largestIndext])
            {
                largestIndext = j;
            }
        }
        std::swap(arr[i], arr[largestIndext]);
    }
}

int main()
{
    const int length = 5;
    int arr[length] = {50, 30, 20, 10, 40};
    selectionSortAsendind(arr, length);

    // Now that the whole array is sorted, print our sorted array as proof it works
    for (int index = 0; index < length; ++index)
        std::cout << arr[index] << ' ';

    std::cout << "\n.........................................\n";

    const int len = 5;
    int array[len] = {30, 50, 20, 10, 40};

    std::sort(array, array + len);

    for (int i = 0; i < len; ++i)
        std::cout << array[i] << ' ';

    int len1 = 6;
    int arr1[] = {30, 60, 20, 50, 40, 10};
    selectionSortDesending(arr1, len1);

    std::cout << "\n.........................................\n";

    for (int index = 0; index < len1; ++index)
        std::cout << arr1[index] << ' ';
    std::cout<<std::endl;
    
    return 0;
}