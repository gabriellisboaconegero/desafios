#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main(){
    ll n;
    cin >> n;
    vector<ll> v(n);
    vector<ll> rs(n-1);
    for (auto &i : v) cin >> i;

    sort(v.begin(), v.end());

    ll rm = numeric_limits<ll>::max();
    ll rM = numeric_limits<ll>::min();
    for (int i = 1; i < n; i++){
        rm = min(rm, v[i]/v[i-1]);
        rM = max(rM, v[i]/v[i-1]);
    }
    /* 6, 5 */
    /* 0 1 2 3 4 5 */
    /* x x x x x x */

    if (rm != rM){
        int i;
        for (i = 1; i < n; i++)
            if (v[i]/v[i-1] == rM)
                break;
        cout << v[i-1]*rm << endl;
    } else {
        if (v[0]%rm == 0 && rm != 1)
            cout << v[0]/rm << endl;
        cout << v.back()*rm << endl;
    }

    return 0;
}
