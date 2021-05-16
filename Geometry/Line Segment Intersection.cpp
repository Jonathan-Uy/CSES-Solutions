#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

struct Point {
    int x, y;
    void read(){ scanf("%d %d", &x, &y); }
    Point operator +(const Point& b) const { return Point{x+b.x, y+b.y}; }
    Point operator -(const Point& b) const { return Point{x-b.x, y-b.y}; }
    ll operator *(const Point& b) const { return (ll) x * b.y - (ll) y * b.x; }
    void operator +=(const Point& b) { x += b.x; y += b.y; }
    void operator -=(const Point &b) { x -= b.x; y -= b.y; }
    void operator *=(const int k) { x *= k; y *= k; }

    ll cross(const Point& b, const Point& c) const {
        return (b - *this) * (c - *this);
    }
};

int T;
Point P[4];

void lineintersect(Point P1, Point P2, Point P3, Point P4){
    // Parallel case
    if((P2-P1) * (P4-P3) == 0){
        // Collinear case, check bounding boxes
        if(P1.cross(P2, P3) == 0){
            for(int i = 0; i < 2; i++){
                if(max(P1.x, P2.x) < min(P3.x, P4.x) || max(P1.y, P2.y) < min(P3.y, P4.y)){
                    printf("NO\n");
                    return;
                }
                swap(P1, P3);
                swap(P2, P4);
            }
            printf("YES\n");
            return;
        }

        // Non-collinear parallel lines never intersect
        printf("NO\n");
        return;
    }

    // Non-parallel case
    for(int i = 0; i < 2; i++){
        ll s1 = P1.cross(P2, P3);
        ll s2 = P1.cross(P2, P4);
        if((s1 < 0 && s2 < 0) || (s1 > 0 && s2 > 0)){
            printf("NO\n");
            return;
        }
        swap(P1, P3);
        swap(P2, P4);
    }

    printf("YES\n");
}

int main(){
    scanf("%d", &T);
    for(int t = 0; t < T; t++){
        for(int i = 0; i < 4; i++)
            P[i].read();
        lineintersect(P[0], P[1], P[2], P[3]);
    }
}
