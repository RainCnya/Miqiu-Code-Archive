#include<bits/stdc++.h>
using namespace std;

const int maxn = 2e5 + 50;
const int maxm = 50 + 5;

int a[maxn];
int b[maxn];
int nxt[maxn];
int n, k, p;
vector<int> col[maxm];


int main() {
    cin >> n >> k >> p;
    for( int i = 1; i <= n; ++ i )
        cin >> a[i] >> b[i];

    nxt[n + 1] = n + 1;
    for( int i = n; i >= 1; -- i )
    {
        if( b[i] <= p ) nxt[i] = i;
        else nxt[i] = nxt[i + 1];
    }

    for( int i = 1; i <= n; ++ i ) 
        col[a[i]].push_back( i );

    long long ans = 0;
    for( int i = 0; i < k; ++ i )
    {
        if( col[i].size( ) < 2 ) continue;
        int m = col[i].size( );
        int r = 0;
        for( int l = 0; l < m; ++ l )
        {
            int idxL = col[i][l];
            int idxr = nxt[idxL];

            if( r <= l ) r = l + 1;

            while( r < m && col[i][r] < idxr )
                r ++;
            
            if( r < m ) ans += m - r;
        }
    }
    cout << ans << '\n';

    return 0;
}