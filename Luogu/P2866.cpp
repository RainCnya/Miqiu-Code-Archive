#include<bits/stdc++.h>
using namespace std;

const int maxn = 1e5 + 50;
int n;
long long a[maxn];

int main()
{	
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin >> n;
    for( int i = 1; i <= n; ++ i )
        cin >> a[i];
    
    stack<int> stk;
    long long cnt = 0;
    for( int i = 1; i <= n; ++ i )
    { 
        long long cur = a[i];
        while( !stk.empty( ) && stk.top( ) <= cur )
            stk.pop( ); 
        cnt += stk.size( );
        stk.push( cur );
    }

    cout << cnt << '\n';
    return 0;
}