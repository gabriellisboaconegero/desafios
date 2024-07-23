#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define NEUTRAL (vector<ll>())
#define OP(x, y) merge((x).begin(), (x).end(), (y).begin(), (y).end(), )
const ll N = 1e5+15;

vector<vector<ll>> t(4*N);

void build(vector<ll> &src, ll ti=1, ll tl=1, ll tr=N){
    if (tl == tr){
        if (tl < ll(src.size())) t[ti] = vector<ll>(1, src[tl]);
        return;
    }
    ll tm = (tl + tr)/2;
    build(src, ti*2, tl, tm);
    build(src, ti*2+1, tm+1, tr);
    merge(t[ti*2].begin(), t[ti*2].end(), t[ti*2+1].begin(), t[ti*2+1].end(),
            t[ti]);
}

ll query(ll l, ll r, ll x, ll ti=1, ll tl=1, ll tr=N){
    if (l > r)
        return NEUTRAL;
    if (tl == l && tr == r)
        return t[ti];
    ll tm = (tl + tr)/2;
    return OP(
            op_inclusive(l, min(r, tm), ti*2, tl, tm),
            op_inclusive(max(l, tm+1), r, ti*2+1, tm+1, tr));
}

int main(){
    ll n, q;
    cin >> n >> q;
    vector<ll> v(n+1);
    for (ll i = 1; i <= n; i++) cin >> v[i];
    build(v);
    while(q--){
        ll i, j, k;
        cin >> i >> j >> k;
        cout << op_inclusive(i, j, k) << endl;
    }
}
