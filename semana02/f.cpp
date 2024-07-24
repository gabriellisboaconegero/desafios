#include <bits/stdc++.h>
using namespace std;

#define ll long long int

int main() {
    list<ll> l;
    auto pos = l.end();
    ll t, q, num;
    cin >> t;
    char op;
    while (t--){
        cin >> op;
        switch (op){
            case 'i':
                cin >> q >> num;
                pos = l.insert(pos, q, num);
                break;
            case 'm':
                cin >> num;
                advance(pos, num);
                break;
            case 'd':
                pos = l.erase(pos);
                break;
            case 'q':
                cout << *pos << endl;
        }
    }
    return 0;
}
