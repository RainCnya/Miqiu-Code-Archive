#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using PII = pair<int, int>;

const int maxn = 5e5 + 50;

int a[maxn];
int tmp[maxn];
int n;
ll ans;

void merge_sort( int l, int r )
{
    if( l >= r ) return ;
    int mid = ( l + r ) >> 1;
    merge_sort( l, mid );
    merge_sort( mid+1, r );

    int k = 0, i = l, j = mid + 1;
    while( i <= mid && j <= r )
    {
        if( a[i] <= a[j] ) {
            tmp[k ++] = a[i ++];
        }
        else {
            tmp[k ++] = a[j ++];
            ans += mid - i + 1;
        }
    }
    while( i <= mid ) tmp[k ++] = a[i ++];
    while( j <= r ) tmp[k ++] = a[j ++];
    for( int i = l, k = 0; i <= r; ++ i, ++ k )
    {
        a[i] = tmp[k];
    }
}

int main( )
{
    cin >> n;
    
    for( int i = 1; i <= n; ++ i )
    {
        cin >> a[i];
    }
    merge_sort( 1, n );
    cout << ans << '\n';
    return 0;
}