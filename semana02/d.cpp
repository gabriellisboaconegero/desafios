#include <bits/stdc++.h>
using namespace std;

#define ll long long int

int main() {
    int n, k;
    ll sum = 0;
    cin >> n >> k;
    vector<tuple<ll, string, ll>> v(n);
    for (auto &i : v) cin >> get<0>(i) >> get<1>(i) >> get<2>(i);
    sort(v.begin(), v.end(), [](tuple<ll, string, ll> a, tuple<ll, string, ll> b){
            if (get<0>(a) != get<0>(b))
                return get<0>(a) < get<0>(b);
            if (get<1>(a) != get<1>(b))
                return get<1>(a)[0] > get<1>(b)[0];
            return get<2>(a) > get<2>(b);
            });
    for (int i = 0; i < k; i++)
        sum += get<2>(v[i]);
    cout << sum << endl;
    
    return 0;
}
