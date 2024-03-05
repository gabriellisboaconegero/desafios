#include <bits/stdc++.h>
using namespace std;

#define ll long long int

int main() {
    int v[26] = {0};
    string s;
    string f;
    cin >> s;
    for (auto c : s)
        v[c-'A']++;
    char middle = '\0';
    for (int i = 0; i < 26; i++){
        int freq = v[i];
        if (freq % 2 == 0){
            for (int j = 0; j < freq/2; j++)
                f.push_back((char)(i+'A'));
        }else if (middle == '\0'){
            middle = (char)(i+'A');
            for (int j = 0; j < freq/2; j++)
                f.push_back((char)(i+'A'));
        }else{
            cout << "NO SOLUTION" << endl;
            return 0;
        }
    }
    cout << f;
    if (middle != '\0')
        cout << middle;
    for_each(f.rbegin(), f.rend(), [](const char c){cout << c;});
    cout << endl;
    return 0;
}
