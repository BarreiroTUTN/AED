#include <cassert>

double farenheitToCelsius(double); // f: R -> R / f(x) = (x - 32) * 5 / 9;

bool AreNear(double, double, double); // f: R x R x R^+ -> B / f(x, y, z) = y - z <= x <= y + z;

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
    assert(AreNear(1, 0, 1));
    assert(AreNear(0, 1, 1));
    assert(AreNear(0.5, 1, 1));
    assert(AreNear(1, 0.5, 1));
    assert(!AreNear(1, 2, 0.1));
    assert(!AreNear(2, 1, 0.1));
}

void testCelsius()
{
    transformToCelsiusAndValidate(32, 0);
    transformToCelsiusAndValidate(75, 24);
    transformToCelsiusAndValidate(40, 4);
}

void transformToCelsiusAndValidate(double farenheit, double correctCelsius)
{
    double tolerance = 1;

    double celsius = farenheitToCelsius(farenheit);

    bool isInsideToleranceInterval = AreNear(celsius, correctCelsius, tolerance);

    assert(isInsideToleranceInterval);
}

double farenheitToCelsius(double farenheit)
{
    return (farenheit - 32) * 5 / 9;
}

bool AreNear(double value, double secondValue, double tolerance = 0.001)
{
    double minValue = secondValue - tolerance;
    double maxValue = secondValue + tolerance;

    return value >= minValue && value <= maxValue;
}