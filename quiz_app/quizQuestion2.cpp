#include <iostream>
#include "constant.h"


// gets initial height from user and returns it
double getInitialHeight()
{
    std::cout << "Enter the height of the tower in meters: ";
    double initialHeight ;
    std::cin>>initialHeight;
    return initialHeight;
}

// Returns height from ground after "seconds" seconds
double calculateHeight(double initHeight, int sec)
{
    // Using formula: [ s = u * t + (a * t^2) / 2 ], here u(initial velocity) = 0
    double distanceFallen = (MY_Constant::gravity *sec*sec)/2;
    double currentHeight = initHeight - distanceFallen;
    return currentHeight;
}

// Prints height every second till ball has reached the ground
void printHeight(double height, int sec)
{
    if(height >0.0){
        std::cout << "At " << sec << " seconds, the ball is at height: " << height << " meters\n";
    }
    else{
        std::cout << "At " <<sec <<" seconds, the ball is on the ground.\n ";
    }
}
// Calculate and print 
void calculateAndPrintHeight(double initialHeight, int seconds)
{
    double height = calculateHeight(initialHeight, seconds);
	printHeight(height, seconds);
}

int main()
{
	const double initialHeight = getInitialHeight();
 
	calculateAndPrintHeight(initialHeight, 0);
	calculateAndPrintHeight(initialHeight, 1);
	calculateAndPrintHeight(initialHeight, 2);
	calculateAndPrintHeight(initialHeight, 3);
	calculateAndPrintHeight(initialHeight, 4);
	calculateAndPrintHeight(initialHeight, 5);
 
	return 0;
}