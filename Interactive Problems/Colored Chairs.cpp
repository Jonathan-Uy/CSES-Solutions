#include <bits/stdc++.h>

using namespace std;

int N;

char query(int i){
    cout << "? " << ((i - 1) % N) + 1 << endl;
    char c;
    cin >> c;
    return c;
}

int main(){
    cin >> N;

    int l = 1, r = N+1;
    char l_color = query(l);
    char r_color = l_color;

    while(l+1 < r){
        int m = (l + r) / 2;
        char m_color = query(m);

        bool left_good = ((m - l) % 2 == 0) ^ (m_color == l_color);

        if(left_good){
            r = m;
            r_color = m_color;
        } else {
            l = m;
            l_color = m_color;
        }
    }

    cout << "! " << l << endl;
}