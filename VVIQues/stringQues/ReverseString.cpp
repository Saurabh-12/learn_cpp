#include<iostream>
#include<string>
#include<algorithm>
#include<sstream>
#include<vector>


using namespace std;


string reverseStrings(const string& input){
    string result;
    for(int i = input.length()-1; i >=0; i--)
       result+=input[i];

    return result;
}

void reverseStringsInPlace(string& str){
    int left = 0;
    int right = str.length()-1;

    while(left < right){
         std::swap(str[left], str[right]);
         left++;
         right--;
    }
}

//reverse words in strings
string reverseWordsInSentences(const string& sentence){
    string result = "" ;
    string word;
    stringstream strStream(sentence);
    vector<string>words;
    while(strStream >> word)
      words.push_back(word);
    
    int sizes = words.size();
    cout<<"vector size: "<<sizes<<endl;

  for(int i = sizes-1; i>=0; i--) {
    result +=words[i]+" ";
    //cout<<words[i]<<endl;
  }
        

return result;
}

int main() {

    string ss = "Saurabh";
    //printf("orignal String and reverse string %s, %s \n",ss,reverseStrings(ss));
    cout<<"orignal String: "<<ss<<" Reverse String: "<<reverseStrings(ss)<<endl;
    cout<<"******************\n";
    reverseStringsInPlace(ss);
    cout<<ss<<endl;

// Using c++ reverse string 
cout<<"******************\n";
    string code = "gnirts a esrever";
    cout << "Original: " << code << std::endl;
    std::reverse(code.begin(), code.end());
    cout << "Reversed: " << code << endl;

    //reverse words in strings
    cout<<"******************\n";
    string sent = "I love C++ programming";
    string reverseSent = reverseWordsInSentences(sent);
    cout<<reverseSent<<endl;



    return 0;
}