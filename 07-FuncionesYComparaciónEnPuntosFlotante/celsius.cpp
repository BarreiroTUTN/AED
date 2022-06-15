#include <cassert>

double farenheitToCelsiusWithValue(double);      // f: R -> R / f(x) = (x - 32) * 0.55555555555;
double farenheitToCelsiusWithExpression(double); // f: R -> R / f(x) = (x - 32) * 5 / 9;

bool validateTolerance(double, double, double); // f: R -> R / f(x, y, z) = x < y + z && x > y - z;

int main()
{
    double tolerance = 0.000000001;

    double farenheitValues[] = {-25, -22.5, -20, -15, -10, -5, -1, 0, 32, 40, 42.5, 45, 47.5, 50, 52.5, 55, 60, 70, 80};

    for (double farenheit : farenheitValues)
    {
        double celsiusWithValue = farenheitToCelsiusWithValue(farenheit);
        double celsiusWithExpression = farenheitToCelsiusWithExpression(farenheit);

        bool isInsideToleranceInterval = validateTolerance(celsiusWithValue, celsiusWithExpression, tolerance);

        assert(isInsideToleranceInterval == true);
    }
}

double farenheitToCelsiusWithValue(double farenheit)
{
    return (farenheit - 32) * 0.55555555555;
}

double farenheitToCelsiusWithExpression(double farenheit)
{
    return (farenheit - 32) * 5 / 9;
}

bool validateTolerance(double value, double secondValue, double tolerance)
{
    double minValue = secondValue - tolerance;
    double maxValue = secondValue + tolerance;

    return value >= minValue && value <= maxValue;
}