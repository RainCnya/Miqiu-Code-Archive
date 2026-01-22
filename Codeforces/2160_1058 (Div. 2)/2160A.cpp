#include<bits/stdc++.h>
using namespace std;

int main( )
{
    int t;  cin >> t;
    while( t -- )
    {
        int n;  cin >> n;
        vector<int> cnt(n+1, 0);
        for( int i = 0; i < n; ++ i )
        {
            int x;  cin >> x;
            cnt[x] ++;
        }
        int ans= 0;
        while( ans <= 100 && cnt[ans] > 0 )
            ans ++;
        cout << ans << "\n";
    }
    return 0;
}