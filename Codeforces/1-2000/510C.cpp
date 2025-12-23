#include<bits/stdc++.h>
using namespace std;

using PII = pair<int, int>;

const int N = 100 + 5;
const int M = 26;

int n;
vector<int> adj[M];
int ind[M];
vector<int> result;
bool edges[M][M];

bool kahn( )
{
    queue<int> q;
    for( int i = 0; i < M; ++ i )
    {
        if( ind[i] == 0 )
            q.push(i);
    }
    while( !q.empty( ) )
    {
        int u = q.front( ); q.pop( );
        result.push_back(u);
        for( int v : adj[u] )
        {
            ind[v] --;
            if( ind[v] == 0 )
                q.push(v);
        }
    }
    return result.size( ) == M;
}

int main( )
{
    cin >> n;
    string s[N];
    for( int i = 0; i < n; ++ i )
    {
        cin >> s[i];
    }
    for( int i = 0; i < n - 1; ++ i )
    {
        string s1 = s[i], s2 = s[i+1];
        int len1 = s1.length( );
        int len2 = s2.length( );
        bool flag = false;
        for( int j = 0; j < min(len1, len2); ++ j )
        {
            if( s1[j] != s2[j] )
            {
                int u = s1[j] - 'a', v = s2[j] - 'a';
                if( !edges[u][v] )
                {
                    edges[u][v] = true;
                    adj[u].push_back(v);
                    ind[v] ++;
                }
                flag = true;
                break;
            }
        }
        if( !flag && len1 > len2 )
        {
            cout << "Impossible" << endl;
            return 0;
        }
    }
    if( kahn( ) )
    {
        for( int res : result )
            cout << (char)(res + 'a');
    }
    else
        cout << "Impossible" << endl;
    return 0;
}
