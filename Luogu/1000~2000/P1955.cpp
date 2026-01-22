#include<bits/stdc++.h>
using namespace std;

const int maxn = 1e5 + 50;

int fa[maxn << 1];
int n;

struct Node{
    int x, y, e;
};

vector<Node> a;

bool cmp( Node aa, Node bb ) {
    return aa.e > bb.e;
} 

int find( int x ) {
    return fa[x] == x ? x : fa[x] = find( fa[x] );
}
void merge( int x, int y ) {
    fa[ find(x) ] = find( y );
}

void solve( )
{
    cin >> n;

    a.clear( );
    a.resize( n );

    vector<int> tmp;
    for( int i = 0; i < n; ++ i ) {
        cin >> a[i].x >> a[i].y >> a[i].e;
        tmp.push_back( a[i].x );
        tmp.push_back( a[i].y ); 
    }

    sort( tmp.begin( ), tmp.end( ) );
    tmp.erase( unique( tmp.begin( ), tmp.end( ) ), tmp.end( ) );
    
    int sz = tmp.size( );
    for( int i = 0; i < sz; ++ i )  fa[i] = i;

    for( int i = 0; i < n; ++ i )
    {
        a[i].x = lower_bound( tmp.begin( ), tmp.end( ), a[i].x ) - tmp.begin( );
        a[i].y = lower_bound( tmp.begin( ), tmp.end( ), a[i].y ) - tmp.begin( );
    }

    sort( a.begin( ), a.end( ), cmp );

    bool ok = 1;
    for( int i = 0; i < n; ++ i )
    {
        auto& [u, v, opt] = a[i];
        if( opt == 1 ) {
            merge( u, v );
        } else {
            if( find( u ) == find( v ) ) {
                ok = 0;
                break;
            }
        }
    }
    if( ok ) cout << "YES" << '\n';
    else cout << "NO" << '\n';
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int t;  cin >> t;
    while( t -- )
    {
        solve( );
    }
    return 0;
}