#include<bits/stdc++.h>
using namespace std;

const int maxn = 5e5 + 50;

int ans = -1e9;
int n, m;
int sum[maxn];

int main()
{	
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> n >> m;
    
    for( int i = 1; i <= n; ++ i )
    {
        int x;
        cin >> x;
        sum[i] = sum[i-1] + x;
    }

    deque<int> q;
    q.push_back( 0 );

    for( int i = 1; i <= n; ++ i )
    {
        while( !q.empty( ) && q.front() < i - m )
            q.pop_front( );   
        ans = max( ans, sum[i] - sum[q.front( )] );
        while( !q.empty( ) && sum[q.back( )] >= sum[i] )
            q.pop_back( );
        q.push_back( i );
        
    }

    cout << ans << '\n';
    return 0;
}