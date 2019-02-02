#include<iostream>


int main()
{
    int array[1000000]; // allocate 1 million integers (probably 4MB of memory)

        int arr [5] = {1,2,3,4,6};

    
    for(int i = 0; i < 5; i++)
    {
        std::cout<<i<<" "<<arr[i]<<" ";
    }
    std::cout<<"\n";

    int *arr2 = new int [1000000]();
    std::cout<<"arr2 "<<arr2[0]<<"\n";
    


    return 0;
}