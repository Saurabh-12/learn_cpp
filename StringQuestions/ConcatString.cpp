#include <iostream>
#include <string>

using std::cout;
using std::cin;
using std::endl;
using std::string;

int main () {

    char str1[80], str2[80];

    cout<<"Enter first string: "<<endl;
    cin.getline(str1, 80);
    
    cout<<"Enter second string: "<<endl;
    cin.getline(str2, 80);

    int l = 0; //Hold length of first string
    
    //Find length of first string.
    for(l = 0; str1[l] != '\0'; l++);

    // Adding Space after First String 
    str1[l++] = ' ';

    //Adding second string content in first
    for(int i = 0; str2[i] != '\0'; i++)
    {
        str1[l++] = str2[i];
    }
	
    str1[l] = '\0';
   
   cout<<"Final concated String  "<<str1<<endl;

   //Using String Class
   string ss1 ="Saurabh";
   string ss2 = " Kumar";
   string ss33 = ss1+ss2;

   cout<<"Final concated String  "<<ss33<<endl;
   if (ss2 == ss1)
    cout << "ss2 == ss1 "<< true << endl;
   else
    cout << "ss2 == ss1 "<< false << endl;

    if (ss2 == ss1)
    cout << "ss2 == ss1 "<< true << endl;
    else
    cout << "ss2 == ss1 "<< false << endl;


    return 0;
}