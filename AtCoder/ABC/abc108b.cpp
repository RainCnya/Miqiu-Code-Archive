#include<bits/stdc++.h>

int main() {
    using namespace std;
    long long x1, y1, x2, y2;   
    cin >> x1 >> y1 >> x2 >> y2;
    long long dx = x2 - x1;
    long long dy = y2 - y1;
    long long x3 = x2 - dy;
    long long y3 = y2 + dx;
    long long x4 = x1 - dy;
    long long y4 = y1 + dx;
    cout << x3 << ' ' << y3 << ' ';
    cout << x4 << ' ' << y4 << '\n';
    return 0;
}