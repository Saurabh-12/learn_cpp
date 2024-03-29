#include <stdio.h>
#include <iostream>
#include <vector>

using namespace std;

#define NUM_PEOPLE 5

// Function to find the last person standing using mathematical analysis
int find_last_person() {
    int last_person = 0;
    for (int i = 2; i <= NUM_PEOPLE; i++) {
        last_person = (last_person + 2) % i;
    }
    return last_person + 1; // Adding 1 to convert from 0-based index to 1-based index
}

int main() {
    int last_person = find_last_person();
    printf("The last person standing is: %d\n", last_person);



    int person = 100;
 
    // Placeholder array for person
    vector<int> a(person);
 
    // Assign placeholders from 1 to N (total person)
    for (int i = 0; i < person; i++) {
        a[i] = i + 1;
    }
 
    // Will start the game from 1st person (Which is at
    // placeholder 0)
    int pos = 0;
 
    // Game will be continued till we end up with only one
    // person left
    while (a.size() > 1) {
        // Current person will shoot the person next to
        // him/her. So incrementing the position.
        pos++;
        // As person are standing in circular manner, for
        // person at last place has right neighbour at
        // placeholder 0. So we are taking modulo to make it
        // circular
        pos %= a.size();
        // Killing the person at placeholder 'pos'
        // To do that we simply remove that element
        a.erase(a.begin() + pos);
        // There is no need to increment the pos again to
        // pass the gun Because by erasing the element at
        // 'pos', now next person will be at 'pos'.
    }
 
    // Print Person that survive the game
    cout << a[0]<<endl;


    return 0;
}