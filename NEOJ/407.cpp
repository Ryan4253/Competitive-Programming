/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include<bits/stdc++.h>
using namespace std;

#define eps 1e-6
#define ll long long
#define endl '\n'
#define pb push_back
#define pii pair<int, int>
#define mp make_pair
#define F first;
#define S second;

typedef pair<ll int, ll int> Point;

Point operator+(Point a, Point b){
    return {a.first + b.first, a.second + b.second};
}

Point operator-(Point a, Point b){
    return {a.first - b.first, a.second - b.second};

}   

ll int dot(Point a, Point b){
    return a.first * b.first + a.second * b.second;
}

ll int cross(Point a, Point b){
    return a.first * b.second - a.second * b.first;
}

bool isParallel(Point a, Point b){
    return cross(a, b) == 0;    
}

// a is point, bc is line
bool isWithin(Point a, Point b, Point c){
    if(isParallel(b-a, c-a)){
        if(dot(b-a, c-a) <= 0){
            return true;
        }
        else{
            return false;
        }
    }
    else{
        return false;
    }
}

int sgn(ll int val){
    if(val == 0){
        return 0;
    }
    else if(val < 0){
        return -1;
    }
    else{
        return 1;
    }
}

void solve(){
    Point a[4];
    for(int i = 0; i < 4; i++){
        int x, y; cin >> x >> y;
        a[i] = make_pair(x, y);
    }   
    
    if(isParallel(a[0]-a[1], a[2]-a[3])){
        if(isWithin(a[0], a[2], a[3]) || isWithin(a[1], a[2], a[3]) || isWithin(a[2], a[0], a[1]) || isWithin(a[3], a[0], a[1])){
            cout << "Yes" << endl;
        }
        else{
            cout << "No" << endl;
        }
    }
    else{
        if( sgn(cross(a[2]-a[0], a[3]-a[0])) * sgn(cross(a[2]-a[1], a[3]-a[1])) <= 0 &&  sgn(cross(a[0]-a[2], a[1]-a[2]) * sgn(cross(a[0]-a[3], a[1]-a[3])) <= 0)){
            cout << "Yes" << endl;
        }
        else{
            cout << "No" << endl;
        }
    }
}

int main(){
  ios::sync_with_stdio(0); cin.tie(0);
  int n = 1; cin >> n;
  while(n--){
    solve();
  }
}