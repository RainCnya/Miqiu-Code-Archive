#include <bits/stdc++.h>
using namespace std;

const int maxn = 2e5 + 50;

long long a[maxn];
long long k, x, cnt;
int n;

void print( long long l, long long r )
{
    for( long long p = l; p <= r && cnt < k; ++ p )
    {
        cout << p << " ";
        cnt ++;
    }
}

bool check( long long mid )
{
    long long tcnt = 0;
    
    if( a[1] >= mid ) tcnt += a[1] - mid + 1;
    
    for( int i = 1; i < n; ++ i )
    {
        long long diff = a[i + 1] - a[i];
        if( diff >= mid * 2 )
            tcnt += diff - 2 * mid + 1 ;
    }

    if( x - a[n] >= mid ) tcnt += x - a[n] - mid + 1 ;

    return tcnt >= k;
}

void solve( ) 
{
    cnt = 0;
    cin >> n >> k >> x;
    for( int i = 1; i <= n; ++ i ) 
    {
        cin >> a[i];
    }
    sort( a + 1, a + n + 1 );

    long long l = 0, r = x + 1;
    long long ans = 0;

    while( l <= r )  
    {
        long long mid = ( l + r ) >> 1;
        if( check( mid ) ) ans = mid, l = mid + 1;
        else r = mid - 1;
    }

    if( ans == 0 )
    {
        for( int i = 0; i < k; ++ i )
            cout << i << " ";
        cout << '\n';
        return;
    }

    if( a[1] >= ans ) print( 0, a[1] - ans );
    
    for( int i = 1; i < n; ++ i )
    {
        long long st = a[i] + ans;
        long long ed = a[i+1] - ans;
        if( st <= ed ) print( st, ed );
    }

    if( x - a[n] >= ans ) print( a[n] + ans, x );
    cout << '\n';
}

int main( ) 
{
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    int t;
    cin >> t;
    while( t -- ) 
    {
        solve( );
    }
    return 0;
}