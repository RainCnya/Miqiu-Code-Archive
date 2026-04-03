#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define endl '\n'

const int maxn = 15e5 + 5;
const int maxm = 1e4 + 5;
const int inf = 2e9;

struct Point { 
    int x, y;
    bool operator < ( const Point &oth ) const { 
        if( y != oth.y ) return y < oth.y;
        return x < oth.x;
    }
};

vector< Point > ptr[31];
struct Query { int x1, y1, x2, y2, id; } qs[maxm];

struct Event {
    int x, y, type;
    bool operator < ( const Event &oth ) const { 
        if( x != oth.x ) return x < oth.x; 
        return abs( type ) < abs( oth.type );
    }
};

ll ans[maxm];
int Bit[maxn + maxm * 3], sz;

void upd( int i, ll val ) {
    for( ; i <= sz; i += i & - i ) Bit[i] += val;
}

int qry( int i ) {
    int res = 0;
    for( ; i > 0; i -= i & - i ) res += Bit[i];
    return res;
}

int sqrt2[31][31];
int n, m;

void solve( )
{
    cin >> n >> m;

    for( int i = 0; i <= 30; ++ i ) ptr[i].clear( );
    for( int i = 0; i <= m; ++ i ) ans[i] = 0;

    for( int i = 1; i <= n; ++ i )
    {
        int p, q, r; cin >> p >> q >> r;
        ptr[r].push_back({ p, q });
    }

    for( int i = 1; i <= m; ++ i )
    {
        cin >> qs[i].x1 >> qs[i].y1 >> qs[i].x2 >> qs[i].y2;
        qs[i].id = i;
    }

    for( int r = 1; r <= 30; ++ r )
    {
        for( int dy = 0; dy <= r; ++ dy )
        {
            sqrt2[r][dy] = (int)( sqrt( 1.0 * r * r - 1.0 * dy * dy ) + 1e-9 );
        }
    }

    for( int r = 1; r <= 30; ++ r )
    {
        if( ptr[r].empty( ) ) continue;
        const vector< Point > &pts = ptr[r];
        sort( ptr[r].begin( ), ptr[r].end( ) );
        
        for( int i = 1; i <= m; ++ i )
        {
            for( int dy = 1; dy <= r; ++ dy )
            {
                int dx = sqrt2[r][dy];
                int tx1 = qs[i].x1 - dx, tx2 = qs[i].x2 + dx;
                int tys[2] = { qs[i].y1 - dy, qs[i].y2 + dy };
                for( int ty : tys )
                {
                    auto low = lower_bound( pts.begin( ), pts.end( ), Point{ -inf, ty } );
                    auto upp = upper_bound( pts.begin( ), pts.end( ), Point{ inf, ty } );
                    if( low == upp ) continue;

                    auto it1 = lower_bound( low, upp, Point{ tx1, ty } );
                    auto it2 = upper_bound( low, upp, Point{ tx2, ty } );
                    ans[qs[i].id] += distance( it1, it2 );
                }
            }
        }

        vector< Event > es;
        vector< int > vy;

        for( int j = 0; j < pts.size( ); ++ j )
        {
            es.push_back({ pts[j].x, pts[j].y, 0 });
            vy.push_back( pts[j].y );
        }

        for( int i = 1; i <= m; ++ i )
        {
            vy.push_back( qs[i].y1 );
            vy.push_back( qs[i].y2 );
            es.push_back({ qs[i].x1 - r - 1, 0, -i });
            es.push_back({ qs[i].x2 + r, 0, i });
        }

        sort( vy.begin( ), vy.end( ) );
        vy.erase( unique( vy.begin( ), vy.end( ) ), vy.end( ) );
        sz = vy.size( );
        fill( Bit, Bit + sz + 2, 0 );

        sort( es.begin( ), es.end( ) );

        for( int j = 0; j < es.size( ); ++ j )
        {
            if( es[j].type == 0 )
            {
                int pos = lower_bound( vy.begin( ), vy.end( ), es[j].y ) - vy.begin( ) + 1;
                upd( pos, 1 );
            }
            else 
            {
                int qidx = abs( es[j].type );
                int L = lower_bound( vy.begin( ), vy.end( ), qs[qidx].y1 ) - vy.begin( ) + 1;
                int R = lower_bound( vy.begin( ), vy.end( ), qs[qidx].y2 ) - vy.begin( ) + 1;
                
                int res = qry( R ) - qry( L - 1 );
                if( es[j].type > 0 ) ans[qidx] += res;
                else ans[qidx] -= res;
            }
        }
    }

    for( int i = 1; i <= m; ++ i ) cout << ans[i] << '\n';
}

int main( )
{
    ios::sync_with_stdio( 0 ); cin.tie( 0 );
    int _t = 1; cin >> _t;
    while( _t -- ) solve( );
    return 0;
}