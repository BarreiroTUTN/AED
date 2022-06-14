#include <cassert>

float farenheitToCelsiusWithValue(float);      // f: R -> R / f(x) = (x - 32) * 0.55555555555;
float farenheitToCelsiusWithExpression(float); // f: R -> R / f(x) = (x - 32) * 5 / 9;

bool validateTolerance(float, float, float);

int main()
{
    float tolerance = 0.0000001;

    float farenheitValues[] = {-25, -22.5, -20, -15, -10, -5, -1, 0, 32, 40, 42.5, 45, 47.5, 50, 52.5, 55, 60, 70, 80};

    for (float farenheit : farenheitValues)
    {
        float celsiusWithValue = farenheitToCelsiusWithValue(farenheit);
        float celsiusWithExpression = farenheitToCelsiusWithExpression(farenheit);

        bool isInsideToleranceInterval = validateTolerance(celsiusWithValue, celsiusWithExpression, tolerance);

        assert(isInsideToleranceInterval == true);
    }
}

float farenheitToCelsiusWithValue(float farenheit)
{
    return (farenheit - 32) * 0.55555555555;
}

float farenheitToCelsiusWithExpression(float farenheit)
{
    return (farenheit - 32) * 5 / 9;
}

bool validateTolerance(float value, float secondValue, float tolerance)
{
    float minValue = secondValue - tolerance;
    float maxValue = secondValue + tolerance;

    return value >= minValue && value <= maxValue;
}