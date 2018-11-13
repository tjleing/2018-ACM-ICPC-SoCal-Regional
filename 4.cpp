#include <bits/stdc++.h>

using namespace std;

double EPS = 1e-12;

struct Point {
    double x;
    double y;
    Point () {}
    Point (double x, double y) : x(x), y(y) {}
    Point (const Point &p) : x(p.x), y(p.y) {}
    Point operator - (const Point &p) {return Point(x - p.x, y - p.y);}
    Point operator + (const Point &p) {return Point(x + p.x, y + p.y);}
    Point operator * (double c) {return Point(x * c, y * c);}
    Point operator / (double c) {return Point(x / c, y / c);}
};


Point p1, p2, p3, p4;

double dot(Point a, Point b) {
    return a.x * b.x + a.y * b.y;
}

double dist2(Point a, Point b) {
    return (a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y);
}

double cross(Point a, Point b) {
    return a.x * b.y - a.y - b.x;
}

bool lines_parallel(Point a, Point b, Point c, Point d) {
    return fabs(cross(b-a, c-d)) < EPS;
}

bool lines_collinear(Point a, Point b, Point c, Point d) {
    return lines_parallel(a, b, c, d) && fabs(cross(a-b, a-c)) < EPS && fabs(cross(c-d, c-a)) < EPS;
}

bool segments_intersect(Point a, Point b, Point c, Point d) {
    if(lines_collinear(a, b, c, d)) {
        if(dist2(a, c) < EPS || dist2(a, d) < EPS || dist2(b, c) < EPS || dist2(b, d) < EPS) {
            return true;
        }
        if(dot(c-a, c-b) > 0 && dot(d-a, d-b) > 0 && dot(c-b, d-b) > 0) {
            return false;
        }
        return true;
    }
    if(cross(d-a, b-a) * cross(c-a, b-a) > 0) return false;
    if(cross(a-c, d-c) * cross(b-c, d-c) > 0) return false;
    return true;
}

Point segment_intersection(Point a, Point b, Point c, Point d) {
    b = b-a;
    d = c-d;
    c = c-a;
    return a + b * (cross(c, d) / cross(b, d));
}

vector<double> quad_intersection(double x) {
    Point bottom(x, -1000006);
    Point top(x, 1000006);
    vector<double> ys;
    if(segments_intersect(bottom, top, p1, p2) && !lines_collinear(bottom, top, p1, p2)) {
        Point intersection = segment_intersection(bottom, top, p1, p2);
        assert(intersection.x == x);
        ys.push_back(intersection.y);
        //cout << p1.x << " " << p1.y << " " << p2.x << " " << p2.y << endl;
        //cout << intersection.x << " " << intersection.y << endl;
    }
    if(segments_intersect(bottom, top, p2, p3) && !lines_collinear(bottom, top, p2, p3)) {
        Point intersection = segment_intersection(bottom, top, p2, p3);
        assert(intersection.x == x);
        ys.push_back(intersection.y);
        //cout << p2.x << " " << p2.y << " " << p3.x << " " << p3.y << endl;
        //cout << intersection.x << " " << intersection.y << endl;
    }
    if(segments_intersect(bottom, top, p3, p4) && !lines_collinear(bottom, top, p3, p4)) {
        Point intersection = segment_intersection(bottom, top, p3, p4);
        assert(intersection.x == x);
        ys.push_back(intersection.y);
        //cout << p3.x << " " << p3.y << " " << p4.x << " " << p4.y << endl;
        //cout << intersection.x << " " << intersection.y << endl;
    }
    if(segments_intersect(bottom, top, p4, p1) && !lines_collinear(bottom, top, p4, p1)) {
        Point intersection = segment_intersection(bottom, top, p4, p1);
        assert(intersection.x == x);
        ys.push_back(intersection.y);
        //cout << p4.x << " " << p4.y << " " << p1.x << " " << p1.y << endl;
        //cout << intersection.x << " " << intersection.y << endl;
    }
    return ys;
}

double min(double a, double b) {
    if (a < b) {
        return a;
    }
    return b;
}

double max(double a, double b) {
    if (a > b) {
        return a;
    }
    return b;
}


int main() {
    long long N;
    while(cin >> N) {
        

      cin >> p1.x >> p1.y;
      cin >> p2.x >> p2.y;
      cin >> p3.x >> p3.y;
      cin >> p4.x >> p4.y;

      vector<long long> num_squares;
      while(N) {
          long long squares = 0;
          for(long long i = -1000006; i <= 1000006; ++i) {
              vector<double> ys1 = quad_intersection(i);
              vector<double> ys2 = quad_intersection(i+1);
              if(ys1.size() == 0 || ys2.size() == 0) continue;

              double y1bottom = min(ys1[0], ys1[1]);
              double y1top = max(ys1[0], ys1[1]);

              double y2bottom = min(ys2[0], ys2[1]);
              double y2top = max(ys2[0], ys2[1]);

              if(i == 10) cout << y1bottom << " " << y1top << endl;
              if(i == 10) cout << y2bottom << " " << y2top << endl;


              double bottom, top;

              if (y2bottom >= y1bottom && y2bottom <= y1top) {
                  bottom = y2bottom;
                  top = min(y1top, y2top);
              } else if (y2top >= y1bottom && y2top <= y1top) {
                  top = y2top;
                  bottom = max(y1bottom, y2bottom);
              } else {
                  /* Ranges don't intersect. */
                  continue;
              }
              if(i == 0) cout << top << " " << bottom << endl;
              if (floor(top + 1e-8) - ceil(bottom - 1e-8) > 0) {
                  squares += floor(top + 1e-8) - ceil(bottom - 1e-8);
              }



              /*
              int y1bottom = ceil(min(ys1[0], ys1[1]) - 1e-8);
              int y1top = floor(max(ys1[0], ys1[1]) + 1e-8);
              int y2bottom = ceil(min(ys2[0], ys2[1]) - 1e-8);
              int y2top = floor(max(ys2[0], ys2[1]) + 1e-8);
              int range_bottom = max(y1bottom, y2bottom);
              int range_top = min(y1top, y2top);
              if(range_bottom <= range_top) {
                  cout << y1bottom << " " << y1top << " " << y2bottom << " " << y2top << endl;
                  cout << range_top << " " << range_bottom << endl;
                  cout << i << endl;
              )
              squares += max(range_top - range_bottom, 0);
              */
          }
          num_squares.push_back(squares);

          p1.x /= 2;
          p1.y /= 2;
          p2.x /= 2;
          p2.y /= 2;
          p3.x /= 2;
          p3.y /= 2;
          p4.x /= 2;
          p4.y /= 2;


          N /= 2;
      }

      /*for(int i = 0; i<num_squares.size(); ++i) {
          cout << num_squares[i] << endl;
      )*/
      long long prev = 0;
      for(long long i = num_squares.size()-1; i >= 0; --i) {
          cout << num_squares[i] - 4 * prev;
          if(i != 0) cout << " ";
          prev = num_squares[i];
      }
      cout << endl;
    }

}
