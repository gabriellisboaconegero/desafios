#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main() {
    ll n;
    cin >> n;
    vector<ll> pr, lp (1e7+15);
    for (ll i = 2; i <= n; i++) {
        if (lp[i] == 0) { lp[i] = i; pr.push_back(i); }
        for (ll j = 0; j < int(pr.size())
                && pr[j] <= lp[i] && i*pr[j] <= n; j++)
            lp[i * pr[j]] = pr[j];
    }

    ll sum = 0;
    for (ll i = 0; i < pr.size() && pr[i] <= n; i++)
        sum += lp[n-pr[i]] == n-pr[i];
    sum += (n%2 == 0) && (lp[n/2] == n/2);
    cout << sum/2<< endl;
}
