#include <bits/stdc++.h>
using namespace std;
#define ll long long

int aply_ops(int ops, int n, vector<int> v){
    int ors = v[0];
    int xors = 0;
    for (int i = 0; i < n-1; i++){
        // case |
        if (!((ops>>i)&1))
            ors |= v[i+1];
        // case ^
        else{
            xors ^= ors;
            ors = v[i+1];
        }
        /* 0 := | */
        /* 1 := ^ */
        /* 1|5|7^6^8|5|6^7|8|9 */
        /* 0 0 1 1 0 0 1 0 0 */
    }
    xors ^= ors;
    return xors;
}

int main(){
    int n;
    cin >> n;
    vector<bool> ops(n-1);
    vector<int> v(n);
    int m = numeric_limits<int>::max();
    for (auto &i : v) cin >> i;
    for (int i = 0; i < 1<<(n-1); i++)
        m = min(m, aply_ops(i, n, v));
    cout << m << endl;
}
