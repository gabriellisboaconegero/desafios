#include <bits/stdc++.h>
using namespace std;
#define ll long long
ll n;
ll dfs(vector<vector<ll>> &g, ll v, vector<bool> &visitados,vector<vector<ll>> &edges){
    ll res = 0;
    visitados[v] = true;
    for (auto u : g[v]){
        if (visitados[u]) continue;
        ll r = dfs(g, u, visitados, edges)+1;
        edges[v].push_back(r);
        edges[u].push_back(n - r);
        res += r;
    }
    return res;
}
int main(){
    cin >> n;
    vector<vector<ll>> g(n);
    vector<bool> visitados(n, false);
    vector<vector<ll>> edges(n);
    for (ll i = 0; i < n - 1; i++){
        ll a, b;
        cin >> a >> b;
        a--; b--;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    dfs(g, 0, visitados, edges);
    for (ll i = 0; i < n; i++){
        ll m = 0;
        for (auto j : edges[i])
            m = max(m, j);
        if (m <= n/2){
            cout << i + 1 << endl;
            return 0;
        }
    }
}
