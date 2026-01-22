#include<bits/stdc++.h>
using namespace std;

const int maxn = 20;

struct node{
    int fmax;
    int smax;
}a[1<<maxn];

int n;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    cin >> n;
    for( int i = 0; i < (1 << n); ++ i )
    {
        int x;  cin >> x;
        a[i].fmax = x;
    }

    for( int j = 0; j < n; ++ j )
    {
        for( int i = 0; i < (1 << n); ++ i )
        {
            if( ( i >> j ) & 1 )
            {
                int x = i ^ ( 1 << j );
                node tmp;
                if( a[i].fmax > a[x].fmax )
                {
                    tmp.fmax = a[i].fmax;
                    tmp.smax = max( a[i].smax, a[x].fmax);
                }
                else
                {
                    tmp.fmax = a[x].fmax;
                    tmp.smax = max( a[x].smax, a[i].fmax);
                }
                a[i] = tmp;
            }
        }
    }

    int ans = 0;
    for( int i = 1; i < (1 << n); ++ i )
    {
        ans = max( ans, a[i].fmax + a[i].smax );
        cout << ans << '\n';
    }
    cout << endl;
    return 0;
}