# include <iostream>
# include <vector>

using namespace std;

// Solving Josephus circle problem using Vector in C++
int returnLastSelectedPerson(vector<int> &people, int elimeeliminationCount) {
    // Start eliminating people until only one remains
    int index = 0;
    while (people.size() > 1) {
        // Compute the index of the person to be eliminated
        index = (index + elimeeliminationCount - 1) % people.size();
        
        // Eliminate the person at the computed index
        people.erase(people.begin() + index);
    }

    // Return the last remaining person
    return people[0];

}

// Solving Josephus circle problem using recursion in C++
// elimeliminationCount = k
int josephusCircle(vector<int> &person, int k, int index) {
       // Base case , when only one person is left
    if (person.size() == 1) {
        return person[0];
    }
 
    // find the index of first person which will be eliminated
    index = ((index + k-1) % person.size());
 
    // remove the first person which is going to be killed
    person.erase(person.begin() + index);
 
    // recursive call for n-1 persons
    return josephusCircle(person, k, index);
    
}

int josephusCircleUsingForLoop(vector<int> &person, int k) {
    int index = 0;
    // Start eliminating people until only one remains
    for (int i = 0; i < person.size(); i++) {
        index = (index + k - 1) % person.size();
        person.erase(person.begin() + index);
    }
    return person[0];
}


int main () {

    vector<int> circle;
    for (int i = 1; i <= 5; ++i) {
        circle.push_back(i);
    }

    //int lastPerson = returnLastSelectedPerson(circle, 2);
    //int lastPerson = josephusCircle(circle, 2, 0);
    int lastPerson = josephusCircleUsingForLoop(circle, 2);
    cout<<"Last person standing is: "<<lastPerson<<endl;

    return 0;
}