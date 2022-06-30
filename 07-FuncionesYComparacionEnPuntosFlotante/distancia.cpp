#include <cassert>
#include <cmath>

bool AreNear(double, double, double = 0.001);
// f: R x R x R^+ -> B / f(x, y, z) =
// V si y - z <= x <= y + z;
// F si x < y - z, x > y + z;

struct Point
{
    double x{0}, y{0}, z{0};
};

double distanceBetween(double, double, double, double); // f:R^2xR^2--> R/f(ax,ay,bx,by) = ((x1-x2)^2 + (y1-y2)^2)^1/2
double distanceBetweenRn(double, double, double = 0, double = 0, double = 0, double = 0);
double distanceBetweenPoints(Point a, Point b);

void testDistanceBetween();
void testDistanceBetweenRn();
void testDistanceBetweenPoints();

int main()
{
    testDistanceBetween();
    testDistanceBetweenRn();
    testDistanceBetweenPoints();
}

void testDistanceBetween()
{
    assert(AreNear(distanceBetween(5, 5, 0, 0), 7, 1));
    assert(AreNear(distanceBetween(0, 0, 5, 5), 7, 1));

    assert(AreNear(distanceBetween(5, 5, 5, 5), 0));
    assert(AreNear(distanceBetween(5, 5, 5, 5), 0));

    assert(AreNear(distanceBetween(4, 2, 5, 8), 6, 1));
    assert(AreNear(distanceBetween(5, 8, 4, 2), 6, 1));

    assert(AreNear(distanceBetween(-5, 0, 5, 0), 10));
    assert(AreNear(distanceBetween(5, 0, -5, 0), 10));

    assert(AreNear(distanceBetween(0, -5, 0, 5), 10));
    assert(AreNear(distanceBetween(0, 5, 0, -5), 10));
}

void testDistanceBetweenRn()
{
    assert(AreNear(distanceBetweenRn(5, 5), 0));

    assert(AreNear(distanceBetweenRn(5, -5), 10));
    assert(AreNear(distanceBetweenRn(-5, 5), 10));

    assert(AreNear(distanceBetweenRn(5, 0, 5, 0), 7, 1));
    assert(AreNear(distanceBetweenRn(0, 5, 0, 5), 7, 1));

    assert(AreNear(distanceBetweenRn(5, 5, 5, 5), 0));
    assert(AreNear(distanceBetweenRn(5, 5, 5, 5), 0));

    assert(AreNear(distanceBetweenRn(4, 5, 2, 8), 6, 1));
    assert(AreNear(distanceBetweenRn(5, 4, 8, 2), 6, 1));

    assert(AreNear(distanceBetweenRn(0, 0, 0, 0, -5.0, 5.0), 10));
    assert(AreNear(distanceBetweenRn(0, 0, 0, 0, 5.0, -5.0), 10));
}

void testDistanceBetweenPoints()
{
    assert(AreNear(distanceBetweenPoints(Point{5}, Point{5}), 0));

    assert(AreNear(distanceBetweenPoints(Point{5}, Point{-5}), 10));
    assert(AreNear(distanceBetweenPoints(Point{-5}, Point{5}), 10));

    assert(AreNear(distanceBetweenPoints(Point{5, 5}, Point{5, 5}), 0));
    assert(AreNear(distanceBetweenPoints(Point{5, 5}, Point{5, 5}), 0));

    assert(AreNear(distanceBetweenPoints(Point{0, 0, -5}, Point{0, 0, 5}), 6, 1));
    assert(AreNear(distanceBetweenPoints(Point{0, 0, 5}, Point{0, 0, -5}), 6, 1));
}

double distanceBetween(double ax, double ay, double bx, double by)
{
    double distanceBetweenX = pow(ax - bx, 2);

    double distanceBetweenY = pow(ay - by, 2);

    return sqrt(distanceBetweenX + distanceBetweenY);
}

double distanceBetweenRn(double ax, double bx, double ay, double by, double az, double bz)
{
    double distanceBetweenX = (ax - bx) * (ax - bx);

    double distanceBetweenZ = pow(az - bz, 2);

    return sqrt(distanceBetweenX + pow(ay - by, 2) + distanceBetweenZ);
}

double distanceBetweenPoints(Point a, Point b)
{
    double distanceBetweenX = pow(a.x - b.x, 2);

    double distanceBetweenY = pow(a.y - b.y, 2);

    double distanceBetweenZ = pow(a.z - b.z, 2);

    return std::sqrt(distanceBetweenX + distanceBetweenZ + distanceBetweenZ);
}
// d(a, b);
// a.d(b);

bool AreNear(double value, double secondValue, double tolerance)
{
    double minValue = secondValue - tolerance;
    double maxValue = secondValue + tolerance;

    return value >= minValue && value <= maxValue;
}