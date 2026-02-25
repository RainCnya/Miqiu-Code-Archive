#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using PII = pair<int, int>;

const int maxn = 2e5 + 50;

struct Kite {
    int a, b;
    bool operator < ( const Kite &other ) {
        if( a != other.a ) return a < other.a;
        return b > other.b;
    }
} kites[maxn];

int f[maxn];
int n;

int main( )
{
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    cin >> n;
    
    for( int i = 1; i <= n; ++ i )
    {
        cin >> kites[i].a >> kites[i].b;
    }

    sort( kites + 1, kites + n + 1 );

    vector<int> vec;
    for( int i = 1; i <= n; ++ i )
    {
        if( vec.empty( ) || kites[i].b > vec.back( ) )
        {
            vec.push_back( kites[i].b );
        }
        else
        {
            auto it = lower_bound( vec.begin( ), vec.end( ), kites[i].b );
            *it = kites[i].b;
        }
    }
    cout << vec.size( ) << endl;
    return 0;
}