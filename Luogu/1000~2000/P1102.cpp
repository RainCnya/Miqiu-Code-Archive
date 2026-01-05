#include<bits/stdc++.h>
using namespace std;

const int maxn = 2e5 + 50;

int a[maxn];
int n, c;

int main() {
    cin >> n >> c;
    
    for( int i = 1; i <= n; ++ i ) {
        cin >> a[i];
    }
    sort( a + 1, a + n + 1 );

    int l = 1, r1 = 1, r2 = 1;
    long long ans = 0;

    for( l = 1; l <= n; ++ l )
    {
        while( r1 <= n && a[r1] - a[l] <= c ) r1 ++;
        while( r2 <= n && a[r2] - a[l] < c ) r2 ++;
        if( a[r2] - a[l] == c && a[r1 - 1] - a[l] == c && r1 - 1 >= l )
            ans += r1 - r2;
    }

    cout << ans << '\n';
    return 0;
}