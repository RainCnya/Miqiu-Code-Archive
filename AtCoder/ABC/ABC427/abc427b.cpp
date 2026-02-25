#include<bits/stdc++.h>
using namespace std;

const int N = 100 + 5;

int A[N];

int calc( int x )
{
    if( 0 <= x && x <= 10 )
        return x;
    int res = 0, tmp = x;
    while( tmp )
    {
        res += tmp % 10;
        tmp /= 10;
    }
    return res;
}

int main( )
{
    int n;  cin >> n;
    A[0] = 1;
    for( int i = 1; i <= 100; ++ i )
    {
        for( int j = 0; j < i; ++ j )
        {
            A[i] += calc(A[j]);
        }
    }
    
    cout << A[n];
    return 0;
}