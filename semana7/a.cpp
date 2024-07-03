#include <bits/stdc++.h>
using namespace std;
#define ll long long
const ll M = 1e9+7;
inline ll mult(ll a, ll b, ll m){
    return ((a%m)*(b%m))%m;
}

ll fast_pow(ll a, ll b) {
    if (b == 0) { return 1; } if (b == 1) { return a; }
    ll res = fast_pow(a, b/2);
    res = mult(res, res, M);
    if (b % 2) res = mult(res, a, M);
    return res;
}

ll num_divisores(vector<pair<ll,ll>> &primes){
    ll res = 1;
    for (auto pi : primes)
        res = mult(res, (pi.second + 1), M);
    return res;
}

ll prod_divisores(vector<pair<ll,ll>> &primes, bool all_even){
    ll divs = 1, num = 1;
    if (all_even){
        for (auto pi : primes){
            divs = mult(divs, pi.second+1, M-1);
            num = mult(num, fast_pow(pi.first, pi.second/2), M);
        }
    }else{
        bool divided = false;
        for (auto pi : primes){
            if (!divided && (pi.second+1)%2 == 0){
                divided = true;
                divs = mult(divs, (pi.second+1)/2, M-1);
            } else
                divs = mult(divs, pi.second+1, M-1);
            num = mult(num, fast_pow(pi.first, pi.second), M);
        }
    }
    return fast_pow(num, divs);
}

ll sum_divisores(vector<pair<ll,ll>> &primes){
    ll res = 1;
    for (auto pi : primes)
        res = mult(res,
                mult(fast_pow(pi.first, pi.second+1) - 1, fast_pow(pi.first - 1, M-2), M),
              M);
    return res;
}

int main() {
    ll n;
    cin >> n;
    vector<pair<ll, ll>> primes(n, make_pair(0, 0));
    bool all_even = true;
    for (auto &i : primes){
        cin >> i.first >> i.second;
        if (i.second % 2 == 1)
            all_even = false;
    }
    cout << num_divisores(primes) << " ";
    cout << sum_divisores(primes) << " ";
    cout << prod_divisores(primes, all_even) << endl;
}
