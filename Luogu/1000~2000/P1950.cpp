#include<bits/stdc++.h>
using namespace std;

const int maxn = 1000 + 50;

char mat[maxn][maxn];
int h[maxn];
int n, m;

int main()
{	
    cin >> n >> m;
    long long ans = 0;
    for( int i = 1; i <= n; ++ i )
    {
        for( int j = 1; j <= m; ++ j )
        {
            char tmp;
            cin >> tmp;
            if( tmp == '.' ) h[j] ++;
            else h[j] = 0;
        }
        for( int j = 1; j <= m; ++ j )
        {
            int cur = h[j];
            for( int k = j; k <= m; ++ k )
            {
                if( !h[k] ) break;
                cur = min( cur, h[k] );
                ans += cur;    
            }
        }
    }
    
    cout << ans << '\n';
    return 0;
}