#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int maxn = 5e4 + 50;

map< string, int > id;
string names[maxn];
int fa[maxn];
string s;
int cnt;

int get_id( string name )
{
    if( id.find( name ) == id.end( ) ) 
    {
        id[name] = ++ cnt;
        names[cnt] = name;
        fa[cnt] = cnt;
    }
    return id[name];
}

int find( int x ) 
{
    if( fa[x] == x ) return fa[x];
    return fa[x] = find( fa[x] );
}

void solve( )
{
    char opt;
    int cur_father = 0;
    while( cin >> opt )
    {
        if( opt == '$' ) break;
        cin >> s;

        int idx = get_id( s );

        if( opt == '#' ) cur_father = idx;
        else if( opt == '+' ) fa[idx] = cur_father;
        else 
        {
            int root = find( idx );
            cout << s << " " << names[root] << '\n';
        }
    }
}

int main( )
{
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    solve( );
    return 0;
}