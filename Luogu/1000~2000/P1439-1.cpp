#include<bits/stdc++.h>
using namespace std;

const int maxn = 1e5 + 5;

int n;
int a[maxn], b[maxn];
int mp[maxn], f[maxn];

int main()
{	
    cin >> n;
    for( int i = 1; i <= n; ++ i )
    {
        cin >> a[i];
        mp[ a[i] ] = i;
    }
    
    for( int j = 1; j <= n; ++ j )
    {
        cin >> b[j];
    }

    int len = 0;

    for( int i = 1; i <= n; ++ i )
    {
        int pos = lower_bound( f + 1, f + len + 1, mp[ b[i] ] ) - f;
        f[pos] = mp[ b[i] ];
        if( pos > len ) len = pos;
    }

    cout << len << '\n';
    return 0;
}