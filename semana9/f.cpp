#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll oo = 1987654321987654321;

ll dfs(vector<vector<pair<ll, ll>>> &g, vector<bool> &vis, ll r){
    ll res = 0;
    vis[r] = true;
    for (auto [u, w] : g[r]){
        res += w;
        if (vis[u]) continue;
        res += dfs(g, vis, u);
    }
    return res;
}
int main(){
    ll n, m;
    cin >> n >> m;
    vector<vector<pair<ll, ll>>> g1(n);
    vector<vector<pair<ll, ll>>> g2(n);
    vector<ll> d(n, oo);
    vector<bool> vis(n, false);
    while(m--){
        ll u, v, w;
        cin >> u >> v >> w;
        g1[u].push_back(make_pair(v, w));
        g1[v].push_back(make_pair(u, w));
    }
    ll src = 0;
    ll dst = n-1;

    priority_queue<pair<ll, ll>,
        vector<pair<ll, ll>>, greater<pair<ll, ll>>> q;
    d[src] = 0;
    q.push(make_pair(0, src));
    while(!q.empty()){
        auto [p, u] = q.top(); q.pop();
        if (vis[u]) continue;
        vis[u] = true;
        for (auto [v, w] : g1[u]){
            if (d[v] > d[u] + w){
                d[v] = d[u] + w;
                q.push(make_pair(d[v], v));
                g2[v].clear();
                g2[v].push_back(make_pair(u, w));
            }else if (d[v] == d[u] + w){
                g2[v].push_back(make_pair(u, w));
            }
        }
    }
    fill(vis.begin(), vis.end(), false);
    cout << 2*dfs(g2, vis, dst) << endl;
}
