# include <iostream>
# include <unordered_map>


using namespace std;

/*
  Difference between Map and unordered_map;

 1.  Map is implemented using a binary search tree(Red-Black Tree), while unordered_map is implemented using hash tables.
 2. Map is slow and unordered_map is fast.
 3. unordered_maps is more efficient for operations such as inserting or deleting elements compare to Map.
 4. Map store elements in sorted order, while unordered_map does not.
 5. This means that operations such as finding an element by key or iterating over the elements in a map are typically faster 
    than in an unordered_map,
  
 6. Find by key: Map -> O(log n)  unordered_map -> O(1)
 7. Iterate over elements:  O(n) for both maps
 8. insert element:  Map -> O(log n) unordered_map -> O(1)
 9. delete element:  Map -> O(log n) unordered_map -> O(1)
 10. Thread safety:  Yes for both Map

*/



int main() {

    unordered_map<int,int> myMaps {
        {1,5},
        {2,6},
        {3,7},
        {4,8}
    };

    //print all the maps value
    for(auto it = myMaps.begin(); it != myMaps.end(); it++) {
        cout<< it->first <<" "<<it->second<<endl;
    }
    cout<<endl;

    myMaps.insert({9,13});
    myMaps[10] = 14;
    myMaps.erase(1);
    bool countResult = myMaps.count(10);
    printf("\n count result is %d\n",countResult);

    if (myMaps.find(9) != myMaps.end()){
        cout << "found key 9 and value is : "<<myMaps[9]<<endl;
    } else {
        cout << "key 2 not found "<<endl;
    }

        //print all the maps value
    for(auto it = myMaps.begin(); it != myMaps.end(); it++) {
        cout<< it->first <<" "<<it->second<<endl;
    }
    cout<<endl;

}