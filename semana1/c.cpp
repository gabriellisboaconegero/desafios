#include <bits/stdc++.h>
using namespace std;

int main() {
    string c, h, m;
    while(cin >> c >> h >> m){
        // int index = (c[2]-'0')*1000 + (c[3]-'0')*100 + (c[4]-'0')*10 + c[5]-'0';
        int minutos = 0;
        for (auto c : m)
            minutos = minutos*10 + c-'0';
        int x = 60;
        for (int i = h.size()-1; i >= 0; i--){
            minutos += (h[i]-'0')*x;
            x*=10;
        }
        cout << "Abel deve " << ((minutos > 10*60) ? "cancelar" : "cursar") << " " << c << endl;
    }
}
