#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll f(vector<ll> &v, ll x){
	ll sum = 0;
	for (auto i : v)
		sum += abs(i - x);
	return sum;
}

int main(){
	cin.tie(0);
	ios_base::sync_with_stdio(0);

	ll n;
	cin >> n;

	//le n strings
	vector<ll> v(n);
	for(auto &x : v) cin >> x;

	//ordena o vetor de forma que a concatenação dos elementos tenha a menor ordem lexicográfica
	sort(v.begin(), v.end());
	ll median = v[n/2];

	cout << f(v, median) << endl;
	return 0;
}
