#include<bits/stdc++.h>
using namespace std;

struct Point{
    double x, y;
    Point(double x, double y) : x(x), y(y){}
};

struct Rectangle{
    Point BL, TR;
    Rectangle(Point bl, Point tr) : BL(bl), TR(tr){}
};

Rectangle intersection(Rectangle a, Rectangle b){
	int x1 = max(a.BL.x, b.BL.x);
    int x2 = min(a.TR.x, b.TR.x);
    int y1 = max(a.BL.y, b.BL.y);
    int y2 = min(a.TR.y, b.TR.y);

    if(x2 > x1 && y2 > y1){
        return Rectangle(Point(x1, y1), Point(x2, y2));
    }

    return Rectangle(Point(0, 0), Point(0, 0));
}

long long int area(Rectangle rec){
    return 1ll * (rec.TR.x-rec.BL.x) * (rec.TR.y-rec.BL.y);
}

void solve(){
    int a, b, c, d; cin >> a >> b >> c >> d;
    Rectangle white(Point(a, b), Point(c, d));

    cin >> a >> b >> c >> d;
    Rectangle black1(Point(a, b), Point(c, d));

    cin >> a >> b >> c >> d;
    Rectangle black2(Point(a, b), Point(c, d));

    auto int1 = intersection(white, black1);
    auto int2 = intersection(white, black2);
    auto int3 = intersection(int1, int2);

    if(area(int1) + area(int2) - area(int3) >= area(white)){
        cout << "NO" << endl;
    } 
    else{
        cout << "YES" << endl;
    }
}

int main(){
    int n = 1; //cin >> n;
    for(int i = 0; i < n; i++){
        solve();
    }
}