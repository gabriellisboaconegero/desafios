#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define N 1e7+15

ll big[N] = {1, 1};

int main() {
    ll t;
    for (ll i = 1; i * i < N; i++)
        if (big[i] == 1)
            for (ll j = i; j < N; j+=i)
                big[j] = i;
    cin >> t;
    while(t--){
        ll k, p, e;
        cin >> k;
        ll num = 1;
        while(k--){
            cin >> p >> e;
            ll p_ = 1;
            while(e--)
                p_ *= p;
            num *= p_;
        }
        num--;
        while(num != 1){
            p = big[num];
            e = 0;
            while(big[num] == p){
                num /= big[num];
                e++;
            }
            cout << p << " " << e << endl;
        }
    }
}