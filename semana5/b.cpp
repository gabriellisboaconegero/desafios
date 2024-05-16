#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main() {
    ll n;
    ll v[5] = {1, 5, 10, 25, 50};
    vector<vector<ll>> dp(5, vector<ll>(3*14321, 1));

    for (ll i = 1; i < 5; i++){
        for (ll j = 0; j < 3*14321; j++){
            dp[i][j] = dp[i-1][j];
            if (j-v[i] >= 0)
                dp[i][j] += dp[i][j-v[i]];
        }
    }
    while(cin >> n){
        cout << dp[4][n] << endl;
    }
}
