#include<bits/stdc++.h>
using namespace std;

const int maxn = 2e6 + 50;
int n, k;
int a[maxn];
int ans[maxn];

int main()
{	
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin >> n >> k;
    for( int i = 1; i <= n; ++ i )
        cin >> a[i];

    deque<int> q;
    int cnt = 0;
    for( int i = 1; i <= n; ++ i )
    {
        while( !q.empty( ) && a[ q.back( ) ] <= a[i] )
            q.pop_back( );
        q.push_back( i );
        while( !q.empty( ) && q.front( ) <= i - k )
            q.pop_front( );
        if( i >= k )
            ans[++cnt] = a[ q.front( ) ];
    }
    
    for( int i = 1; i <= cnt; ++ i )
    {
        cout << ans[i] << '\n';
    }
    return 0;
}