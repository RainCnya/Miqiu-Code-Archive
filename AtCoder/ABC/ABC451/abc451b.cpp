#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int maxn = 2e5 + 5;

int n, m;
int a[maxn], b[maxn];
int cnt1[maxn], cnt2[maxn];

void solve( )
{
    cin >> n >> m;
    for( int i = 1; i <= n; ++ i ) 
    {
        cin >> a[i] >> b[i];
        cnt1[a[i]] ++;
        cnt2[b[i]] ++;
    }

    for( int i = 1; i <= m; ++ i )
    {
        cout << cnt2[i] - cnt1[i] << '\n';
    }

}

int main( )
{
    ios::sync_with_stdio( 0 ); cin.tie( 0 );
    solve( );
    return 0;
}