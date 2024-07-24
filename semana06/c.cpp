#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main() {
    ll n;
    cin >> n;

    vector<ll> v(n);
    for (auto &i : v)
        cin >> i;

    vector<ll> r(n, numeric_limits<ll>::max());
    ll nt = 1;
    r[0] = v[0];
    for (ll i = 1; i < n; i++){
        auto it = upper_bound(r.begin(), r.end(), v[i]);
        if (*it == numeric_limits<ll>::max())
            nt++;
        *it = v[i];
    }
    cout << nt << endl;
}
