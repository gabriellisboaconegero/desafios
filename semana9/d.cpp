#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll oo = 1987654321987654321;
using dist_type = pair<ll, pair<string, string>>;

int main(){
    ll n, m;
    cin >> n >> m;
    map<string, ll> name_id_map;
    map<ll, string> id_name_map;
    vector<vector<ll>> d(n, vector<ll>(n, oo));
    vector<vector<ll>> g(n);
    vector<ll> pai(n, -1);
    vector<bool> visitados(n, false);
    ll cont = 0;
    while(m--){
        string u, v;
        cin >> u >> v;
        auto [it1, inserted1] = name_id_map.insert(make_pair(u, cont));
        if (inserted1){
            id_name_map.insert(make_pair(cont, u));
            cont++;
        }
        auto [it2, inserted2] = name_id_map.insert(make_pair(v, cont));
        if (inserted2){
            id_name_map.insert(make_pair(cont, v));
            cont++;
        }
        g[it1->second].push_back(it2->second);
        d[it1->second][it2->second] = 1;
    }

    for (ll i = 0; i < n; i++)
        d[i][i] = 0;
    for (ll m = 0; m < n; m++)
    for (ll u = 0; u < n; u++)
    for (ll v = 0; v < n; v++)
        d[u][v] = min(d[u][v], d[u][m] + d[m][v]);

    double sum = 0.0;
    ll num_min_paths = 0;
    vector<dist_type> dists;
    for (ll u = 0; u < n; u++)
        for (ll v = 0; v < n; v++)
            if (d[u][v] != 0 && d[u][v] != oo){
                dists.push_back(make_pair(d[u][v], make_pair(id_name_map[u], id_name_map[v])));
                sum += double(d[u][v]);
                num_min_paths++;
            }
    sort(dists.begin(), dists.end());
    ll med_path = num_min_paths/2 + num_min_paths%2 - 1;
    auto [src_str, dst_str] = dists[med_path].second;
    ll src = name_id_map[src_str];
    ll dst = name_id_map[dst_str];

    queue<ll> q;
    q.push(src);
    while (!q.empty()){
        ll u = q.front(); q.pop();
        for (auto v : g[u]){
            if (visitados[v]) continue;
            visitados[v] = true;
            pai[v] = u;
            if (u == dst) break;
            q.push(v);
        }
    }
    vector<string> sol;
    ll u = dst;
    while(u != src){
        sol.push_back(id_name_map[u]);
        u = pai[u];
    }
    sol.push_back(id_name_map[u]);

    cout << (sum/double(num_min_paths)) << endl;
    for (auto it = sol.rbegin(); it != sol.rend(); it++)
        cout << *it << " ";
    cout << endl;
}
