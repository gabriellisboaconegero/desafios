#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll ds_find(ll u, vector<ll> &rep) {
    if (rep[u] != u) { rep[u] = ds_find(rep[u], rep); }
    return rep[u];
}

void ds_union(ll u, ll v, vector<ll> &rep, vector<ll> &rnk) {
    u = ds_find(u, rep); v = ds_find(v, rep);
    assert(u != v);
    if (!(rnk[u] > rnk[v])) { swap(u, v); }
    if (rnk[u] == rnk[v]) { rnk[u]++; }
    rep[v] = u;
}
int main(){
    ll n, m, k;
    cin >> n >> m >> k;
    set<pair<ll, ll>> edges;
    vector<pair<ll, ll>> arreben(k);
    vector<ll> rep(n);
    vector<ll> rnk(n);
    vector<ll> sol;

    while(m--){
        ll u, v;
        cin >> u >> v;
        edges.insert(make_pair(--u, --v));
    }
    for (auto &pi : arreben){
        cin >> pi.first >> pi.second;
        pi.first--;
        pi.second--;
        auto it = edges.find(pi);
        if (it != edges.end())
            edges.erase(pi);
        else
            edges.erase(make_pair(pi.second, pi.first));
    }
    for (int u = 0; u < n; u++){
        rep[u] = u;
        rnk[u] = 0; 
    }
    ll comps = n;
    for (auto [u, v] : edges){
        if (ds_find(u, rep) != ds_find(v, rep)){
            comps--;
            ds_union(u, v, rep, rnk);
        }
    }
    for (auto it = arreben.rbegin(); it != arreben.rend(); it++){
        auto [u, v] = *it;
        sol.push_back(comps);
        if (ds_find(u, rep) != ds_find(v, rep)){
            comps--;
            ds_union(u, v, rep, rnk);
        }
    }
    for (auto it = sol.rbegin(); it != sol.rend(); it++)
        cout << *it << " ";
    cout << endl;
}
