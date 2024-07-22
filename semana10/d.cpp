#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll oo = 1987654321987654321;
#define OP(x, y) ((x) + (y))
const ll NEUTRAL = 0;
const ll N = 1e5+15;

vector<ll> t(4*N);

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

ll op_inclusive(ll l, ll r, ll ti=1, ll tl=1, ll tr=N){
    if (tl > tr)
        return NEUTRAL;
    if (tl == l && tr == r)
        return t[ti];
    ll tm = (tl + tr)/2;
    return OP(
            op_inclusive(l, min(r, tm), ti*2, tl, tm),
            op_inclusive(max(l, tm), r, ti*2+1, tm+1, tr));
}

void set_value(ll i, ll val, ll ti=1, ll tl=1, ll tr=N){
    if (tl == tr){
        t[ti] = val;
        return;
    }
    ll tm = (tl + tr)/2;
    if (i <= tm)
        set_value(i, val, ti*2, tl, tm);
    else
        set_value(i, val, ti*2+1, tm+1, tr);
    t[ti] = OP(t[ti*2], t[ti*2+1]);
}

int main(){
    ll n, k, i, j;
    cin >> n >> k;
    vector<ll> v(n);
    for (auto &i : v) cin >> i;
    
    build(v);
    char op;
    for (ll x = 0; x < k; x++){
        cin >> op >> i >> j;;
        switch(op){
            case 'A':
                set_value(i, j);
                break;
            case 'B':
                ll s = op_inclusive(i, j);
                cout << (s == 0 ? "0" : (s < 0 ? "-" : "+"));
                break;
        }
    }
    cout << endl;
    return 0;
}
