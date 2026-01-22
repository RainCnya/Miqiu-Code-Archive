#include<bits/stdc++.h>
using namespace std;

const int maxn = 1e5 + 50;

int n, m;
int a[maxn];
int ans[maxn];

int main()
{	
    cin >> n >> m;
    for( int i = 1; i <= n; ++ i )
    {
        cin >> a[i];
    }
    
    deque<int> q;
    int cnt = 0;
    for( int i = 1; i <= n; ++ i )
    {
        while( !q.empty( ) && a[ q.back( ) ] > a[i] )
            q.pop_back( );
        
        q.push_back( i );
        
        while( !q.empty( ) && q.front( ) <= i - m )
            q.pop_front( );
        
        if( i >= m ) ans[++cnt] = a[ q.front( ) ];
    }

    for( int i = 1; i <= cnt; ++ i )
    {
        cout << ans[i] << '\n';
    }
    return 0;
}