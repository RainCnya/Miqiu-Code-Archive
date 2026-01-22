#include<bits/stdc++.h>
using namespace std;

const int maxn = 1e6 + 50;
const double inf = 1e9;

int n, s, t;
double sum[maxn];
double b[maxn];
int a[maxn];

bool check( double mid )
{
    sum[0] = 0;
    for( int i = 1; i <= n; ++ i )
        sum[i] = sum[i - 1] + (a[i] - mid);
    
    deque<int> q;
    for( int i = s; i <= n; ++ i )
    {
        while( !q.empty( ) && sum[ q.back( ) ] >= sum[i - s] )
            q.pop_back( );
        
        q.push_back( i - s );

        while( !q.empty( ) && q.front( ) < i - t )
            q.pop_front( );
        
        if( !q.empty( ) && sum[i] - sum[ q.front( ) ] >= 0 )
            return 1;
    }
    return 0;
}

int main()
{	
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> n >> s >> t;

    double l = inf, r = -inf;
    for( int i = 1; i <= n; ++ i )
    {
        cin >> a[i];
        double x = double( a[i] );
        l = min( l, x );
        r = max( r, x );
    }

    double ans = 0;
    for( int k = 1; k <= 100; ++ k )
    {
        double mid = ( r + l ) / 2;
        if( check( mid ) )
            ans = l = mid;
        else
            r = mid;
    }

    cout << fixed << setprecision(3) << ans << '\n';
    return 0;
}