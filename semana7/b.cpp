#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main() {
    ll t;
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
        stack<pair<ll, ll>> factors;
        for (ll i = 2; i*i <= num; i++){
            ll d = 0;
            while (num%i == 0){
                num/= i;
                d++;
            }
            if (d)
                factors.push(make_pair(i, d));
        }
        if (num > 1)
            factors.push(make_pair(num, 1));
        while(!factors.empty()){
            cout << factors.top().first << " " << factors.top().second << endl;
            factors.pop();
        }
    }
}
