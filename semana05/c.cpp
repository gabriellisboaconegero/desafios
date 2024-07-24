#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main() {
    ll n, m, k;
    cin >> n >> m >> k;
    vector<ll> v(n);
    for (auto &i : v)
        cin >> i;

    if (m == 1){
        cout << max_element(v.begin(), v.end()) << endl;
        return 0;
    }

    vector<vector<ll>> dp_0(n, vector<ll>(n, 0));
    vector<vector<ll>> dp_1(n, vector<ll>(n, 0));
    auto &dp0 = dp_0;
    auto &dp1 = dp_1;

    vector<vector<ll>> eg(n, vector<ll>(n, 0));

    for (ll i = 0; i < k; i++){
        ll i, j;
        cin >> i >> j;
        cin >> eg[i][j];
    }

    for (ll i = 0; i < n; i++){
        for (ll j = 0; j < i; j++)
            dp0[i][j] = v[i] + v[j] + eg[i][j];
        for (ll j = i+1; j < n; j++)
            dp0[i][j] = v[i] + v[j] + eg[i][j];
    }

    for (auto &l: dp0){
        for (auto &i: l){
            cout << i << " ";
        }
        cout << endl;
    }
        
    return 0;
}