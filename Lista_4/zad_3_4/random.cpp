#include "random.h"

Random::Random::Random(int f1)
: _fn(f1)
{
    assert( f1 > 0 && f1 < 2147483647 );
}

double Random::Random::operator()()
{
    long long x = _fn;
    x *= 16807;
    x %= 2147483647;
    _fn = static_cast<int>(x);
    return x / 2147483646.0;
}

