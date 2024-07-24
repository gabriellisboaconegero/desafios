#include <bits/stdc++.h>
using namespace std;
#define ll long long

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

int main() {
    ll n, q, d, p, a1, a2, b1, b2, op;
    binary_function<ll&, ll&, ll> operation;
    cin >> n;

    for (ll i = 1; i < n+1; i++){
        char c;
        cin >> c;
        d = c-'0';
        add(i, d);
        add(n+1, -d);
    }
    cin >> q;
    
    while(q--){
        cin >> op;
        if (op == 3){
            cin >> p >> d;
            d -= (get(p)-get(p-1));
            add(p, d);
            add(n+1, -d);
            continue;
        }

        cin >> a1 >> b1 >> a2 >> b2 >> d;
        ll a = (get(b1) - get(a1-1))%9;
        ll b = (get(b2) - get(a2-1))%9;
        ll r;
        if (op == 1)
            r = a+b;
        else
            r = a*b;
        cout << ((r%10 + r/10)%9 == d ? "YES" : "NO") << endl;
    }
}
