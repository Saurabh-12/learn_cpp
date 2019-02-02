#ifndef BASEBALLPLAYER_H
#define BASEBALLPLAYER_H

#include<iostream>
#include"PersonExample.cpp"


class BaseballPlayer : public PersonExample{
public:
    double m_battingAverage;
    int m_homeRuns;
 
    BaseballPlayer(double battingAverage = 0.0, int homeRuns = 0)
       : m_battingAverage(battingAverage), m_homeRuns(homeRuns)
    {
    }
};
#endif