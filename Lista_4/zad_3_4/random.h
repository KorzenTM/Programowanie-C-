#include <ctime>
#include <iostream>
#include <cassert>

#ifndef MAIN_RANDOM_H
#define MAIN_RANDOM_H

class Random
{
    int _fn;
public:
    Random(int f1 = time(0));
    double operator()();
};

#endif //MAIN_RANDOM_H
