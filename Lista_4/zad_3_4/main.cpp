#include <iostream>
#include "random.h"
#include <vector>
#include "hist.h"

int main()
{
    const int N = 100;
    std:: vector<double> v(N);

    Random r;
    for (int i = 0; i < N; i++)
    {
        v[i] = r();
    }
    Hist h(v);
    h.draw_hist();
    return 0;
}

