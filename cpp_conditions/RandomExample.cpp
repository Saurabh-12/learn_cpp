#include<iostream>
#include <cstdlib> // for rand() and srand()
#include <ctime> // for time()

// Generate a random number between min and max (inclusive)
// Assumes srand() has already been called
// Assumes max - min <= RAND_MAX
int getRandomNumber(int min, int max)
{
    // static used for efficiency, so we only calculate this value once
    static const double fraction = 1.0 / (static_cast<double>(RAND_MAX) + 1.0);
    // evenly distribute the random number across our range
    return min + static_cast<int>((max - min + 1) * (rand() * fraction));
}

void generateRandomNumber(int max_no)
{
    srand(static_cast<unsigned int>(time(0))); // set initial seed value to system clock
    
        for (int count=1; count <= max_no; ++count)
        {
            std::cout << rand() << "\t";
     
            // If we've printed 5 numbers, start a new row
            if (count % 5 == 0)
                std::cout << "\n";
        }
}

int main()
{
    std::cout<<getRandomNumber(1,6)<<"\n";

    return 0;
}