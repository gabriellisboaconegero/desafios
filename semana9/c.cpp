#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll oo = 1987654321987654321;

int main(){
    ll n, m, c, k;
    cin >> n >> m >> c >> k;
    vector<vector<pair<ll, ll>>> g(n);
    while(m--){
        ll u, v, p;
        cin >> u >> v >> p;
        g[u].push_back(make_pair(v, p));
        g[v].push_back(make_pair(u, p));
    }
    vector<ll> d(n, oo);
    vector<bool> vis(n, false);
    priority_queue<pair<ll, ll>,
        vector<pair<ll, ll>>, greater<pair<ll, ll>>> q;
    d[k] = 0;
    q.push(make_pair(0, k));
    while(!q.empty()){
        auto [p, u] = q.top(); q.pop();
        if (vis[u]) continue;
        vis[u] = true;
        for (auto [v, w] : g[u]){
            if (u <= c-1){
                if (d[v] > d[u] + w && v == u+1){
                    d[v] = d[u] + w;
                    q.push(make_pair(d[v], v));
                }
            }else{
                if (d[v] > d[u] + w){
                    d[v] = d[u] + w;
                    q.push(make_pair(d[v], v));
                }
            }
        }
    }
    cout << d[c-1] << endl;

}
