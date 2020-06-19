#include <iostream>
#include <utility>
#include <vector>
#include <cmath>
#include <algorithm>
#ifndef MAIN_HIST_H
#define MAIN_HIST_H

class Hist
{
private:
    std:: vector<double> vec;
public:
    Hist(std:: vector<double> w);
    void show_sort_data();
    void draw_hist();
    ~Hist() {}
};



#endif //MAIN_HIST_H
