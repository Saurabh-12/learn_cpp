#include<iostream>

struct Advertisment
{
int adsShown;
double clickThroughRatePercentage;
double averageEarningsPerClick;

};

void printAdvertising(Advertisment adv)
{
    std::cout<<"Number of ads shown: "<< adv.adsShown<<"\n";
    std::cout<<"click through rate: "<< adv.clickThroughRatePercentage<<"\n";
    std::cout <<"Average earnings per clicks: $ "<<adv.averageEarningsPerClick<<"\n";

     // The following line is split up to reduce the length
    // We need to divide ad.clickThroughRatePercentage by 100 because it's a percent of 100, 
    // not a multiplier
    std::cout << "Total Earnings: $" <<
    (adv.adsShown * adv.clickThroughRatePercentage / 100 * adv.averageEarningsPerClick) << '\n';
}


int main()
{
 // Declare an Advertising struct variable
 Advertisment ad;
 
    std::cout << "How many ads were shown today? ";
    std::cin >> ad.adsShown;
    std::cout << "What percentage of users clicked on the ads? ";
    std::cin >> ad.clickThroughRatePercentage;
    std::cout << "What was the average earnings per click? ";
    std::cin >> ad.averageEarningsPerClick;
 
    printAdvertising(ad);

    return 0;
}