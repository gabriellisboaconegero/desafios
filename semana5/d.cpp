#include <bits/stdc++.h>
using namespace std;
#define ll long long

map<ll,ll> m;
ll f(ll n){
    if (n == 0)
        return 1;
    const auto [it, b] = m.emplace(n, 0);
    if (!b)
        return it->second;
    return m[n] = f(n/2)+f(n/3);
}

int main() {
    ll n;
    cin >> n;
    cout << f(n) << endl;
}