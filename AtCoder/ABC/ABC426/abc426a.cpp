#include<iostream>
#include<vector>
#include<utility>

using std::pair;
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;

int main() {
    using namespace std;
    string a, b;
    cin >> a >> b;
    int a1, b1;
    if( a == "Ocelot" ) a1 = 2;
    if( b == "Ocelot" ) b1 = 2;
    if( a == "Serval" ) a1 = 1;
    if( b == "Serval" ) b1 = 1;
    if( a == "Lynx" ) a1 = 0;
    if( b == "Lynx" ) b1 = 0;
    if( a1 <= b1 ) cout << "Yes";
    else cout << "No";
    return 0;
}