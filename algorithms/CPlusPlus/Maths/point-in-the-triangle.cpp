#include<iostream>
using namespace std;

class fPoint {
public:
    int x, y;

};

int sign(fPoint p1, fPoint p2, fPoint p3) {
    return (p1.x - p3.x) * (p2.y - p3.y) - (p2.x - p3.x) * (p1.y - p3.y);
}

bool PointInTriangle(fPoint pt, fPoint v1, fPoint v2, fPoint v3) {
    int d1, d2, d3;
    bool has_neg, has_pos;

    d1 = sign(pt, v1, v2);
    d2 = sign(pt, v2, v3);
    d3 = sign(pt, v3, v1);

    has_neg = (d1 <= 0) || (d2 <= 0) || (d3 <= 0);
    has_pos = (d1 >= 0) || (d2 >= 0) || (d3 >= 0);

    return !(has_neg && has_pos);
}


int main() {

    fPoint*vertices = new fPoint[3];

    //Input the 3 vertices of triangle.
    for (int i = 0; i < 3; i++) {
        int x, y;
        cin >> x >> y;
        fPoint Point;
        Point.x = x;
        Point.y = y;
        vertices[i] = Point;
    }
    //point to be checked
    int targetX, targetY;
    cin >> targetX >> targetY;

    fPoint Target;
    Target.x = targetX;
    Target.y = targetY;

    if (PointInTriangle(Target, vertices[0], vertices[1], vertices[2])) {
        cout << "Yes, the point lies competely inside the triangle" << "\n";
    } else {
        cout << "No, the point lies outside the triangle" << "\n";
    }

}

