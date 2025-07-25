#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const int maxN = 2e5+1;

int N, M;
char S[maxN];
bool exists[26];
map<char,int> ch;
map<vector<int>,ll> dp;

bool containsEach(vector<int> V){
    for(int i = 0; i < (int) V.size(); i++)
        if(V[i] <= 0)
            return false;
    return true;
}

int main(){
    scanf(" %s", S);
    N = (int) strlen(S);
    for(int i = 0; i < N; i++){
        int c = (int) (S[i] - 'a');
        if(!exists[c]){
            ch[S[i]] = M++;
            exists[c] = true;
        }
    }

    ll ans = 0;
    vector<int> freq(M);
    dp[freq]++;
    for(int i = 0; i < N; i++){
        int c = ch[S[i]];
        freq[c]++;
        if(containsEach(freq))
            for(int j = 0; j < M; j++)
                freq[j]--;
        ans += dp[freq];
        dp[freq]++;
    }
    printf("%lld\n", ans);
}