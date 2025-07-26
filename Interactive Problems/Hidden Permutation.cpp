#include <bits/stdc++.h>

using namespace std;
const int maxN = 1001;

int N, ans[maxN];
string result;
vector<int> inv;

int binsearch(int i, int l, int r){
    if(l == r)  return l-1;

    int m = l + (r-l) / 2;
    cout << "? " << i << " " << inv[m-1] << endl;
    cin >> result;

    if(result == "YES") return binsearch(i, l, m);
    else                return binsearch(i, m+1, r);
}

int main(){
    cin >> N;

    if(N == 1){
        cout << "! 1" << endl;
        return 0;
    }

    inv.push_back(1);
    for(int i = 2; i <= N; i++){
        int pos = binsearch(i, 1, i);
        inv.emplace(inv.begin() + pos, i);
    }

    for(int i = 1; i <= N; i++)
        ans[inv[i-1]] = i;

    cout << "! ";
    for(int i = 1; i < N; i++)
        cout << ans[i] << " ";
    cout << ans[N] << endl;
}