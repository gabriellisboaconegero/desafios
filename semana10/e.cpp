#include <bits/stdc++.h>
using namespace std;
using ll = long long;

vector<pair<ll, ll>> t;

void build(string &src, ll ti, ll tl, ll tr){
    if (tl == tr){
        if (tl-1 < ll(src.size())) t[ti] = make_pair(src[tl-1] == ')', src[tl-1] == '(');
        return;
    }
    ll tm = (tl + tr)/2;
    build(src, ti*2, tl, tm);
    build(src, ti*2+1, tm+1, tr);
    ll matches_number = min(t[ti*2].second, t[ti*2+1].first);
    ll opened_brak_needed = t[ti*2].first + (t[ti*2+1].first - matches_number);
    ll closed_brak_needed = t[ti*2+1].second + (t[ti*2].second - matches_number);
    t[ti] = make_pair(opened_brak_needed, closed_brak_needed);
}

pair<ll, ll> get(ll l, ll r, ll ti, ll tl, ll tr){
    if (l > r){
        /* cout << "(" << tl << "," << tr << "): " << 0 << " " << 0 << endl; */
        return make_pair(0, 0);
    }

    if (tl == l && tr == r){
        /* cout << "(" << tl << "," << tr << "): " << t[ti].first << " " << t[ti].second << endl; */
        return t[ti];
    }

    ll tm = (tl+tr)/2;
    pair<ll, ll> l_s = get(l , min(r, tm), ti*2, tl, tm);
    pair<ll, ll> r_s = get(max(l, tm+1), r, ti*2+1, tm+1, tr);

    ll matches_number = min(l_s.second, r_s.first);
    /* cout << "min: " << matches_number << endl; */
    /* printf("l_s: (%d %d) r_s: (%d %d)\n", l_s.first, l_s.second, r_s.first, r_s.second); */
    ll opened_brak_needed = l_s.first + (r_s.first - matches_number);
    ll closed_brak_needed = r_s.second + (l_s.second - matches_number);
    /* cout << "(" << tl << "," << tr << "): " << opened_brak_needed << " " << closed_brak_needed << endl; */
    return make_pair(opened_brak_needed, closed_brak_needed);
}

void update(ll i, char p, ll ti, ll tl, ll tr){
    if (tl == tr){
        t[ti] = make_pair(p == ')', p == '(');
        return;
    }
    ll tm = (tl+tr)/2;

    if (i <= tm)
        update(i, p, ti*2, tl, tm);
    else
        update(i, p, ti*2+1, tm+1, tr);

    ll matches_number = min(t[ti*2].second, t[ti*2+1].first);
    ll opened_brak_needed = t[ti*2].first + (t[ti*2+1].first - matches_number);
    ll closed_brak_needed = t[ti*2+1].second + (t[ti*2].second - matches_number);
    t[ti] = make_pair(opened_brak_needed, closed_brak_needed);
}

int main(){
    ll n, q;
    string s;
    cin >> n >> q >> s;
    t.resize(4*n);
    build(s, 1, 1, n);
    while(q--){
        ll op, i, j;
        cin >> op >> i >> j;
        if (op == 1){
            update(i, s[j-1], 1, 1, n);
            update(j, s[i-1], 1, 1, n);
            char sa = s[i-1];
            s[i-1] = s[j-1];
            s[j-1] = sa;
        }else if(op == 2){
            auto [opened_brak_needed, closed_brak_needed] = get(i, j, 1, 1, n);
            cout << (opened_brak_needed == 0 && closed_brak_needed == 0 ? "Yes" : "No") << endl;
        }
    }
}
