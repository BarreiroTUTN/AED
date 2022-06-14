#include <cassert>

float farenheitToCelsiusWithValue(float);      // f: R -> R / f(x) = (x - 32) * 0.55555555555;
float farenheitToCelsiusWithExpression(float); // f: R -> R / f(x) = (x - 32) * 5 / 9;

bool validateTolerance(float, float, float);

void validateFloatingPointExecution(float);

int main()
{
    validateFloatingPointExecution(0);
    validateFloatingPointExecution(32);
    validateFloatingPointExecution(40);
    validateFloatingPointExecution(42.5);
    validateFloatingPointExecution(45);
    validateFloatingPointExecution(47.5);
    validateFloatingPointExecution(50);
    validateFloatingPointExecution(52.5);
    validateFloatingPointExecution(55);
    validateFloatingPointExecution(60);
    validateFloatingPointExecution(70);
    validateFloatingPointExecution(80);
}

void validateFloatingPointExecution(float farenheit)
{
    float tolerance = 0.1;

    float celsiusWithValue = farenheitToCelsiusWithValue(farenheit);
    float celsiusWithExpression = farenheitToCelsiusWithExpression(farenheit);

    bool isInsideToleranceInterval = validateTolerance(celsiusWithValue, celsiusWithExpression, tolerance);

    assert(isInsideToleranceInterval == true);
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

    return value >= minValue || value <= maxValue;
}