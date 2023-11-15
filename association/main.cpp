#include <iostream>
#include <graphics.h>

class Point {
    int x, y;

public:
    Point(int x = 0, int y = 0) : x(x), y(y) {}
    int getX() const { return x; }
    int getY() const { return y; }
};//end point class

class Line {
    Point &startP, &endP;

public:
    Line(Point &sp, Point &ep) : startP(sp), endP(ep) {}

    void draw() const {
        line(startP.getX(), startP.getY(), endP.getX(), endP.getY());
    }
}; //end line class

class Circle {
    Point &center;
    int radius;

public:
    Circle(Point &c, int r) : center(c), radius(r) {}

    void draw() const {
        circle(center.getX(), center.getY(), radius);
    }
};//end circle class
int main() {
    int gd = DETECT, gm;
    initgraph(&gd, &gm, "");
    //line
    Point startPoint(100, 100);
    Point endPoint(300, 100);

    Line myLine(startPoint, endPoint);

    myLine.draw();
    //circle
    Point centerPoint(200, 200);
    int radius = 50;

    Circle myCircle(centerPoint, radius);

    myCircle.draw();
    delay(5000); // Display the graphics for 5 seconds

    closegraph();
    return 0;
}
