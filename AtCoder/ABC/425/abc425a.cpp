#include<bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    long long ans = 0;
    int opt = -1;
    for( int i = 1; i <= n; ++ i ) {
        ans += opt * pow( i, 3 );
        if( opt == -1 ) opt = 1;
        else opt = -1; 
    }
    cout << ans << '\n';
    return 0;
}