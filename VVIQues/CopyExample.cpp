#include <iostream>
#include <string.h>
# include <stdio.h>



using std::cout;
using std::cin;
using std::endl;
using std::string ;

char* strcpy1(char *dest, const char *src)
{
    char *ret = dest;
    while (*dest++ = *src++);
    return ret;
}

char *strcpy2(char *dest, const char *src) {
    char *ptr = dest;
    while (*src!= '\0')
    {
        *dest = *src;
        dest++;
        src++;
    }
    *dest ='\0'; 
    return ptr;
}

int main()
{
    char ss[20] = "Learn c and cpp";
    char dd [20];

    strcpy(dd,ss);

    cout <<"copied String  or char is : "<<dd<<endl;    
    return 0;
}
