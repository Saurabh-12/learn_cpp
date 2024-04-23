# include <iostream>
# include <algorithm>
# include <string>
#include <sstream>
#include <map>

using namespace std;


bool isPalindrome(string str) {
    string str1 = str;
    reverse(str1.begin(), str1.end());
    if (str1 == str) {  
        return true;
    } else {
        return false;
    }
}

void toLowercase(string &str) {
    for (int i = 0; i < str.length(); i++) {
        //str[i] = tolower(str[i]);
         if (str[i] >= 'A' && str[i] <= 'Z') {
                str[i] = str[i] + 32;
            }
    }
}

void toUppercase(string &str) {
    for (int i = 0; i < str.length(); i++) {
        //str[i] = toupper(str[i]);
        if (str[i]>='a' && str[i]<='z') {
            str[i] = str[i]-32;
        }
    }
}
void sortString(string &str)
{
    int temp = 0, i, j;
    for (i = 0; i < str.length() - 1; i++)
    {
        for (j = i + 1; j < str.length(); j++)
        {
            if (str[i] > str[j])
            {
                temp = str[i];
                str[i] = str[j];
                str[j] = temp;
            }
        }
    }
}

bool isAnagram(string str1, string str2)
{
    if (str1.length() != str2.length())
    {
        return false;
    }
    else
    {
        //sort(str1.begin(), str1.end());
        //sort(str2.begin(), str2.end());
        toLowercase(str1);
        toLowercase(str2);
        sortString(str1);
        sortString(str2);
        if (str1 == str2)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
}

//search a character occurence in a string and print the count of the character
int searchCharacter(string str, char ch) {
    int count = 0;
    for (int i = 0; i < str.length(); i++) {
        if (str[i] == ch) {
            count++;
        }
    }
    return count;
}
// count the number of words in a string and print each word in separate line
int countWords(string str) {
    int count = 0;
    for (int i = 0; i < str.length(); i++) {
        if (str[i] == ' ') {
            count++;
        }
    }
    count++;
    return count;
}

// Function to count the number of words in a string
int sStreamcountWords(const string& str) {
    stringstream iss(str);
    string word;
    int count = 0;

    // Iterate through each word in the string stream
    while (iss >> word) {
        count++;
        cout << word << endl;
    }
    return count;
}
//function to reverse a string wors 
string reverseWords(const string& s) {
    stringstream iss(s);
    string word;
    string reversedString;

    // Read each word from the string stream
    while (iss >> word) {
        // Add each word to the beginning of the reversed string
        reversedString = word + " " + reversedString;
    }

    // Remove the trailing space
    if (!reversedString.empty()) {
        reversedString.pop_back();
    }

    return reversedString;
}

//function to count the number of frequency of each Words in a string
void countWordsFrequency(string str) {
    stringstream iss(str);
    string word;
    map<string, int> wordFreq;
    // Iterate through each word in the string stream
    while (iss >> word) {
        wordFreq[word]++;
    }
    for (auto it : wordFreq) {
        cout << it.first << " " << it.second << endl; 
    }
}

int main () {

    // for given string find the length of the string
    string name = "saurabh kumar Sharma";
    cout << "Name before Reverse: "<<name << endl;
    int length = name.length();
    int size = name.size();
    name.at(0) = 'k';
    cout << "Length of the string is: "<<length << endl;
    cout << "Size of the string is: "<<size << endl;

    // reverse the given string 
    string reverseName = "";
    for (int i = length-1; i >= 0; i--) {
        reverseName = reverseName + name[i];
    }
    cout << "Name after Reverse: "<<reverseName << endl;

    //check string is palindrome or not
    string palindrome = "madam";
    string reversePalindrome = "";
    for (int i = palindrome.length()-1; i >= 0; i--) {
        reversePalindrome = reversePalindrome + palindrome[i];
    }
    if (palindrome == reversePalindrome) {
        cout << "Given string is palindrome: "<<palindrome << endl;
    } else {
        cout << "Given string is not palindrome: "<<palindrome << endl;
    }

    // check given string is anagram or not
    string anagram1 = "Listen";
    string anagram2 = "Silent";
    if (isAnagram(anagram1, anagram2)) {
        cout << "Given string is anagram: "<<anagram1 << " and "<<anagram2 << endl;
    } else {
        cout << "Given string is not anagram: "<<anagram1 << " and "<<anagram2 << endl;
    }
    string reverseStr = "Saurabh Kumar Sharma";
    int count = searchCharacter(reverseStr, 'a');
    cout << "Character 'a' count in "<<reverseStr<< " is " <<count<< endl;
    count = sStreamcountWords(reverseStr);
    cout << "Number of words in "<<reverseStr<< " is " <<count<< endl;
    cout << "Reverse of "<<reverseStr<< " is " <<reverseWords(reverseStr)<< endl;

    string strFreq = "In Democracy people elects people in people In Democracy";
    countWordsFrequency(strFreq);
    string strSmall = "saurabh";
    toUppercase(strSmall);
    cout<<" small to uppercase "<<strSmall<<endl;

    return 0;
}
