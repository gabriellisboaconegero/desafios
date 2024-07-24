#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main(){
    ll n, i;

    cin >> n;
    ll sum = 0;
    while(n--){
        cin >> i;
        sum += i > 10 ? i-10 : 0;
    }

    cout << sum << endl;

    return 0;
}
