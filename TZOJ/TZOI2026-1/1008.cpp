#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define int long long
const int maxn = 2e5 + 5;
const int offset = 2e5;

using PII = pair< ll, ll >;

ll a[maxn];
ll dp[maxn << 1];
ll n, k;

map< ll, vector< PII > > rems;

bool cmp( int a, int b )
{
    return a * k < b * k;
}

void solve( )
{
    rems.clear();
    cin >> n >> k;
    //k = abs( k );
    a[0] = -1;
    for( int i = 1; i <= n; ++ i ) 
    {
        cin >> a[i];
        //rems[ a[i] % abs( k ) ].push_back( a[i] );
    }
    sort( a + 1, a + n + 1, cmp );

    for(int i = 1, j = 0, yu = 0; i <= n; ++ i){
        if(a[j] != a[i]){
            j = i;
            yu = a[i] % abs( k );
            rems[yu].push_back( { a[i], 1 } );
        } 
        else{
            rems[yu][rems[yu].size() - 1].second += 1;
        }
}
        int res = 0;
        for( auto &it : rems)
        {
            auto t = it.second;
            int len = t.size();
            for(int i = 0; i < len ; i++)
            {
                int cnt = t[i].second;
                if(cnt >= 2){
                    if(i + 1 < len){ //后面还有
                        int dis = (t[i + 1].first - t[i].first) / k;
                        if(dis <= cnt - 1){ //得添加
                            t[i + 1].second += cnt - dis;
                            res += dis * (2 * cnt - dis - 1) / 2;
                        }else{ //直接跳过
                            res += (cnt - 1) * cnt / 2;
                        }

                    }
                    else{
                        res += (cnt - 1) * cnt / 2;
                    }
                }
            }
        }
        cout << res << endl;
    }



signed main( )
{
    ios::sync_with_stdio( 0 ); cin.tie( 0 );
    int _t = 1; cin >> _t;
    while( _t -- ) solve( );
    return 0;
}