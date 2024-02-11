#include<iostream>
#include<algorithm>

void SelectionSort(int arr[], int length)
{
    
    for(int startIndex = 0; startIndex < length-1; startIndex++)
    {
        int smallestIndex = startIndex;

        for(int currentIndex = startIndex+1; currentIndex < length; currentIndex++)
        {
           	// If we've found an element that is smaller than our previously found smallest
			if (arr[currentIndex] < arr[smallestIndex])
				// then keep track of it
				smallestIndex = currentIndex;
        }
      std::swap(arr[startIndex], arr[smallestIndex]);  
    } 

}

void printArray(int Arr[], int length)
{
    std::cout<<"[ ";
    for(int i = 0; i < length; i++)
    {
        std::cout<<Arr[i]<<" ";
    }
    std::cout<<"]"<<"\n\n";  
}

void bubbleSort(int arr[] , int len)
{
    
    for(int startIndex = 0; startIndex < len; startIndex++)
    {
        
        for(int currentIndex = startIndex+1; currentIndex < len; currentIndex++)
        {
            if(arr[startIndex]>arr[currentIndex])
            {
                std::swap(arr[startIndex], arr[currentIndex]);
            }
        }
    }

}


int main()
{
    int arrayLength = 5;
     
     int arr[5] = { 30, 50, 20, 10, 40 };
     std::cout<<"Array before sorting"<<"\n";
     printArray(arr, arrayLength);
     SelectionSort(arr, arrayLength);
     std::cout<<"SelectionSort: Array after sorting"<<"\n";
     printArray(arr,arrayLength);

     const int length(9);
     int array[length] = { 6, 3, 2, 9, 7, 1, 5, 4, 8 };
     std::cout<<"Array before sorting"<<"\n";
     printArray(array,length);
     bubbleSort(array, length);
     std::cout<<"BubbleSort: Array after sorting"<<"\n";
     printArray(array,length);






}