#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main() {
    ll n;
    cin >> n;
    vector<ll> A(n), B(n), C(n);
    vector<ll> a(n), b(n), c(n);

    for (ll i = 0; i < n; i++)
        cin >> A[i] >> B[i] >> C[i];

    a[n-1] = A[n-1];
    b[n-1] = B[n-1];
    c[n-1] = C[n-1];

    for (ll i = n - 2; i >= 0; i--){
        a[i] = max(b[i+1], c[i+1]) + A[i];
        b[i] = max(a[i+1], c[i+1]) + B[i];
        c[i] = max(b[i+1], a[i+1]) + C[i];
    }
    cout << max(a[0], max(b[0], c[0])) << endl;
}
