#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main(){
    ll q, t, x;
    cin >> q;
    vector<ll> mortes;
    vector<vector<ll>> g(q);
    ll cont = 0;
    for (ll i = 0; i < q; i++){
        cin >> t >> x;
        if (t == 1)
            g[--x].push_back(++cont);
        else
            mortes.push_back(--x);
    }
    ll rei = 0;
    stack<ll> s;
    vector<bool> morto(q, false);
    for (auto morte : mortes){
        morto[morte] = true;
        if (morte == rei){
            bool found = false;
            s.push(rei);
            while (!s.empty() && !found){
                ll u = s.top(); s.pop();
                if (!morto[u]){
                    rei = u;
                    found = true;
                }else
                    for (auto it = g[u].rbegin(); it != g[u].rend(); it++)
                        s.push(*it);
            }
        }
        cout << rei+1 << endl;
    }
}
