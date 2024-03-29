#include <iostream>
#include <stdio.h>


int main () {

    char name []  = {"saurabh kumar sharma"};
    char userName [20] ;

    printf("%s", name);

    printf("\n Enter First Name: ");
    scanf("%s", userName);

    std::cout << "Hello " << userName << std::endl;

    int num ;

    printf("\n Enter Number: ");
    scanf("%d", &num);
    std::cout << "Number is " << num << std::endl;


    return 0;
}