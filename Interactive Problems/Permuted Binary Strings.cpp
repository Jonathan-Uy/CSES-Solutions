#include <bits/stdc++.h>

using namespace std;
const int maxSize = 1024;

int N, ans[maxSize];
string response;

int main(){
    cin >> N;
    for(int i = 1; (1<<(i-1)) < N; i++){
        cout << "? ";
        for(int j = 0; j < N; j++)
            cout << (bool) (j & (1<<(i-1)));
        cout << endl;

        cin >> response;
        for(int j = 0; j < N; j++)
            if(response[j] == '1')
                ans[j] += (1<<(i-1));
    }

    cout << "! ";
    for(int i = 0; i < N; i++)
        cout << ans[i] + 1 << (i == N-1 ? "" : " ");
    cout << endl;
}