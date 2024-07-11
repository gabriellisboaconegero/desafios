#include <bits/stdc++.h>
using namespace std;
using ll = long long;
ll oo = 1987654321987654321;
using edge = pair<ll, ll>;

bool bounded(ll i, ll j, vector<vector<edge>> &mapa){
    return (i >= 0 &&
            i < ll(mapa.size()) &&
            j >= 0 &&
            j < ll(mapa.front().size()));
}

vector<edge> vizinhanca4(ll i, ll j, vector<vector<edge>> &mapa){
    vector<edge> res;
    if (bounded(i - 1, j, mapa))
        res.push_back(make_pair(i - 1, j));
    if (bounded(i + 1, j, mapa))
        res.push_back(make_pair(i + 1, j));
    if (bounded(i, j - 1, mapa))
        res.push_back(make_pair(i, j - 1));
    if (bounded(i, j + 1, mapa))
        res.push_back(make_pair(i, j + 1));
    return res;
}
vector<edge> vizinhanca4_diag(ll i, ll j, vector<vector<edge>> &mapa){
    vector<edge> res;
    if (bounded(i - 1, j - 1, mapa))
        res.push_back(make_pair(i - 1, j - 1));
    if (bounded(i - 1, j + 1, mapa))
        res.push_back(make_pair(i - 1, j + 1));
    if (bounded(i + 1, j - 1, mapa))
        res.push_back(make_pair(i + 1, j - 1));
    if (bounded(i + 1, j + 1, mapa))
        res.push_back(make_pair(i + 1, j + 1));
    return res;
}

int main(){
    ll n, m, t;
    cin >> n >> m >> t;
    vector<vector<edge>> mapa(n, vector<edge>(m, make_pair(0, oo)));
    queue<pair<ll, ll>> zeros;
    for (ll i = 0; i < n; i++){
        for (ll j = 0; j < m; j++){
            cin >> mapa[i][j].first;
            if (mapa[i][j].first == 0){
                zeros.push(make_pair(i, j));
                mapa[i][j].second = 0;
            }
        }
    }

    ll zeros_cont = 0;
    while(!zeros.empty()){
        auto [i, j] = zeros.front(); zeros.pop();
        if (mapa[i][j].second <= t)
            zeros_cont++;
        for (auto [vi, vj] : vizinhanca4(i, j, mapa)){
            ll val = mapa[vi][vj].first;
            if (val == 5 || val == 0)
                continue;
            if (val <= 2){
                mapa[vi][vj].first = 0;
                mapa[vi][vj].second = mapa[i][j].second+1;
                zeros.push(make_pair(vi, vj));
            }else
                mapa[vi][vj].first--;
        }
        for (auto [vi, vj] : vizinhanca4_diag(i, j, mapa)){
            if (mapa[vi][vj].first == 1){
                mapa[vi][vj].first = 0;
                mapa[vi][vj].second = mapa[i][j].second+1;
                zeros.push(make_pair(vi, vj));
            }
        }
    }
     cout << zeros_cont << endl;
}
