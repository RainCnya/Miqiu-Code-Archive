#include<bits/stdc++.h>
using namespace std;

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
        for( int i = 1; i <= n; ++ i )
        {
            cin >> a[i];
        }

        sort( a + 1, a + n + 1 );
        bool ok = 1;
        for( int i = 2; i < n; i += 2 )
        {
            if( a[i] != a[i+1] ) {
                ok = 0;
                break;
            }
        }

        if( ok ) {
            cout << "YES" << '\n';
        } else {
            cout << "NO" << '\n';
        }
    }
    return 0;
}