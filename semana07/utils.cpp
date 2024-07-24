#include <bits/stdc++.h>
using namespace std;
#define ll long long

// O(sqrt(n))
bool is_prime(ll n){
    if (n == 1 || n%2 == 0)
        return false;
    if (n == 2)
        return true;
    for (ll i = 3; i*i <= n; i+=2)
        if (n%i == 0)
            return false;
    return true;
}

void crivo_erastotenes(vector<bool> &crivo, ll n){
    for (ll i = 2; i * i <= n; i++)
        if (crivo[i])
            for (ll j = i*i; j <= n; j+= i)
                crivo[j] = false;
}