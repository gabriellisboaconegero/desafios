#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll oo = 1987654321987654321;
#define NEUTRAL oo
#define FACTOR(sz) (1)
#define OP(x, y) (min((x),(y)))
const ll N = 1e5+15;

vector<ll> t (4*N), lazy (4*N), sety (4*N, -1);
void push(ll ti, ll tl, ll tm, ll tr) {
    if (sety[ti] != -1) {
        t[ti*2] = sety[ti] * FACTOR(tm - tl + 1);
        lazy[ti*2] = 0; sety[ti*2] = sety[ti];
        t[ti*2+1] = sety[ti] * FACTOR(tr - (tm+1) + 1);
        lazy[ti*2+1] = 0; sety[ti*2+1] = sety[ti];
        sety[ti] = -1;
    }
    t[ti*2] += lazy[ti] * FACTOR(tm - tl + 1);
    lazy[ti*2] += lazy[ti];
    t[ti*2+1] += lazy[ti] * FACTOR(tr - (tm+1) + 1);
    lazy[ti*2+1] += lazy[ti];
    lazy[ti] = 0;
}
ll op_inclusive(ll l, ll r,
        ll ti=1, ll tl=1, ll tr=N) {
    if (l > r) { return NEUTRAL; }
    if (l <= tl && tr <= r) { return t[ti]; }
    ll tm = (tl + tr) / 2; push(ti, tl, tm, tr);
    return OP(op_inclusive(l, min(r, tm), ti*2, tl, tm),
            op_inclusive(max(l, tm+1), r, ti*2+1, tm+1, tr));
}

void set_inclusive(ll l, ll r, ll d,
        ll ti=1, ll tl=1, ll tr=N) {
    if (l > r) { return; }
    if (l == tl && tr == r) {
        t[ti] = ll(d) * FACTOR(tr - tl + 1);
        sety[ti] = d; lazy[ti] = 0; return; }
    ll tm = (tl + tr) / 2; push(ti, tl, tm, tr);
    set_inclusive(l, min(r, tm), d, ti*2, tl, tm);
    set_inclusive(max(l, tm+1), r, d, ti*2+1, tm+1, tr);
    t[ti] = OP(t[ti*2], t[ti*2+1]);
}

void add_inclusive(ll l, ll r, ll d,
        ll ti=1, ll tl=1, ll tr=N) {
    if (l > r) { return; }
    if (l == tl && tr == r) {
        t[ti] += ll(d) * FACTOR(tr - tl + 1); lazy[ti] += d; return; }
    ll tm = (tl + tr) / 2; push(ti, tl, tm, tr);
    add_inclusive(l, min(r, tm), d, ti*2, tl, tm);
    add_inclusive(max(l, tm+1), r, d, ti*2+1, tm+1, tr);
    t[ti] = OP(t[ti*2], t[ti*2+1]);
}

void build(vector<ll> &src, ll ti=1, ll tl=1, ll tr=N){
    if (tl == tr){
        if (tl < ll(src.size())) t[ti] = src[tl];
        return;
    }
    ll tm = (tl + tr)/2;
    build(src, ti*2, tl, tm);
    build(src, ti*2+1, tm+1, tr);
    t[ti] = OP(t[ti*2], t[ti*2+1]);
}

int main(){
    ll n, q;
    cin >> n >> q;
    vector<ll> v(n+1);
    for (ll i = 1; i <= n; i++) cin >> v[i];
    build(v);

    while(q--){
        ll op, a, b, x;
        cin >> op;
        switch(op){
            case 1:
                cin >> a >> b >> x;
                add_inclusive(a, b, x);
                break;
            case 2:
                cin >> a >> b;
                cout << op_inclusive(a, b) << endl;
        }
    }
    return 0;
}
