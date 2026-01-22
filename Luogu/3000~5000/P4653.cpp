#include<bits/stdc++.h>
using namespace std;

const int maxn = 1e5 + 50;

double a[maxn], b[maxn];
double suma[maxn], sumb[maxn];
int n;

bool cmp( double a, double b ) {
    return a > b;
}

int main() {
    cin >> n;
    for( int i = 1; i <= n; ++ i )
    {
        cin >> a[i] >> b[i];
    }    
    sort( a + 1, a + n + 1, cmp );
    sort( b + 1, b + n + 1, cmp );
    for( int i = 1; i <= n; ++ i )
    {
        suma[i] = suma[i-1] + a[i];
        sumb[i] = sumb[i-1] + b[i];
    }
    
    double ans = 0;
    int i = 1, j = 1;
    while( i <= n && j <= n )
    {
        if( suma[i] > sumb[j] )
        {
            ans = max( ans, sumb[j] - i - j );
            j ++;
        }
        else
        {
            ans = max( ans, suma[i] - i - j );
            i ++;
        }
    }

    printf("%.4f\n", ans);
    // cout << ans << '\n';
    return 0;
}