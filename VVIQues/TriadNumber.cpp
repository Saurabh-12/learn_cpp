# include <iostream>

using namespace std;


int main () {

    /*
    The triad numbers is a set of three numbers which satisfy the following condition:
              1. Each number must be a 3 digit number
              2. All the digits in the numbers must be unique.
              3. The second number must be twice the first number and the third number must be thrice the first.
    */

   int d1, d2, d3,tmp;

   //3 digit number start from 100 to 999

   //Loop A generate the number
   for (int num = 100; num < 999/3; num++){

    // loop B check for unique digits in the first number
        for (int i = num; i <= num * 3; i += num){
            tmp = i;
            d1 = tmp % 10;

            tmp = tmp / 10;
            d2 = tmp % 10;

            tmp = tmp / 10;
            d3 = tmp % 10;

            if (d1 == d2 || d2 == d3 || d3 == d1) {
                goto next;
            }
        }

        // Loop C check whether the given three numbers have unique digits or not
        for (int a = num; a > 0; a /= 10) 
        {
            d1 = a % 10;

            // Loop D check whether the given three numbers have unique digits or not
            for (int b = num * 2; b > 0; b /= 10) 
            {
                d2 = b % 10;

                // Loop E check whether the given three numbers have unique digits or not
                for (int c = num * 3; c > 0; c /= 10) 
                {
                    d3 = c % 10;

                    if (d1 == d2 || d2 == d3 || d3 == d1) 
                    {
                        goto next;
                    }
                }
            }
        }

        printf("%d %d %d\n", num, num * 2, num * 3);

        next:;
   }
   return 0;
   }