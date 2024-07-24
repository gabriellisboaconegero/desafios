#include <bits/stdc++.h>
using namespace std;
#define ll long long

struct vert {
    bool visited;
    char dir;
    ll dist;
    ll parent;
};
int main(){
    ll n, m, start_v, end_v;
    cin >> n >> m;
    vector<vector<pair<ll, char>>> g(n*m);
    vector<string> map(n);
    vector<struct vert> visitados(n*m, (struct vert){
        .visited=false,
    });
    for (auto &s : map)
        cin >> s;
    for (ll i = 0; i < n; i++){
        for (ll j = 0; j < m; j++){
            char c = map[i][j];
            switch(c){
                case 'A': start_v = i*m + j; break;
                case 'B': end_v = i*m + j; break;
            }
            if (c == '#')
                continue;
            if (i < n-1 && map[i+1][j] != '#'){
                g[i*m + j].push_back(make_pair((i+1)*m + j, 'U'));
                g[(i+1)*m + j].push_back(make_pair(i*m + j, 'D'));
            } if (j < m-1 && map[i][j+1] != '#'){
                g[i*m + j].push_back(make_pair(i*m + j+1, 'L'));
                g[i*m + j+1].push_back(make_pair(i*m + j, 'R'));
            }
        }
    }

    queue<ll> q;
    visitados[end_v].visited = true;
    visitados[end_v].dist = 0;
    q.push(end_v);

    bool found = false;
    while(!q.empty() && !found){
        ll v = q.front(); q.pop();
        for (auto pw : g[v]){
            ll w = pw.first;
            if (!visitados[w].visited){
                visitados[w].visited = true;
                visitados[w].dir = pw.second;
                visitados[w].dist = visitados[v].dist+1;
                visitados[w].parent = v;
                q.push(w);
                if (w == start_v){
                    found = true;
                    break;
                }
            }
        }
    }

    if (!found)
        cout << "NO" << endl;
    else{
        cout << "YES" << endl;
        cout << visitados[start_v].dist << endl;
        ll w = start_v;
        while (w != end_v){
            cout << visitados[w].dir;
            w = visitados[w].parent;
        }
        cout << endl;
    }
}
