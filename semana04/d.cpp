#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main(){
    ll n;
    cin >> n;
    vector<string> v(n);
    for (auto &i : v) cin >> i;
    
    sort(v.begin(), v.end(), [&](string a, string b){
        string ab = a+b;
        string ba = b+a;
        return lexicographical_compare(ab.begin(), ab.end(), ba.begin(), ba.end());
    });
    string result;
    for (auto &i : v)
        result += i;
    cout << result << endl;
    return 0;
}
