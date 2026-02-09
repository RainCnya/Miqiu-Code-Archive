#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int maxn = 1e5 + 50;

struct State { 
    int weight, time;
    bool operator < ( const State& oth ) const {
        if( weight != oth.weight ) return weight < oth.weight;
        return time > oth.time;
    }
};

int n;

void solve( )
{
    priority_queue<State> pq[4];

    int idx = 0;
    for( int i = 1; i <= n; ++ i )
    {
        string opt;
        cin >> opt;
        
        if( opt == "IN" )
        {
            ++ idx;
            int weight, doctor;
            cin >> doctor >> weight;
            pq[doctor].push({ weight, idx });
        }
        else if( opt == "OUT" )
        {
            int doctor;
            cin >> doctor;
            if( pq[doctor].empty( ) ) cout << "EMPTY" << '\n';
            else 
            {
                cout << pq[doctor].top( ).time << '\n';
                pq[doctor].pop( );
            }
        }
    }
}

int main( )
{
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    while( cin >> n ) solve( );
    return 0;
}