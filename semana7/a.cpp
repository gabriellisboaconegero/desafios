#include <bits/stdc++.h>
#include "utils.cpp"
using namespace std;
#define ll long long

int main() {
    ll n, c;
    cin >> n >> c;
    vector<ll> b(n);
    vector<ll> co(n, 0);
    ll maior = 0;
    for (auto &i:b){
        cin >> i;
        maior = max(maior,i);
    }

    for (auto &i:co){
        ll a, b;
        cin >> a >> b;
        co[b-1]++;
    }

    //calcula cada coluna
    for (ll i = 0; i < n; i++){
        ll div = 
    }
}
