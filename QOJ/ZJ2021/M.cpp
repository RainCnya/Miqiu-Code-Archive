#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using PII = pair<int, int>;

const int maxn = 1e5 + 50;
const double inf = 1e18;

int n;

int main( )
{
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    cin >> n;

    double ans = inf;

    for( int y = 1; y <= 20; ++ y )
    {
        double cur = 0;
        for( int x = 1; x <= 20; ++ x )
        {
            double score = y - x;
            if( x > y ) score += 10;
            else if( x < y ) score -= 10;
            cur += score;
        }
        double avg = cur / 20.0;
        ans = min( ans, avg );
    }

    ans = ( n - 1 ) * ans;

    cout << fixed << setprecision(4) << ans << '\n';

    return 0;
}

/*
cin >> n;
cout << 0.0000 << '\n;
*/