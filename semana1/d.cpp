#include <bits/stdc++.h>
using namespace std;

#define ll long long int

int main() {
    ll n, num, m, c = 0;
    cin >> n;
    cin >> m;
    while(--n){
        cin >> num;
        if (num <= m)
            c += m-num;
        else
            m = num;
    }

    cout << c << endl;
}
