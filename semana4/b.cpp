#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
	cin.tie(0);
	ios_base::sync_with_stdio(0);

	ll n;
	cin >> n;

	vector<pair<ll, ll>> v(n);
    for(auto &i : v) cin >> i.first >> i.second;
    
    sort(v.begin(), v.end(), [&](pair<ll,ll> a, pair<ll,ll> b){
        return a.second == b.second ? a.first > b.first : a.second < b.second;
    });

    ll sum = 0;
    ll prev = -1;
    for (auto i: v){
        if (prev != i.second)
            sum += i.first;
        prev = i.second;
    }

    cout << sum << endl;

	return 0;
}