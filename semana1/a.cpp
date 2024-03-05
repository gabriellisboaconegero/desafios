#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    string a, b;
    cin >> n;
    while(n--){
        cin >> a >> b;
        cout << (!(a.back()%2 ^ b.back()%2) ? "PARCEIROS" : "NAO PARCEIROS") << endl;
    }
}
