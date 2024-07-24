#include <bits/stdc++.h>
using namespace std;

#define ll long long int

int main() {
    queue<int> q;
    stack<int> s;
    priority_queue<int> pq;
    bool is_q = true;
    bool is_s = true;
    bool is_pq = true;
    int n, op, age;
    cin >> n;
    while(n--){
        cin >> op >> age;
        if (!is_q && !is_s && !is_pq){
            cout << "unknown" << endl;
            return 0;
        }
            
        if (!op){
        // Insere
            if (is_q)
                q.push(age);
            if (is_s)
                s.push(age);
            if (is_pq)
                pq.push(age);
        }else{
        // Retira
            if (is_q){
                if (q.front() != age)
                    is_q = false;
                else
                    q.pop();
            }
            if (is_s){
                if (s.top() != age)
                    is_s = false;
                else
                    s.pop();
            }
            if (is_pq){
                if (pq.top() != age)
                    is_pq = false;
                else
                    pq.pop();
            }

        }
    }

    if (!(is_q ^ is_s ^ is_pq) || (is_q && is_s && is_pq))
        cout << "ambiguous" << endl;
    else if (is_q)
        cout << "fifo" << endl;
    else if (is_s)
        cout << "lifo" << endl;
    else if (is_pq)
        cout << "priority" << endl;

    return 0;
}
