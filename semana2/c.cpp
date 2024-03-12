#include <bits/stdc++.h>
using namespace std;

#define ll long long int

int main() {
    int n;
    cin >> n;

    vector<int> v(n), id(n);
    for (auto &i : v) cin >> i;
    iota(begin(id), end(id), 0);

    sort(begin(id), end(id), [&](int i, int j){
        return v[i] < v[j];
            });

    ll sum = 1;
    for (ll i = 1; i < n; i++)
        if (id[i] < id[i-1])
            sum++;

    cout << sum << endl;
    return 0;
}
