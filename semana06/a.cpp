#include <bits/stdc++.h>
using namespace std;
#define ll long long

ll swaps = 0;
void merge_sort(ll l, ll u, vector<ll> &a){
    if (u - l <= 1) return;
    ll mi = l + (u - l)/2;
    merge_sort(l, mi, a);
    merge_sort(mi, u, a);
    vector<ll> aux(u - l);
    ll i = l, j = mi;
    for (ll k = 0; k < u - l; k++){
        if (i < mi && j < u){
            if (a[i] >= a[j])
                swaps += mi - i;
            if (a[i] < a[j])
                aux[k] = a[i++];
            else
                aux[k] = a[j++];
        } else if (i < mi)
            aux[k] = a[i++];
        else
            aux[k] = a[j++];
    }
    copy(aux.begin(), aux.end(), a.begin()+l);
}

int main() {
    ll n, h;
    cin >> n >> h;

    vector<ll> v(n);
    vector<ll> c(h);

    for (ll i = 0; i < h; i++){
        cin >> v[i];
        c[i] = v[i];
    }
    for (ll i = h; i < n; i++)
        cin >> v[i];

    swaps = 0;
    merge_sort(0, h, c);
    /* for (auto &i : c) */
    /*     cout << i << " "; */
    /* cout << endl; */
    ll s = swaps;
    swaps = 0;
    merge_sort(0, n, v);
    /* for (auto &i : v) */
    /*     cout << i << " "; */
    /* cout << endl; */
    cout << swaps - s << endl;
}
