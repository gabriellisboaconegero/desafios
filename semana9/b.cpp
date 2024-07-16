#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll oo = 1987654321987654321;

struct edge {
    ll u, v, w;
};

int main(){
    ll n, m, q;
    cin >> n;
    vector<ll> lots(n);
    for (auto &i : lots)
        cin >> i;
    cin >> m;
    vector<struct edge> edges(m);
    for (auto &e : edges){
        cin >> e.u >> e.v;
        e.w = lots[--e.v] - lots[--e.u];
    }
    vector<ll> d(n, oo);
    d[0] = 0;
    for (int i = 0; i < n - 1; i++)
        for (auto e : edges)
            if (d[e.u] != oo && d[e.v] > d[e.u] + e.w)
                d[e.v] = d[e.u] + e.w;
    for (auto e : edges)
        if (d[e.u] != oo && d[e.v] > d[e.u] + e.w){
            fill(d.begin(), d.end(), -oo);
            d[0] = 0;
            break;
        }
    cin >> q;
    while(q--){
        ll u;
        cin >> u;
        u--;
        if (d[u] < 3 || d[u] == oo)
            cout << "Não, Edsger..." << endl;
        else
            cout << d[u] << endl;
    }
}
