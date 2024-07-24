#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define N 1e6

int main() {
    ll t, n, k;
    cin >> t;
    vector<ll> pr, lp (N+15);
    for (ll i = 2; i <= N; i++) {
        if (lp[i] == 0) { lp[i] = i; pr.push_back(i); }
        for (ll j = 0; j < int(pr.size())
                && pr[j] <= lp[i] && i*pr[j] <= N; j++)
            lp[i * pr[j]] = pr[j];
    }
    while(t--){
        cin >> n >> k;
        ll prod = 1;
        for (ll i = 0; i < k; i++)
            prod *= pr[i];
        ll i = k;
        while ((prod / pr[i-k])*pr[i] < n){
            prod /= pr[i-k];
            prod *= pr[i];
            i++;
        }
        cout << prod << endl;
    }
}