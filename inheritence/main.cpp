#include <iostream>
#include <graphics.h>
using namespace std;
class Point {
    int x, y;

public:
    Point(int x = 0, int y = 0) : x(x), y(y) {}
    int getX() const { return x; }
    int getY() const { return y; }
    void draw() const {
        putpixel(x, y, WHITE);
    }

};//end point class

class Line : public Point {
    Point endP;

public:
    Line(Point sp, Point ep) : Point(sp), endP(ep) {}

    void draw() const {
        Point::draw();
        line(getX(),getY(),endP.getX(), endP.getY());
    }
}; //end line class

class Circle:public Point {
    int radius;

public:
    Circle(Point c, int r) : Point(c), radius(r) {}

    void draw() const {
        Point::draw();
        circle(getX(), getY(), radius);
    }
};//end circle class

class Triangle : public Point {
    Point point2, point3;

public:
    Triangle(Point p1, Point p2, Point p3) : Point(p1), point2(p2), point3(p3) {}

    void draw() const {
        Point::draw();
        line(getX(), getY(), point2.getX(), point2.getY());
        line(point2.getX(), point2.getY(), point3.getX(), point3.getY());
        line(point3.getX(), point3.getY(), getX(), getY());
    }
};//end triangle class
int main() {
    int gd = DETECT, gm;
    initgraph(&gd, &gm, "");
    //line
    int n, choose;
    cout << "How many times do you want to print a shape?" << endl;
    cin >> n;

    for (int i = 1; i <= n; i++) {
        cout << "Choose a shape to draw (1: Line, 2: Circle, 3: Triangle): ";
        cin >> choose;

        switch (choose) {
            case 1: {
                // Line
                int n,m,b,c;
                cout<<"enter start point"<<endl;
                cin>>n>>m;
                cout<<"enter end point"<<endl;
                cin>>b>>c;
                Point startPoint(n, m);
                Point endPoint(b, c);
                Line myLine(startPoint, endPoint);
                myLine.draw();
                break;
            }
            case 2: {
                // Circle
                int h,j;
                cout<<"Enter the center point"<<endl;
                cin>>h>>j;
                Point centerPoint(h, j);
                int radius ;
                cout<<"enter radius"<<endl;
                cin>>radius;
                Circle myCircle(centerPoint, radius);
                myCircle.draw();
                break;
            }
            case 3: {
                // Triangle
                int f,q,w,t,g,k;
                cout<<"enter point"<<endl;
                cin>>f>>q;
                cout<<"enter point"<<endl;
                cin>>w>>t;
                cout<<"enter point"<<endl;
                cin>>g>>k;
                Point vertex1(f, q);
                Point vertex2(w, t);
                Point vertex3(g, k);
                Triangle myTriangle(vertex1, vertex2, vertex3);
                myTriangle.draw();
                break;
            }
            default:
                cout << "Invalid choice\n";
                i--;  // Decrement i to repeat the current iteration
                break;
        }
    }


    delay(5000); // Display the graphics for 5 seconds

    closegraph();
    return 0;
}
