#include<iostream>
#include<list>


using namespace std;

bool isEven(int i) {
    return (i%2 == 0 ? true:false);}

int main() {

    list<int> myList;

    //Adding element in list
    for(int i = 0; i <10; i++)
       myList.push_back(i);
    
myList.push_front(10);
myList.push_front(11);
myList.push_front(12);

myList.pop_back(); 
myList.pop_front();
myList.remove_if(isEven);
myList.remove(11);
myList.push_back(8);
myList.push_back(16);
myList.push_back(7);
myList.push_back(19);
myList.push_back(10);
myList.push_back(4);
//printf("  %d ",popBack1);
myList.sort();
myList.remove(7);
int kk = myList.front();
int mm = myList.back();
int size = myList.size();

list<int>::iterator it = myList.begin();

myList.insert(it++, 56);
myList.insert(myList.begin()++,89);
myList.insert(myList.end()--,67);

    for(int ele : myList)
        printf(" %d ",ele);
    printf("\n");




    return 0;
}