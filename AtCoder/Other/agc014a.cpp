#include<bits/stdc++.h>
using namespace std;

int main() {
    long long a, b, c;
    cin >> a >> b >> c;
    int cnt = 0;
    while( 1 ) {
        if( a & 1 || b & 1 || c & 1 ) {
            break;
        } else if( a == b && b == c ) {
            cnt = -1;
            break;
        }
        long long aa = a, bb = b, cc = c;
        a = (bb + cc) / 2;
        b = (aa + cc) / 2;
        c = (aa + bb) / 2;
        cnt ++;
    }
    cout << cnt << '\n';
    return 0;
}