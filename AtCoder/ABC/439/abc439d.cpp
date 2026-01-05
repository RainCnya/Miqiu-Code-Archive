#include<bits/stdc++.h>
using namespace std;
using ll = long long;

const int maxn = 3e5 + 50;

int a[maxn];
int n;

int main( )
{
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    map< int, ll > cntl, cntr;

    cin >> n;
    for( int i = 1; i <= n; ++ i )
    {
        cin >> a[i];
        cntr[ a[i] ] ++;  
    }

    ll ans = 0;
    for( int jj = 1; jj <= n; ++ jj )
    {
        cntr[ a[jj] ] --;

        if( a[jj] % 5 == 0 )
        {
            int cur = a[jj] / 5;
            ll ii = cur * 7ll;
            ll kk = cur * 3ll;

            if( cntl.count( ii ) && cntl.count( kk ) )
                ans += cntl[ii] * cntl[kk];
            
            if( cntr.count( ii ) && cntr.count( kk ) )
                ans += cntr[ii] * cntr[kk];
        }

        cntl[ a[jj] ] ++;
    }
    cout << ans << '\n';
    
    return 0;
}