#include <bits/stdc++.h>
using namespace std;
#define ll long long

struct vert {
    bool visited;
    ll dist;
};

pair<ll,ll> bfs(vector<vector<ll>> &g, ll start){
    queue<ll> q;
    vector<struct vert> visitados(g.size(), (struct vert){
        .visited=false,
    });
    visitados[start].visited = true;
    visitados[start].dist = 0;
    q.push(start);
    ll maior = start;

    while(!q.empty()){
        ll v = q.front(); q.pop();
        maior = v;
        for (auto w : g[v]){
            if (!visitados[w].visited){
                visitados[w].visited = true;
                visitados[w].dist = visitados[v].dist+1;
                q.push(w);
            }
        }
    }
    return make_pair(maior, visitados[maior].dist);
}

int main(){
    ll n, u, v;
    cin >> n;
    vector<vector<ll>> g(n);
    for (ll i = 0; i < n - 1; i++){
        cin >> v >> u;
        g[u-1].push_back(v-1);
        g[v-1].push_back(u-1);
    }
    cout << bfs(g, bfs(g, 0).first).second << endl;
}
