#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define number_of_divisors(a, b, n) ((b)/(n)-(a-1)/(n))

ll n, a, b;
ll sieve(vector<ll> &v, ll i, ll d, ll sign){
    if (i == n){
        return -sign*number_of_divisors(a, b, d);
    }
    ll r = sieve(v, i+1, d, sign);
    r += sieve(v, i+1, d*v[i], sign*-1);
    return r;
    
}

int main(){
    cin >> a >> b >> n;
    vector<ll> v(n);

    ll inter = b-a+1;
    for (auto &i : v) cin >> i;
    cout << -sieve(v, 0, 1, 1) << endl;
}
