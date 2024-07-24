#include <bits/stdc++.h>
using namespace std;
#define ll int

int main() {
    ll n, k, c;
    cin >> n >> k >> c;

    vector<ll> v(n);
    for (auto &i : v)
        cin >> i;

    vector<vector<ll>> dp(n+c, vector<ll>(k+1, 0));

    for (ll i = n-1; i >= 0; i--){
        for (ll j = 0; j <= k; j++){
            if (j == 0){
                dp[i][j] = dp[i+1][j] + v[i];
            }else if (n-i <= j*c){
                if (n-i == j*c)
                    dp[i][j] = 0;
                continue;
            }else{
                dp[i][j] = max(v[i]+dp[i+1][j], dp[i+c][j-1]);
            }
        }
    }

    cout << dp[0][k] << endl;
}
