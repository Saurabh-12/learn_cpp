#include <iostream>
#include<exception>



using namespace std;

void insertElement(int arr[], int size, int index, int value) {
    if (index <0 || index >= size)
        throw out_of_range("Index out of range");
    arr[index] = value;
}


int main() {

    int arr[10];

/*     arr[0] = 23;
    arr[1] = 24;
    arr[2] = 25;
    arr[19] = 31;
    arr[20] = 32;
    arr[21] = 33;
    arr[22] = 34;
    arr[23] = 35;
    arr[24] = 36; */
    
    unsigned size = sizeof(arr)/sizeof(arr[0]);
    cout<<" array size : "<<size<<endl;

//Adding elements in array;
    try
    {
        for (int i = 0; i < size-1; i++)
            arr[i] = i * 2;
            //insertElement(arr,size,i,i*2);

        /*
        In C++, you cannot directly catch out-of-bounds exceptions with a try-catch block 
        because accessing an array out of bounds leads to undefined behavior, and 
        it typically doesn't raise an exception that you can catch using try-catch.
        */
    }
    catch (out_of_range& e)
    {
        cout << e.what() << endl;
    } catch (exception& e) {
        cout<<e.what()<<endl;
    }

    // adding element in last
    arr[9] = 23;
    //adding element in first
    arr[0] = 12;

    // Inserting element at any index 
    


    printf("Printing array elements...\n");
    //print elements arraY
    for(int j = 0; j<size; j++)
       cout<<arr[j]<<" ";
    printf("\n");




    return 0;
}