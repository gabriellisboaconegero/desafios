#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main() {
    ll n, m;
    cin >> n >> m;

    multiset<ll> ms;
    for (ll i = 0; i < n; ++i){
        ll a;
        cin >> a;
        ms.insert(a);
    }

    for (ll i = 0; i < m; i++){
        ll a;
        cin >> a;
        auto u = ms.upper_bound(a);
        if (u == ms.begin())
            cout << -1 << endl;
        else {
            u--;
            cout << *u << endl;
            ms.erase(u);
        }
    }
}
