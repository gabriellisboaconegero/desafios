#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main(){
    ll t;
    cin >> t;
    while (t--){
        ll p, h, f, d, c;
        cin >> p >> h >> f >> d >> c;
        p = p/2;

        ll m = min(p, h);
        ll m1 = m*d + min(f, (p-m))*c;
        m = min(p, f);
        ll m2 = m*c + min(h, (p-m))*d;
        cout << max(m1, m2) << endl;
    }
    return 0;
}
