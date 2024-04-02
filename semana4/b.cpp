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

    multiset<ll> m;
    for (auto p: v){
        m.insert(p.first);
        if (m.size() > p.second)
            m.erase(m.begin());
    }

    ll sum = 0;
    for (auto i: m)
        sum += i;
    cout << sum << endl;

	return 0;
}
