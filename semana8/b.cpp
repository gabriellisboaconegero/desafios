#include <bits/stdc++.h>
using namespace std;
#define ll long long

ll n, m, start_v, end_v;
ll dfs(ll v, vector<vector<pair<ll, char>>> &g, vector<pair<ll, ll>> &visitados){
    ll dist = 0;
    for (auto pu : g[v]){
        if (visitados[pu].first == 0){
            dist = dfs(pu.first, g, visitados);
        }else if(visitados.first ){
            
        }
    }
    return dist;
}

int main(){
    cin >> n >> m;
    vector<vector<pair<ll, char>>> g(n*m);
    vector<pair<ll, ll>> visitados(n*m, make_pair(0, -1));
    for (ll i = 0; i < n; i++){
        string l;
        cin >> l;
        for (ll j = 0; j < int(l.size()); j++){
            switch(l[j]){
                case 'A': start_v = i*n + j; break;
                case 'B': end_v = i*n + j; break;
                case '#': visitados[i*n + j] = true;
            }
            if (i < n-1){
                g[i*n + j].push_back(make_pair((i+1)*n + j, 'R'));
                g[(i+1)*n + j].push_back(make_pair(i*n + j, 'L'));
            } if (j < n-1){
                g[i*n + j].push_back(make_pair(i*n + j+1, 'D'));
                g[i*n + j+1].push_back(make_pair(i*n + j, 'U'));
            }
        }
    }

    dfs(end_v, g, visitados);
    if (path.size()){
        cout << "YES" << endl;
        cout << path.size() << endl;
        for (auto c : path)
            cout << c;
        cout << endl;
    }else{
        cout << "NO" << endl;
    }
}