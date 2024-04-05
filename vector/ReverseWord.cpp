#include <iostream>
#include <vector>

using namespace std;


int main() {

    string name ("Saurabh Kumar Sharma");
    cout << "Name before Reverse: "<<name << endl;

    vector<string> reverseName;
    string temp = " ";

    for (int i = 0 ; i < name.length(); i++) {
        if (name[i] == ' ') {
            reverseName.push_back(temp);
            temp = " ";
        } else {
            temp = temp + name[i];
        }
    }
    reverseName.push_back(temp);

    for (int i = reverseName.size()-1; i >= 0; i--) {
        cout << reverseName[i] << " ";
    }

    printf("\n");


    return 0;
}