#include<bits/stdc++.h>
using namespace std;

const int maxn = 2e6 + 50;

int n, m;
int a[maxn];
int ans[maxn];

int main( )
{	
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin >> n >> m;
    for( int i = 1; i <= n; ++ i )
        cin >> a[i];
    
    deque<int> q;
    ans[1] = 0;
    int cnt = 1;
    for( int i = 1; i < n; ++ i )
    {
        while( !q.empty( ) && a[ q.back( ) ] >= a[i] )
            q.pop_back( );
        
        q.push_back( i );
        
        while( !q.empty( ) && q.front( ) <= i - m )
            q.pop_front( );
        
        ans[ ++ cnt ] = a[ q.front( ) ];

    }

    for( int i = 1; i <= cnt; ++ i )
    {
        cout << ans[i] << '\n';
    }
    return 0;
}