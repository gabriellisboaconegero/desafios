#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll oo = 1987654321987654321;

int main(){
    ll n, m;
    cin >> n >> m;
    vector<vector<ll>> d(n, vector<ll>(n, oo));
    while(m--){
        ll u, v, w;
        cin >> u >> v >> w;
        d[u][v] = w;
        d[v][u] = w;
    }
    for (ll i = 0; i < n; i++)
        d[i][i] = 0;
    for (ll m = 0; m < n; m++)
    for (ll u = 0; u < n; u++)
    for (ll v = 0; v < n; v++)
        d[u][v] = min(d[u][v], d[u][m] + d[m][v]);

    ll res = oo;
    for (ll u = 0; u < n; u++)
        res = min(res, *max_element(d[u].begin(), d[u].end()));
    cout << res << endl;
}
