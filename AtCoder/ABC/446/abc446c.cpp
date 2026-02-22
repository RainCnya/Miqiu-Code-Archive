#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using PII = pair<int, int>;

const int maxn = 2e5 + 5;

struct State { int day, cnt; };

int a[maxn], b[maxn];
int n, d;

void solve( )
{
    cin >> n >> d;

    for( int i = 1; i <= n; ++ i ) cin >> a[i];
    for( int i = 1; i <= n; ++ i ) cin >> b[i];

    deque< State > q;

    for( int i = 1; i <= n; ++ i )
    {
        q.push_back({ i, a[i] });

        int rem = b[i];
        while( !q.empty( ) && rem > 0 )
        {
            if( q.front( ).cnt <= rem )
            {
                rem -= q.front( ).cnt;
                q.pop_front( );
            }
            else
            {
                q.front( ).cnt -= rem;
                rem = 0;
            }
        }

        int lim = i - d + 1;
        while( !q.empty( ) && q.front( ).day < lim ) q.pop_front( );
    }

    ll sum = 0;
    for( auto &x : q ) sum += x.cnt;
    cout << sum << '\n';
}

int main( )
{
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int _t = 1;
    cin >> _t;
    while( _t -- ) solve( );
    return 0;
}