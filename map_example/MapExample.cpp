#include<iostream>
#include<map>
#include <vector>
#include<set>
#include<string>

/*
Maps in C++ are container structures that store elements in key-value pairs. 
This means that for every unique key, there is a data value mapped to it, that can be easily accessed if we know the key.

This is why every key has to be unique, and no two keys can be the same(but the values associated to keys can be the same).



*/

using namespace std;

    bool checkIfExist(vector<int>& arr) {
        
        int size = arr.size();
        bool found = false;
        
        for(int i = 0; i <size; i++) {
            
            for (int j = i; j < size-1; j++){
                if((arr[i] == 2 * arr[j+1]) || (2 * arr[i] == arr[j+1])) {
                   found = true; 
                }
            }
        }
        return found;
    }



int main () {

    map<int,int>myMaps;

    for (int i = 0; i < 11; i++) {
        myMaps[i] = i * i;
    }

    // print all the maps value
    cout<<myMaps[2]<<endl;
    for(int kk = 0; kk <myMaps.size(); kk++) {
        cout<<myMaps[kk]<<" ";
    }
    printf("\n");

    vector<int>testVector {-2,0,10,-19,4,6,-8};
    cout <<" vector having {0, 0} return value :"<<checkIfExist(testVector)<<endl;

    map<int,map<int,int>>mp;
    //insert key value pair
    for (int i = 1; i < 11 ; i++) {
        for (int j = 1; j <11; j++) {
            // i is the key for the first map
            // j is the key for second map
            mp[i][j] = i *j;
        }
    }

    // access the value od the map 
    cout <<" mp [1][10] value : "<<mp[1][10]<<endl;
    printf("\n");
    printf(" map  value at key [2][9] : %d \n", mp[2][9]);
    printf("\n");

map<vector<int>,map<int,int>> mpvector;
map<set<int>,string> mpSet;




    return 0;
}