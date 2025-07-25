#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const int maxN = 1e6+1;

int N, idx, ans[maxN];
ll K;
deque<int> DQ;

int main(){
    scanf("%d %lld", &N, &K);
    for(int i = 1; i <= N; i++)
        DQ.push_back(i);

    for(int k = N-1; k >= 0; k--){
        if(k <= K){
            ans[++idx] = DQ.back();
            DQ.pop_back();
            K -= k;
        } else {
            ans[++idx] = DQ.front();
            DQ.pop_front();
        }
    }

    for(int i = 1; i <= idx; i++)
        printf("%d%c", ans[i], (" \n")[i==idx]);
}