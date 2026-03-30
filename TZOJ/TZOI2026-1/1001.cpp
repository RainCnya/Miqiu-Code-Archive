#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int maxn = 2e5 + 5;

int n;

void solve( )
{
    cin >> n;
    ll sum = 0;
    double avg = 0;
    for( int i = 1; i <= n; ++ i )
    {
        char c; int x;
        cin >> c >> x;
        if( c == 'A' ) sum += 4;
        if( c == 'B' ) sum += 3;
        if( c == 'C' ) sum += 2;
        if( c == 'D' ) sum += 1;

        if( x == 1 ) {
            if( c == 'A' || c == 'B' || c == 'C' ) avg += 0.05;
        } else if( x == 2 ) {
            if( c == 'A' || c == 'B' || c == 'C' ) avg += 0.025;
        }

    }
    avg += 1.0 * sum / n;
    cout << fixed << setprecision( 6 ) << avg << '\n';
}

int main( )
{
    ios::sync_with_stdio( 0 ); cin.tie( 0 );
    solve( );
    return 0;
}