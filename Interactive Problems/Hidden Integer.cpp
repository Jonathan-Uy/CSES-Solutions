#include <bits/stdc++.h>

using namespace std;
const int maxX = 1e9;

int main(){
    string result;
    int l = 0, r = maxX + 1;
    while(l + 1 < r){
        int m = l + (r-l) / 2;

        cout << "? " << m << endl;
        cin >> result;

        if(result == "YES") l = m;
        else                r = m;
    }

    cout << "! " << l+1 << endl;
}