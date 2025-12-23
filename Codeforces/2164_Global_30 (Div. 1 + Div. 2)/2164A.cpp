#include<bits/stdc++.h>
using namespace std;

const int inf = 2e9;
const int maxn = 105;
int a[maxn];
int n;

int main()
{	
    int t;
    cin >> t;
    while( t -- )
    {
        cin >> n;
        int mn = inf;
        int mx = -inf;
        for( int i = 1; i <= n; ++ i )
        {
            cin >> a[i];
            mx = max( mx, a[i] );
            mn = min( mn, a[i] );
        }
        int t;
        cin >> t;
        if( mn <= t && t <= mx ) {
            cout << "YES" << "\n";
        } else {
            cout << "NO" << '\n';
        }
    }   
    return 0;
}



