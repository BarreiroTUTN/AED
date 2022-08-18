#include <cassert>

unsigned sum(unsigned);
// Sum :N --> N / Sum(x) =
// { 0              si x=0
// { x + Sum(x-1).  e.o.c

int main()
{
    assert(sum(0) == 0);
    assert(sum(1) == 1);
    assert(sum(2) == 3);
    assert(sum(5) == 15);
    assert(sum(10) == 55);
    assert(sum(100000) == 705082704);
}

unsigned sum(unsigned x)
{
    return x == 0 ? 0 : x + sum(x - 1);
}