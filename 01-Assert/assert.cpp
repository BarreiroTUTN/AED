#include <cassert>
#include <string>
using namespace std::literals;

int main()
{
    // Tipo de dato bool:
    assert(true);
    assert(false == false);
    assert(true != false);
    assert(!false);
    assert(!false == true);
    assert(false || true);
    assert(true && true);
    assert(false || true && false == false);
    assert((false || true) && false == false);
    assert(true || true && false);

    // Tipo de dato double:
    assert(2.0 == 1.0 + 1.0);
    assert(0.1 == 1.0 / 10.0);
    assert(1 == 1.0);
    assert(2.0 == 1 + 1.0);
    assert(2 == 1 + 1.0);

    // Tipo de dato string:
    assert("Hello World"s == "Hello"s + " " + "World");
    assert("Hello World"s.length() == 11);

    // Tipo de dato int:
    assert(2 == 1 + 1);
    assert(5 == 2 + 3);
    assert(7 == 3 + 4);
}