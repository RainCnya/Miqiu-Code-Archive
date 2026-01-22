#include<bits/stdc++.h>
using namespace std;

int main() {
    int a, b;
    cin >> a >> b;

    int res = 0, cnt = 0;
    for( int i = 1; res < b; ++ i ) {
        if( i == 1 ) res = a;
        else res += a-1;
        cnt ++;
    }
    if( b == 1 ) cnt = 0;
    cout << cnt << '\n';
    return 0;
}