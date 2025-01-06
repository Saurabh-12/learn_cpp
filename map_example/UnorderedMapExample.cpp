# include <iostream>
# include <unordered_map>
# include <string>


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

    unordered_map<string, int> ages;
  
    //INSERTION
    ages["Rishabh"] = 26;
    ages["Anjali"] = 23;
    ages["Raushan"] = 26;
    pair<string, int> p = make_pair("Reetesh", 25);
    ages.insert(p);
    ages.insert({"Jincheng", 38});
  
    //LOOKUP
    cout << "Reetesh's age is: " << ages["Reetesh"] << endl;

    //CHECKING EXISTENCE USING find()
    string key = "Raushan";
    if (ages.find(key) != ages.end()) {
        cout << key << " exists in the map and is " << ages[key] << " years old." << endl;
    } else {
        cout << key << " does not exist in the map." << endl;
    }

    //CHECKING EXISTENCE USING count()
    key = "Anjali";
    if (ages.count(key) > 0) {
        cout << key << " exists in the map and is " << ages[key] << " years old." << endl;
    } else {
        cout << key << " does not exist in the map." << endl;
    }

    //ACCESSING and CHANGING values using []
    cout << "Rishabh's age is: " << ages["Rishabh"] << endl;
    ages["Rishabh"] = 27;  // Changing value
    cout << "Rishabh's updated age is: " << ages["Rishabh"] << endl;

    //ACCESSING and CHANGING values using at()
    cout << "Anjali's age is: " << ages.at("Anjali") << endl;
    ages.at("Anjali") = 24;  // Changing value
    cout << "Anjali's updated age is: " << ages.at("Anjali") << endl;

    //SEARCHING using [] (adds a new element if not found)
    cout << "Trying to access non-existent key 'John': " << ages["John"] << endl;
    cout << "Size of map after accessing 'John': " << ages.size() << endl;

    //ITERATION using iterator
    cout << "Using iterator:" << endl;
    unordered_map<string, int>::iterator it = ages.begin();
    while (it != ages.end()) {
        cout << it->first << " is " << it->second << " years old" << endl;
        ++it;
    }
  
    //ITERATION using auto
    cout << "Using auto:" << endl;
    for (const auto& pair : ages) {
        cout << pair.first << " is " << pair.second << " years old" << endl;
    }
  
    //DELETION
    ages.erase("Reetesh");

}