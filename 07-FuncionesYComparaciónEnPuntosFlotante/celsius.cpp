#include <cassert>

double farenheitToCelsius(double); // f: R -> R / f(x) = 5 / 9 (x - 32);

bool AreNear(double, double, double = 0.001);
// f: R x R x R^+ -> B / f(x, y, z) =
// V si y - z <= x <= y + z;
// F si x < y - z, x > y + z;

void transformToCelsiusAndValidate(double, double);

void testAreNear();
void testCelsius();

int main()
{
    testAreNear();

    testCelsius();
}

void testAreNear()
{
    assert(AreNear(1, 1, 0.1));

    assert(AreNear(1.5, 0, 1.5));
    assert(AreNear(0, 1.5, 1.5));

    assert(AreNear(0.5, 1, 1));
    assert(AreNear(1, 0.5, 1));

    assert(!AreNear(1, 2, 0.1));
    assert(!AreNear(2, 1, 0.1));

    assert(AreNear(1, 1));

    assert(!AreNear(1, 2));
    assert(!AreNear(2, 1));

    assert(AreNear(1, 1.001));
    assert(AreNear(1.001, 1));
}

void testCelsius()
{
    transformToCelsiusAndValidate(32, 0);
    transformToCelsiusAndValidate(75, 24);
    transformToCelsiusAndValidate(40, 4);
}

void transformToCelsiusAndValidate(double farenheit, double correctCelsius)
{
    double tolerance = 0.5;

    double celsius = farenheitToCelsius(farenheit);

    bool isInsideToleranceInterval = AreNear(celsius, correctCelsius, tolerance);

    assert(isInsideToleranceInterval);
}

double farenheitToCelsius(double farenheit)
{
    return (farenheit - 32) * 5 / 9;
}

bool AreNear(double value, double secondValue, double tolerance)
{
    double minValue = secondValue - tolerance;
    double maxValue = secondValue + tolerance;

    return value >= minValue && value <= maxValue;
}