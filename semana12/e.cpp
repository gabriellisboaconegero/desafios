#include <bits/stdc++.h>
using namespace std;

bool friends(string a, string b){
    if (a.size() > b.size())
        return 0;
    int dist = 0;
    if (a.size() == b.size()){
        for (int i = 0; i < int(a.size()); i++){
            dist += a[i] != b[i];
            if (dist > 1)
                return false;
        }
        return true;
    }
    if (b.size() - a.size() > 1)
        return false;
    int j = 0;
    for (int i = 0; i < int(a.size()); i++, j++){
        dist += a[i] != b[j];
        if (a[i] != b[j])
            i--;
        if (dist > 1)
            return false;
    }
    return true;
}

int main(){
    int n;
    cin >> n;
    map<string, int> res;
    vector<pair<string, vector<int>>> v(n);
    for (int i = 0; i < n; i++){
        cin >> v[i].first;
        res.insert(make_pair(v[i].first, i));
    }

    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            if (i == j) continue;
            if (friends(v[i].first, v[j].first))
                v[i].second.push_back(j);
        }
    }

    for (auto [s, i] : res){
        cout << s << ": ";
        if (v[i].second.size() > 0){
            sort(v[i].second.begin(), v[i].second.end(), [&v](int a, int b){
                return v[a].first < v[b].first;
            });
            for (auto fri_id : v[i].second){
                cout << v[fri_id].first << " ";
            }
            cout << endl;
        }else{
            cout << "nenhum melhor amigo" << endl;
        }
    }
}
