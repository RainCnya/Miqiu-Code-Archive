#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int maxn = 100 + 5;

bool used[maxn];
int x[maxn];
int n, m;

void solve( )
{
    cin >> n >> m;
    vector< int > ans;
    for( int i = 1; i <= n; ++ i )
    {
        int l; cin >> l;
        for( int j = 1; j <= l; ++ j ) cin >> x[j];

        int res = 0;
        for( int j = 1; j <= l; ++ j )
        {
            if( used[ x[j] ] == 0 )
            {
                used[ x[j] ] = 1;
                res = x[j];
                break;
            }
        }
        ans.push_back( res );
    }
    for( int x : ans ) cout << x << endl;
}

int main( )
{
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    solve( );
    return 0;
}