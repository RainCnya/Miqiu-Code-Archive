#include <bits/stdc++.h>
using namespace std;

bool check( const vector<int>& p, int n ) 
{
    for( int i = 1; i < n; ++ i ) 
    {
        bool found = false;
        for( int j = i; j <= n; ++ j ) 
        {
            if( (p[i-1] ^ p[j-1]) == i ) 
            {
                found = true;
                break;
            }
        }
        if( !found ) return false;
    }
    return true;
}

void search( int n ) 
{
    vector<int> p(n);
    iota( p.begin( ), p.end( ), 1 );

    mt19937 g( random_device{ }( ) );

    long long attempts = 0;
    while( attempts < 1000000000 ) 
    {   // 设定一个 1e9 的尝试上限
        shuffle( p.begin( ), p.end( ), g );
        if( check( p, n ) ) 
        {
            printf("N = %d: (Found in %lld): ", n, attempts);
            for( int x : p ) printf("%d ", x);
            printf("\n");
            return;
        }
        attempts++;
    }
    printf("N = %d: Failed After 1e9 Attempts\n", n);
}

int main( ) 
{
    int n;
    cin >> n;
    for( int i = 1; i <= n; ++ i )
    {
        search( i );
    }
    return 0;
}