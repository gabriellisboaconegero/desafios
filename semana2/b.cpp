#include <bits/stdc++.h>
using namespace std;

#define ll long long int
#define altura first
#define dir second

int main() {
    stack<pair<int, char>> s;
    int n, A;
    char D;
    pair<int, char> t;
    cin >> n;
    while (n--){
        cin >> A >> D;
        if (s.empty()){
            s.push(make_pair(A, D));
            if (D == 'O')
                break;
            continue;
        }

        t = s.top();
        if (A > t.altura || (t.altura == A && t.dir == D))
            break;
        else if (t.altura == A && t.dir == 'L' && D == 'O')
            s.pop();
        else
            s.push(make_pair(A, D));

    }
    if (s.empty())
        cout << "S" << endl;
    else
        cout << "N" << endl;

    return 0;
}
