#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main(){
    ll n;
    cin >> n;
    vector<ll> v(n);
    for (auto &i : v) cin >> i;
    map<ll, ll> eq1;
    map<ll, ll> eq2;

    for (int i : v){
        for (int j : v){
            for (int k : v){
                const auto &[it1, inserted1] = eq1.emplace(i*j+k, 1);
                if (!inserted1)
                    it1->second++;
                if (i != 0){
                    const auto &[it2, inserted2] = eq2.emplace(i*(j+k), 1);
                    if (!inserted2)
                        it2->second++;
                }
            }
        }
    }

    auto f1 = eq1.begin();
    auto f2 = eq2.begin();
    ll sum = 0;
    while(f1 != eq1.end() && f2 != eq2.end()){
        if (f1->first < f2->first) f1++;
        else if (f1->first > f2->first) f2++;
        else {
            sum += f1->second * f2->second;
            f1++;
            f2++;
        }
    }
    /* for (auto &i : eq1) */
    /*     cout << i.first << ": " << i.second << endl; */
    /* cout << endl; */
    /* for (auto &i : eq2) */
    /*     cout << i.first << ": " << i.second << endl; */
    /* cout << endl; */
    cout << sum << endl;

}
