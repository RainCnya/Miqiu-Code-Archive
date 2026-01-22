#include<bits/stdc++.h>
using namespace std;

int main( ) {
    int t;
    scanf("%d", &t);
    while( t -- ) {
        int n;
        scanf("%d", &n);
        int ans = 0;
        for( int i = 1; i <= n; ++ i ) {
            int x;
            scanf("%d", &x);
            ans = max( ans, x );
        }
        printf("%d\n", ans);
    }
    return 0;
}