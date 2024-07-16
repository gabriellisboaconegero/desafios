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
        d[it1->second][it2->second] = 1;
    }

    for (ll i = 0; i < n; i++)
        d[i][i] = 0;
    for (ll m = 0; m < n; m++)
    for (ll u = 0; u < n; u++)
    for (ll v = 0; v < n; v++)
        d[u][v] = min(d[u][v], d[u][m] + d[m][v]);


    for (ll u = 0; u < n; u++)
        cout << id_name_map[u] << " ";
    cout << endl;
    for (ll u = 0; u < n; u++){
        cout << setw(10) << id_name_map[u] << ": ";
        for (ll v = 0; v < n; v++)
            cout << d[u][v] << " ";
        cout << endl;
    }

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

    cout << (sum/double(num_min_paths)) << endl;
}
