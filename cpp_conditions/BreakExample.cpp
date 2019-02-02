#include<iostream>

int breakExample()
{
    int sum = 0;

    for (int count = 0; count < 10; count++)
    {
        std::cout << "Enter a number to add, or 0 to exit: ";
        int num;
        std::cin >> num;

        if (num == 0)
            break;

        sum += num;
    }
    return sum;
}

int breakOrReturn()
{
    while (true)
    {
        std::cout << "Enter 'b' to break or 'r' to return: ";
        char ch;
        std::cin >> ch;
        // execution will continue at the first statement beyond the loop
        if (ch == 'b')
            break;

        // return will cause the function to immediately return to the caller (in this case, main())
        if (ch == 'r')
            return 1;
    }
    // breaking the loop causes execution to resume here
    std::cout << "We broke out of the loop\n";
    return 0;
}

//prints all of the numbers from 0 to 19 that aren’t divisible by 4.
int continueExample()
{
    for (int count=0; count  < 20; ++count)
    {
        // if the number is divisible by 4, skip this iteration
        if ((count % 4) == 0)
            continue; // jump to end of loop body
     
        // If the number is not divisible by 4, keep going
        std::cout << count << std::endl;
     
        // The continue statement jumps to here
    }

}

int main()
{
    std::cout << "The sum of all the numbers you entered is " << breakExample() << "\n";
    
    int returnValue = breakOrReturn();
    std::cout << "Function breakOrReturn: " << returnValue << '\n';

    std::cout << "Continue Example \n";
    continueExample();


    return 0;
}