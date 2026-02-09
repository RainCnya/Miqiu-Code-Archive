#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int maxn = 1e5 + 50;

int n;

void solve( )
{
    cin >> n;
    double speed = 25.0 / ( n / 3600.0 );
    cout << fixed << setprecision( 1 ) << speed << '\n';
    if( speed < 100.0 ) cout << "normal" << '\n';
    else if( speed < 120.0 ) cout << "Exceeding the specified speed and less than 20%" << '\n';
    else if( speed < 150.0 ) cout << "Exceeding the specified speed by more than 20% and less than 50%" << '\n';
    else if( speed < 170.0 ) cout << "Exceeding the specified speed by more than 50% and less than 70%" << '\n';
    else cout << "Exceeding the specified speed by more than 70%" << '\n';
}

int main( )
{
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    solve( );
    return 0;
}