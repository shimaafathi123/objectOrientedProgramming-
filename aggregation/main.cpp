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
    Point *ptr1, *ptr2;

public:
    Line(Point *sp, Point *ep)  {
            ptr1=sp;
            ptr2=ep;
    }

    void draw() const {
        line(ptr1->getX(), ptr1->getY(), ptr2->getX(), ptr2->getY());
    }
}; //end line class

class Circle {
    Point *ptr;
    int radius;

public:
    Circle(Point *c, int r) :radius(r) {
        ptr=c;
    }

    void draw() const {
        circle(ptr->getX(), ptr->getY(), radius);
    }
};//end circle class
int main() {
    int gd = DETECT, gm;
    initgraph(&gd, &gm, "");
    //line
    Point *startPoint = new Point(100, 100);
    Point *endPoint = new Point(300, 100);

    Line myLine(startPoint, endPoint);

    myLine.draw();
    //circle
    Point *centerPoint = new Point(200, 200);
    int radius = 50;

    Circle myCircle(centerPoint, radius);

    myCircle.draw();
    delay(5000); // Display the graphics for 5 seconds

    closegraph();
    return 0;
}
