#include <bits/stdc++.h>
using namespace std;

#define ll long long int

int main() {
    int a, b, c;
    cin >> a >> b >> c;
    int ma, mb, mc;
    if (a >= b && a >= c){
        ma = a;
        if (b >= c){
            mb = b;
            mc = c;
        }else{
            mb = c;
            mc = b;
        }
    }
    if (b >= a && b >= c){
        ma = b;
        if (a >= c){
            mb = a;
            mc = c;
        }else{
            mb = c;
            mc = a;
        }
    }
    if (c >= a && c >= b){
        ma = c;
        if (a >= b){
            mb = a;
            mc = b;
        }else{
            mb = b;
            mc = a;
        }
    }
    if (ma == 0 || mb == 0 || mb == 1)
        cout <<  mc - ma - mb << endl;
    else
        cout <<  mc - ma*mb << endl;
    return 0;
}
