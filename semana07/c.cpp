#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define divs(a, b, k) ((b)/(k) - (a-1)/(k))

int main() {
    ll a, b, n;
    cin >> a >> b >> n;
    vector<ll> v(n);
    for (auto &i : v) cin >> i;
    ll res = 0;
    for (ll s = 0; s < (1 << n); s++){
        ll parity = 0;
        ll l = 1;
        for (int i = 0; i < n; i++){
            ll active = bool(s & (1<<i));
            parity += active;
            if (active) {
                if (v[i] > numeric_limits<ll>::max() / (l/gcd(l, v[i]))) {
                    l = b+1;
                    break;
                }
                l *= v[i]/(gcd(l, v[i]));
            }
        }
        res += (parity%2 ? -1 : 1)*(divs(a, b, l));
    }
    cout << res << endl;
}
