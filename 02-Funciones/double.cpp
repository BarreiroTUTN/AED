#include <cassert>

double duplicate(double); // f: R -> R / f(x) = 2x;

int main()
{
    assert(-2 == duplicate(-1));
    assert(2 == duplicate(1));
    assert(0 == duplicate(0));
    assert(2.2 == duplicate(1.1));
    assert(0.25 == duplicate(0.125));
    assert(-0.25 == duplicate(-0.125));
}

double duplicate(double x)
{
    return 2 * x;
}