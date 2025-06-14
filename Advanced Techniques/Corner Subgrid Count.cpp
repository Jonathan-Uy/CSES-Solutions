#include <bits/stdc++.h>
#pragma GCC target("popcnt")

using namespace std;
typedef long long ll;
const int maxN = 3005;

int N;
ll ans;
bitset<maxN> B[maxN];

int f(int X){
    return X*(X-1);
}

int main(){
    cin.sync_with_stdio(0);
    cin.tie(0);

    cin >> N;
    for(int i = 0; i < N; i++)
        cin >> B[i];

    for(int i = 0; i < N; i++)
        for(int j = i+1; j < N; j++)
            ans += f((B[i]&B[j]).count());

    cout << (ans>>1);
}
