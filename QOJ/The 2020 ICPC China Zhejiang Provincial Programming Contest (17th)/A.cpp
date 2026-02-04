#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using PII = pair<int, int>;

const int maxn = 2e5 + 5;

ll sum[10005][13][32];
int months[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

bool check( int y, int m, int d )
{
    string s = "";
    s += to_string( y );
    if( m < 10 ) s += '0';
    s += to_string( m );
    if( d < 10 ) s += '0';
    s += to_string( d );
    return s.find( "202" ) != string::npos;
}

void init( )
{
    int total = 0;
    for( int y = 2000; y <= 9999; ++ y )
    {
        if( y % 400 == 0 || (y % 100 != 0 && y % 4 == 0) ) months[2] = 29; 
        else months[2] = 28;
        for( int m = 1; m <= 12; ++ m )
        {

            for( int d = 1; d <= months[m]; ++ d )
            {
                if( check( y, m, d ) ) total ++;
                sum[y][m][d] = total;
            }
        }
    }
}

void solve( )
{
    int y1, y2, m1, m2, d1, d2;
    cin >> y1 >> m1 >> d1 >> y2 >> m2 >> d2;
    int ans = sum[y2][m2][d2] - sum[y1][m1][d1];
    if( check( y1, m1, d1 ) ) ans ++;
    cout << ans << '\n';
}

int main( )
{
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    init( );
    int _t = 1;
    cin >> _t;
    while( _t -- )
    {
        solve( );
    }
    return 0;
}