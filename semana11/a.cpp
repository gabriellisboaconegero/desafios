#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll tk = 0;
vector<ll> tin, low;
stack<ll> st;
vector<ll> rep, onst;
void dfs_tarjan(vector<vector<ll>> &g, ll u) {
    if (tin[u] != -1) { return; }
    tin[u] = low[u] = onst[u] = ++tk;
    st.push(u);
    for (ll v : g[u]) {
        dfs_tarjan(g, v);
        if (onst[v]) low[u] = min(low[u], low[v]);
    }
    if (low[u] == tin[u]) {
        ll v; do {
            v = st.top(); st.pop(); onst[v] = 0;
            rep[v] = u;
        } while (u != v);
    }
}
void tarjan(vector<vector<ll>> &g, ll n) {
    for (ll u = 0; u < n; u++) { dfs_tarjan(g, u); }
}

int main(){
    ll n, m;
    cin >> n >> m;
    
    tin.resize(n, -1);
    low.resize(n);
    rep.resize(n);
    onst.resize(n);

    vector<vector<ll>> g(n);
    vector<set<ll>> cg(n);
    vector<set<ll>> cgt(n);

    while(m--){
        ll u, v;
        cin >> u >> v;
        u--; v--;
        g[u].push_back(v);
    }

    tarjan(g, n);
    for (int u = 0; u < n; u++)
        for (int v : g[u]) if (rep[u] != rep[v]){
            cg[rep[u]].insert(rep[v]);
            cgt[rep[v]].insert(rep[u]);
        }
    ll sumidouros_cg = 0;
    ll sumidouros_cgt = 0;
    ll num_componentes = 0;
    for (int u = 0; u < n; u++){
        if (rep[u] == u){
            sumidouros_cg += cg[u].size() == 0;
            sumidouros_cgt += cgt[u].size() == 0;
            num_componentes++;
        }
    }
    if (num_componentes > 1)
        cout << max(sumidouros_cgt, sumidouros_cg) << endl;
    else
        cout << 0 << endl;
}
