#include <bits/stdc++.h>

using namespace std;
typedef pair<int,int> pii;
const int maxN = 2e5+1;
const int INF = 0x3f3f3f3f;

int N, dp[maxN];
vector<int> tallers;
vector<pii> mountains;
set<int,greater<int>> S_l;
set<int> S_r;

int main(){
    scanf("%d", &N);

    for(int i = 1, h; i <= N; i++){
        scanf("%d", &h);
        mountains.push_back({h, i});
    }
    sort(mountains.begin(), mountains.end(), greater<pii>());

    int last_height = INF;
    for(pii m : mountains){
        int h = m.first, i = m.second;

        if(last_height != h){
            for(int t : tallers){
                S_l.insert(t);
                S_r.insert(t);
            }
            tallers.clear();
        }

        auto l_ptr = S_l.lower_bound(i);
        auto r_ptr = S_r.lower_bound(i);
        int l = (l_ptr == S_l.end() ? 0 : *l_ptr);
        int r = (r_ptr == S_r.end() ? 0 : *r_ptr);
        dp[i] = max(dp[l], dp[r]) + 1;

        tallers.push_back(i);
        last_height = h;
    }

    int best = 0;
    for(int i = 1; i <= N; i++)
        best = max(best, dp[i]);
    printf("%d\n", best);
}