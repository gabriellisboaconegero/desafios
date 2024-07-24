#include <bits/stdc++.h>
using namespace std;
using ll = long long;

vector<vector<ll>> t;

void build(vector<ll> &src, ll ti, ll tl, ll tr){
    if (tl == tr){
        if (tl < ll(src.size())) t[ti] = vector<ll>(1, src[tl]);
        return;
    }
    ll tm = (tl + tr)/2;
    build(src, ti*2, tl, tm);
    build(src, ti*2+1, tm+1, tr);
    t[ti] = vector<ll>(t[ti*2].size() + t[ti*2+1].size(), 0);
    merge(t[ti*2].begin(), t[ti*2].end(), t[ti*2+1].begin(), t[ti*2+1].end(),
            t[ti].begin());
}

ll query_upper_bound(ll l, ll r, ll x, ll ti, ll tl, ll tr){
    if (l > r)
        return 0;
    if (tl == l && tr == r)
        return upper_bound(t[ti].begin(), t[ti].end(), x) - t[ti].begin();
    ll tm = (tl + tr)/2;
    return query_upper_bound(l, min(r, tm), x, ti*2, tl, tm) +
           query_upper_bound(max(l, tm+1), r, x, ti*2+1, tm+1, tr);
}

int main(){
    ll n, q;
    cin >> n >> q;
    vector<ll> v(n+1);
    t.resize(4*n);
    for (ll i = 1; i <= n; i++) cin >> v[i];
    build(v, 1, 1, n);
    while(q--){
        ll i, j, k;
        cin >> i >> j >> k;
        ll hi = 1e9, lo = -1e9;
        while (lo <= hi){
            ll m = (hi+lo)/2;
            ll val = query_upper_bound(i, j, m, 1, 1, n);
            if (val < k)
                lo = m + 1;
            else
                hi = m - 1;
        }
        cout << lo << endl;
    }
}
