#include <iostream>
#include <stdio.h>
#include <string.h>


//pointer version of strCpy
void astrCpy(char *dest, const char *src);
// Array version of strCpy
void arrstrCpy(char dest[], const char src[]);
//strcat
void astrcat(char *str1, const char *str2);

int main () {

    char name []  = {"saurabh kumar sharma"};
    char userName [20] ;

    printf("%s \n", name);

    //printf("\n Enter First Name: ");
    //scanf("%s", userName);

    //std::cout << "Hello " << userName << std::endl;

    int num ;

   // printf("\n Enter Number: ");
   // scanf("%d", &num);
   // std::cout << "Number is " << num << std::endl;

    char str1[] = "Sharma kumar Saurabh Govind kumar sharma";
    char str2 [1];
    //astrCpy(str2, str1);
    arrstrCpy(str2, str1);

    printf("str2 %s", str2);
    printf("\n");
    char strCat1 [] = "Hello";
    char strCat2 [] = "World";
    astrcat(strCat1, strCat2);
    printf("strCat1 + StrCat2 =  %s", strCat1);
    printf("\n");
    printf("strCat1 + StrCat2 =  %s", strCat2);
    printf("\n");


    return 0;
}

void astrCpy(char *dest, const char *src) {
    while (*src!= '\0') {
        *dest = *src;
        dest++;
        src++;
    }
    *dest = '\0';
    //return *dest;
}

void arrstrCpy(char dest[], const char src[]) {
    int i = 0;
    while (dest[i++] = src[i]);
}

void astrcat(char *str1, const char *str2) {
    int j = 0;
    int i = strlen(str1);
    while (str1[i++] = str2[j++]);
}