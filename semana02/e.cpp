#include <bits/stdc++.h>
using namespace std;

#define ll long long int

int main() {
    ll t;
    cin >> t;
    while (t--){
        ll sz, n, pos;
        cin >> sz >> n;
        ll minD = numeric_limits<ll>::min();
        ll maxD = numeric_limits<ll>::min();

        while (n--){
            cin >> pos;
            minD = max(minD, min(pos, abs(sz-pos)));
            maxD = max(maxD, max(pos, abs(sz-pos)));
        }
        cout << minD << " " << maxD << endl;
    }
}
