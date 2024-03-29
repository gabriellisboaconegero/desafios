#include <bits/stdc++.h>
using namespace std;
#define ll long long

ll n;
ll gen(vector<ll> &v, int k, ll acc1, ll acc2){
    if (k == n)
        return abs(acc1-acc2);
    
    return min(gen(v, k+1, acc1+v[k], acc2-v[k]), gen(v, k+1, acc1, acc2));
}

int main(){
    cin >> n;
    vector<ll> v(n);
    ll sum = 0;
    for (auto &i : v){
        cin >> i;
        sum += i;
    }

    cout << gen(v, 1, v[0], sum+v[0]) << endl;
    return 0;
}
