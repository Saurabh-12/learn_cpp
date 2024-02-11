#include<iostream>
#include<map>
#include<string>

int main()
{
    using namespace std;

    std::map<int, string> my_Map;
    my_Map.insert(make_pair(4, "Apple"));
    my_Map.insert(make_pair(2, "Orange"));
    my_Map.insert(make_pair(1, "Banana"));
    my_Map.insert(make_pair(3, "Grapes"));
    my_Map.insert(make_pair(6, "Mango"));
    my_Map.insert(make_pair(5, "Peach"));

    std::map<int, string>::const_iterator itr; // declare an iterator
    itr = my_Map.begin(); // assign it to the start of the vector

    while(itr != my_Map.end()){
        std::cout<<itr -> first<<" "<<itr -> second<<" \n";
        itr++;
    }

    std::cout<<'\n';
    

    return 0;
}