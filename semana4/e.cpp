#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
	cin.tie(0);
	ios_base::sync_with_stdio(0);

	// X: 3
	// Y: 1
	// VERMELHA: 1 4 6 7
	// VERDE: 1 2 3 4
	// BRANCA: 1 2 3 4 5 6 7 8

	ll x, y, a, b, c;
	cin >> x >> y >> a >> b >> c;

	vector<ll> v_a(a), v_b(b), v_c(c);
	vector<ll> v_total(x+y);
	for (auto &i : v_a) cin >> i;
	for (auto &i : v_b) cin >> i;
	for (auto &i : v_c) cin >> i;

	sort(v_a.begin(), v_a.end(), greater<ll>());
	sort(v_b.begin(), v_b.end(), greater<ll>());
	sort(v_c.begin(), v_c.end(), greater<ll>());

	ll kx = 0, ky = 0;
	for (auto &i : v_total){
		if (kx >= x)
			i = v_b[ky++];
		else if (ky >= y)
			i = v_a[kx++];
		else
			i = v_a[kx] > v_b[ky] ? v_a[kx++] : v_b[ky++];
	}
	
	ll kc = 0;
	while(kc < c && v_c[kc] > v_total[x+y-1-kc]){
		v_total[x+y-1-kc] = v_c[kc];
		kc++;
	}

	ll sum = 0;
	for (auto i : v_total)
		sum += i;
	cout << sum << endl;

	return 0;
}