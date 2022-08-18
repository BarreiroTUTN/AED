#include <cassert>
#include <cmath>

using namespace std;

bool AreNear(double, double, double = 0.001);
// f: R x R x R^+ -> B / f(x, y, z) =
// V si y - z <= x <= y + z;
// F si x < y - z, x > y + z;

struct Point
{
    double x{0}, y{0}, z{0};
};

double distanceBetweenPoints(Point a, Point b);

void testDistanceBetweenPoints();

int main()
{
    testDistanceBetweenPoints();
}

void testDistanceBetweenPoints()
{
    assert(AreNear(distanceBetweenPoints(Point{5}, Point{5}), 0));

    assert(AreNear(distanceBetweenPoints(Point{5}, Point{-5}), 10));
    assert(AreNear(distanceBetweenPoints(Point{-5}, Point{5}), 10));

    assert(AreNear(distanceBetweenPoints(Point{5, 5}, Point{5, 5}), 0));
    assert(AreNear(distanceBetweenPoints(Point{5, 5}, Point{5, 5}), 0));

    assert(AreNear(distanceBetweenPoints(Point{0, 5}, Point{0, -5}), 10));
    assert(AreNear(distanceBetweenPoints(Point{0, -5}, Point{0, 5}), 10));

    assert(AreNear(distanceBetweenPoints(Point{0, 0, -5}, Point{0, 0, 5}), 10, 1));
    assert(AreNear(distanceBetweenPoints(Point{0, 0, 5}, Point{0, 0, -5}), 10, 1));
}

double distanceBetweenPoints(Point a, Point b)
{
    double xDistance = pow(a.x - b.x, 2);

    double yDistance = pow(a.y - b.y, 2);

    double zDistance = pow(a.z - b.z, 2);

    return sqrt(xDistance + yDistance + zDistance);
}

bool AreNear(double value, double secondValue, double tolerance)
{
    double minValue = secondValue - tolerance;
    double maxValue = secondValue + tolerance;

    return value >= minValue && value <= maxValue;
}