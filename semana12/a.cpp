#include <bits/stdc++.h>
using namespace std;

vector<int> pre(string ne) {
    int n = ne.size();
    vector<int> pi (n, 0);
    for (int i = 1, j = 0; i < n; i++) {
        while (j > 0 && ne[i] != ne[j]) { j = pi[j-1]; }
        if (ne[i] == ne[j]) { j++; }
        pi[i] = j;
    }
    return pi;
}

int main(){
    string s;
    cin >> s;
    vector<int> p = pre(s);
    stack<int> res;
    int j = p.back();
    while(j > 0){
        res.push(j);
        j = p[j-1];
    }
    while(!res.empty()){
        cout << res.top() << " ";
        res.pop();
    }
    cout << endl;
}
