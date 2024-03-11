#include <bits/stdc++.h>
using namespace std;

#define ll long long int

int main() {
    int n;
    cin >> n;

    vector<int> v(n), id(n);
    for (auto &i : v) cin >> i;
    iota(begin(id), end(id), 0);

    sort(begin(id), end(id), [&](int i, int j){
        return v[i] < v[j];
            });
    for (auto i : v) cout << i << " ";
    cout << endl;
    for (auto i : id) cout << i << " ";
    cout << endl;
    return 0;
}
