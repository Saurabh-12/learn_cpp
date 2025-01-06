#include<iostream>
#include<vector>

using namespace std;

int main() {

     // Create a 2D vector (array) using initializer lists for each row

     vector<vector<int>> myvector = {
        {18,2,3,4}, // Row 1
        {5,6,7,8}, // Row 2
        {9, 10, 11, 12}, // Row 3
        {13, 14, 15, 16}
     };

    // Print the 2D array (myVector) with its values
    cout << "2D Array (myVector) using initializer lists:" << endl;

    for (int i = 0; i < myvector.size(); i++)
    {
        for (int j = 0; j < myvector.size(); j++)
        {
            cout<<myvector[i][j]<<" ";
        }
        
        cout<<endl;
    }

     // Create an empty 2D vector
    vector<vector<int>> myVector2;
    myVector2.push_back({1,2,3,4}); //adding 1st row
    myVector2.push_back({5,6,7,8}); //adding 2nd row
    myVector2.push_back({9,10,11,12}); //adding 3rd row
    myVector2.push_back({13,14,15,16}); //adding 4th row

        // Print the dynamically added 2D array (matrix)
    cout << "Dynamically added 2D Array:" << endl;

    for (int i = 0; i < myVector2.size(); i++)
    {
        for (int j = 0; j < myVector2.size(); j++)
        {
            cout << myVector2[i][j] << " ";
        }

        cout << endl;
    }

    // Create a jagged 2D array (vector of vectors) where rows have different sizes
    vector<vector<int>> jaggedArray = {
        {18, 2},         // Row 1 (2 elements)
        {5, 6, 7},       // Row 2 (3 elements)
        {9, 10, 11, 12}, // Row 3 (4 elements)
        {13}             // Row 4 (1 element)
    };

    // Print the jagged 2D array
    cout << "Jagged 2D Array:" << endl;
    for (int i = 0; i < jaggedArray.size(); i++)
    {
        for (int j = 0; j < jaggedArray[i].size(); j++)
        {
            cout << jaggedArray[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}