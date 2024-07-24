#include <bits/stdc++.h>
using namespace std;
#define ll long long

ll n, q, m;
vector<ll> ft(2*1e5, 0);
ll get(ll i){
    ll ans = 0;
    for (; i > 0; i -= i & (-i))
        ans += ft[i];
    return ans;
}

void add(ll i, ll delta) {
    for (; i < ft.size(); i += i & (-i))
        ft[i] += delta;
}

ll lower_b(ll val){
    ll l = 1;
    ll u = n;
    while(l < u){
        ll m = l + (u-l)/2;
        if (get(m) < val)
            l = m + 1;
        else
            u = m;
    }
    return l-1;
}
int main() {
    char op;
    cin >> n >> q;

    /* 0 1 2 3 4 5 6 7 */
    /* 1 2 3 3 4 5 6 7 */
    /* 9 8 7 - 5 4 3 2 */

    /* 0 1 2 3 4 */
    /* 1 2 3 4 4 */
    /* 3 5 5 4 - */
    vector<ll> v(n);
    for (ll i = 0; i < n; i++){
        cin >> v[i];
        add(i+1, 1);
        add(n+1, -1);
    }
    ll hv = 0;
    ll hft = 1;

    while(q--){
    /* while(cin >> op){ */
        cin >> op;
        switch (op){
            case 'q': cout << v[hv] << endl; break;
            case 'm':
                cin >> m;
                hft += m;
                hv = lower_b(hft);
                break;
            case 'd':
                add(hv+1, -1);
                add(n+1, 1);
                hv = lower_b(hft);
                break;
        }
    }
}
