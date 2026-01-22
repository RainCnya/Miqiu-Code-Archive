#include<bits/stdc++.h>
using namespace std;

int main( )
{
    int t;
    cin >> t;
    while( t -- )
    {
        int n;
        cin >> n;
        vector<int> a(n);
        for( int i = 0; i < n; i ++ )
            cin >> a[i];
        sort( a.begin(), a.end() );
        int ans = 0xffffffff;
        for( int i = 0; i < n - 1; i += 2 )
        {
            int diff = a[i+1] - a[i];
            if( diff > ans )
                ans = diff;
        }
        cout << ans << endl;
    }
    return 0;
}