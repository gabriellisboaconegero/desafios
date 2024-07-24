#include <bits/stdc++.h>
using namespace std;
#define ll long long

void gcd(ll a, ll b, vector<ll> &v){
    if (b == 0) return;
    v.push_back(a/b);
    return gcd(b, a%b, v);
}
int main() {
    ll n, d, t;
    cin >> t;
    while (t--){
        cin >> n >> d;
        vector<ll> v;
        gcd(n, d, v);
        cout << "[";
        cout << v.front();
        if (v.size() > 1)
            cout << ";" << v[1];
        for (ll i = 2; i < v.size(); i++)
            cout << "," << v[i];
        cout << "]";
        cout << endl;
    }
}
