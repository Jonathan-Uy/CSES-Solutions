#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const int maxN = 5005, K = 26;
const ll MOD = 1e9+7;

struct Node {
    int next[K];
    bool leaf = false;
    Node(){ fill(next, next+K, -1); }
};

int N, M;
ll dp[maxN];
char S[maxN], word[maxN];
vector<Node> trie(1);

void add_word(){
    scanf(" %s", word);
    int v = 0;
    M = (int) strlen(word);
    for(int i = 0; i < M; i++){
        int c = (int) (word[i] - 'a');
        if(trie[v].next[c] == -1){
            trie[v].next[c] = trie.size();
            trie.emplace_back();
        }
        v = trie[v].next[c];
    }
    trie[v].leaf = true;
}

int main(){
    scanf(" %s %d", S, &N);
    for(int i = 0; i < N; i++)
        add_word();

    M = (int) strlen(S);
    dp[M] = 1;
    for(int i = M-1; i >= 0; i--){
        int v = 0;
        for(int j = i; j < M; j++){
            int c = (int) (S[j] - 'a');
            if(trie[v].next[c] == -1)   break;
            v = trie[v].next[c];

            if(trie[v].leaf)
                dp[i] = (dp[i] + dp[j+1]) % MOD;
        }
    }
    printf("%lld\n", dp[0]);
}