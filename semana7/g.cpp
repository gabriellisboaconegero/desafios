#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int M = 1e9+7;
ll mult(ll a, ll b){
    return ((a%M)*(b%M))%M;
}
ll fast_pow(ll a, ll b) {
    if (b == 0) { return 1; } if (b == 1) { return a; }
    ll res = fast_pow(a, b/2);
    res = (res * res) % M;
    if (b % 2) res = (res * a) % M;
    return res;
}
int main() {
    ll n, k, r, c;
    cin >> n >> k;
    vector<pair<ll, ll>> v(n, make_pair(0, n));
    ll maior_fat = 0;
    for (auto &pi : v){
        cin >> pi.first;
        maior_fat = max(maior_fat, pi.first);
    }
    while(k--){
        cin >> r >> c;
        v[c-1].second--;
    }
    vector<ll> fat(maior_fat+1);
    fat[0] = 1;
    for (ll i = 1; i < fat.size(); i++)
        fat[i] = mult(fat[i-1], i);
    ll res = 1;
    for (auto pi : v)
        res = mult(res, mult(fat[pi.first], fast_pow(fat[pi.first-pi.second], M-2)));
    cout << res << endl;
}
