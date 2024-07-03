#include <bits/stdc++.h>
using namespace std;
#define ll long long

bool dfs(ll v, vector<vector<ll>> &g, vector<bool> &visitados){
    if (visitados[v])
        return false;
    visitados[v] = true;
    for (auto u : g[v])
        dfs(u, g, visitados);
    return true;
}

int main(){
    ll n, m;
    cin >> n >> m;
    vector<vector<ll>> g(n);
    vector<bool> visitados(n, false);
    for (ll i = 0; i < m; i++){
        ll a, b;
        cin >> a >> b;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    ll res = 0;
    for (ll v = 0; v < n; v++){
        if (dfs(v, g, visitados))
            res++;
    }
    cout << res << endl;
}