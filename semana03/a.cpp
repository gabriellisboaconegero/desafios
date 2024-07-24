#include <bits/stdc++.h>
using namespace std;
#define ll long long

ll n;
bool respect_restri(vector<bool> &chosen, vector<pair<ll, ll>> &restri, ll k, ll i){
    for (auto r : restri){
        if (i == r.second && !chosen[r.first])
            return false;
    }

    return true;
}

void gen(vector<ll> &v, vector<bool> &chosen, vector<pair<ll, ll>> &restri, ll k){
    if (k == n){
        for (auto i : v) cout << i << " ";
        cout << endl;
        return;
    }
    for (int i = 1; i <= n; i++){
        if (!chosen[i] && respect_restri(chosen, restri, k, i)){
            chosen[i] = true;
            v[k] = i;
            gen(v, chosen, restri, k+1);
            chosen[i] = false;
        }
    }
}

int main(){
    ll c;
    cin >> n >> c;
    vector<pair<ll, ll>> restri(c);
    vector<ll> v(n);
    vector<bool> chosen(n+1);

    for (auto &i : restri) cin >> i.first >> i.second;
    gen(v, chosen, restri, 0);
}
