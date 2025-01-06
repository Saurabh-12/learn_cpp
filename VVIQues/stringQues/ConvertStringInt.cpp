# include <iostream>
# include <string>

using namespace std;



int convertStringInt(string s) {
    int result = 0;
    int multiply = 1;

    for (int i = s.length()-1; i >= 0; i--) {
        result += (s[i] - '0') * multiply;
        multiply *= 10;
    }

    return result;
}

int convertStringAsInt(const string ss){
    int result = 0;
    int multiply = 1;

    for(int i = 0; i<ss.length(); i++){
        result +=ss[i]*multiply;
        multiply *= 10;
    }

    return result;
}


int main() {

    string s = "345";
    int result = convertStringInt(s);
   //int result = convertStringAsInt(s);
    cout << "string 345 as int: "<<result << endl;

    return 0;

}