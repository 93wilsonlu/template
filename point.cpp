#include <algorithm>
#include <cmath>
using namespace std;

struct Point {
    double x, y;
    Point operator+(const Point& p) { return {x + p.x, y + p.y}; }
    Point operator-(const Point& p) { return {x - p.x, y - p.y}; }
    Point operator*(double k) { return {x * k, y * k}; }
    double operator*(const Point& p) { return x * p.x + y * p.y; }
    double operator^(const Point& p) { return x * p.y - y * p.x; }
    double dist() { return sqrt(x * x + y * y); }
    double angle() { return atan2(y, x); }
    void scan() { cin >> x >> y; }
    bool operator==(const Point& p) { return x == p.x && y == p.y; }
    bool operator!=(const Point& p) { return !(*this == p); }
    Point unit() {
        int g = __gcd(x, y);
        return {x / g, y / g};
    }
    int quadrant() {
        if (y > 0) {
            return x > 0 ? 1 : 2;
        }
        return x > 0 ? 4 : 3;
    }
};

bool cmp(Point l, Point r) {
    if (l.quadrant() != r.quadrant()) {
        return l.quadrant() < r.quadrant();
    }
    return (l ^ r) > 0;
}