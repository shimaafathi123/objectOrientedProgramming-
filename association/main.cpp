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

public:

    void draw(Point sp, Point ep) const {
        line(sp.getX(), sp.getY(), ep.getX(), ep.getY());
    }
}; //end line class

class Circle {
    int radius;

public:
    Circle(int r){
        radius=r;
    }
    void draw(Point c) const {
        circle(c.getX(), c.getY(), radius);
    }
};//end circle class
int main() {
    int gd = DETECT, gm;
    initgraph(&gd, &gm, "");
    //line
    Point startPoint(100, 100);
    Point endPoint(300, 100);
    Line myLine;

    myLine.draw(startPoint,endPoint);
    //circle
    Point centerPoint(200, 200);
    int radius = 50;

    Circle myCircle(70);

    myCircle.draw(centerPoint);
    delay(5000); // Display the graphics for 5 seconds

    closegraph();
    return 0;
}
