#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main() {
    ll n;
    ll a;

    while (cin >> n >> a){
        if (n == 0 && a == 0.0)
            break;
        vector<ll> v(n);
        ll t = 0;
        for (auto &i : v){
            cin >> i;
            t += i;
        }
        if (t < a)
            cout << "-.-" << endl;
        else if (t == a)
            cout << ":D" << endl;
        else{
            sort(v.begin(), v.end(), greater<ll>());

            a = t-a;
            ll atual = 0;
            ll n_gt = n;
            auto it = v.begin();
            for (ll i = 0; i < n; i++){
                if (atual > a){
                }
            }
        }
    }
}
