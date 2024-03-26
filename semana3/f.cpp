#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main(){
    ll n;
    cin >> n;
    vector<ll> v(n);
    for (auto &i : v) cin >> i;

    sort(v.begin(), v.end());

    int change_idx = -1;
    for (int i = 1; i < n-1; i+=2){
        if (v[i]/v[i-1] != v[i+1]/v[i])
            change_idx = i;
    }

    ll r;
    if (change_idx != -1){
        r = min(v[change_idx]/v[change_idx-1], v[change_idx+1]/v[change_idx]);
        int id_wrong = v[change_idx]/v[change_idx-1] > v[change_idx+1]/v[change_idx] ? change_idx-1 : change_idx;
        cout << v[id_wrong]*r << endl;
    } else {
        r = v[1]/v[0];
        if (v[0]%r == 0 && r != 1)
            cout << v[0]/r << endl;
        cout << v.back()*r << endl;
    }

    return 0;
}