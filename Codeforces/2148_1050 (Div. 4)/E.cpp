#include<bits/stdc++.h>
using namespace std;

int main( )
{
    int t;
    cin >> t;
    while( t -- )
    {
        int n, k;
        cin >> n >> k;
        vector<int> a(n);
        map<int, int> vis;
        for( int i = 0; i < n; ++ i )
        {
            cin >> a[i];
            vis[ a[i] ] ++;
        }

        bool check = 1;
        for( int i = 1; i <= n; ++ i )
        {
            if( vis[ i ] % k != 0 )
            {
                check = 0;
                break;
            }
        }
        if( check == 0 )
        {
            cout << 0 << endl;
            continue;
        }

        int l = 0;
        long long ans = 0;
        vector<int> cnt(n+1);
        for( int r = 0; r < n; ++ r )
        {
            cnt[ a[r] ] ++;
            while( cnt[ a[r] ] > vis[ a[r] ] / k )
            {
                cnt[ a[l] ] --;
                l ++;
            }
            ans += r - l + 1;
        }
        cout << ans << endl;
    }
    return 0;
}