#include <iostream>
#include <string>

int main()
{
    std::string name = "Saurabh Sharma";
    std::cout << name << "\n";

    std::cout << "Enter your full name " << "\n";
    std::string fName;
    std::getline(std::cin, fName); // read a full line of text into name

    std::cout << "Enter your age"<< "\n";
    int age;
    std::cin >> age;

    int letters = fName.length(); // get number of letters in name (including spaces)
    double agePerLetter = static_cast<double>(age) / letters;

    std::cout << "You've lived " << agePerLetter << " years for each letter in your name.\n";

    return 0;
}
