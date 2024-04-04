#include <iostream>

class Point {
    private:
    float coordinateContainer[2];

    public:
    Point() {
        coordinateContainer[0] = 0;
        coordinateContainer[1] = 0;
    }

    Point(float x, float y) {
        coordinateContainer[0] = x;
        coordinateContainer[1] = y;
    }

    Point(const Point& pt) {
        coordinateContainer[0] = pt.coordinateContainer[0];
        coordinateContainer[1] = pt.coordinateContainer[1];
    }

    ~Point() {
        ;
    }

    void  Set(float x, float y);
    void  Move(float x, float y);
    void  Rotate();
    void  Reflect();
    float GetVertical() const;
    float GetHorizontal() const;
};