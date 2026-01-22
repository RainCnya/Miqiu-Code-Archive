#include<bits/stdc++.h>
using namespace std;

const int maxn = 1e5 + 50;

struct node{
    int st, val;
};

vector<node> ed[maxn]; 
vector< pair<int, int> > segs;
int dp[maxn];
int n;

int main()
{	
    cin >> n;
    for( int i = 1; i <= n; ++ i )
    {
        int a, b;
        cin >> a >> b;
        if( a + b < n ) 
        {
            segs.push_back({ a, b });
        }
    }

    sort( segs.begin( ), segs.end( ) );

    int i = 0;
    while( i < segs.size( ) )
    {
        auto& [a, b] = segs[i];  
        int cnt = 0;
        int j = i;
        
        while( j < segs.size( ) && segs[j].first == a && segs[j].second == b )
        {
            cnt ++;
            j ++;
        }
        
        int l = a + 1;
        int r = n - b;
        int s = n - a - b;
        int v = min( cnt, s );
        ed[r].push_back({ l, v });
        i = j;
    }

    for( int i = 1; i <= n; ++ i )
    {
        dp[i] = dp[i-1];
        for( auto& [st, val] : ed[i] )
        {
            dp[i] = max( dp[i], dp[st - 1] + val );
        }
    }

    cout << n - dp[n] << '\n';
    return 0;
}