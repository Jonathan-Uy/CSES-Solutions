#include <bits/stdc++.h>

using namespace std;
typedef pair<int,int> pii;
const int maxN = 105;

char S[maxN];
bool used[maxN], inZ[2][maxN];
int N, cnt, mt[maxN];
vector<int> G[maxN];

bool kuhns(int u){
    if(used[u]) return false;

    used[u] = true;
    for(int v : G[u]){
        if(!mt[v] || kuhns(mt[v])){
            mt[v] = u;
            return true;
        }
    }

    return false;
}

void dfs(int t, int u){
    inZ[t][u] = true;
    if(t == 0 && !inZ[1][mt[u]]){
        dfs(1, mt[u]);
    } else if(t == 1){
        for(int v : G[u])
            if(!inZ[0][v])
                dfs(0, v);
    }
}

int main(){
    scanf("%d", &N);
    for(int i = 1; i <= N; i++){
        scanf(" %s", S);
        for(int j = 1; j <= N; j++)
            if(S[j-1] == 'o')
                G[j].push_back(i);
    }

    for(int i = 1; i <= N; i++){
        kuhns(i);
        fill(used+1, used+N+1, false);
    }

    cnt = 0;
    for(int i = 1; i <= N; i++){
        if(mt[i]){
            cnt++;
            used[mt[i]] = true;
        }
    }

    for(int i = 1; i <= N; i++)
        if(!used[i])
            dfs(1, i);

    printf("%d\n", cnt);
    for(int i = 1; i <= N; i++)
        if(inZ[0][i])
            printf("1 %d\n", i);
    for(int i = 1; i <= N; i++)
        if(!inZ[1][i])
            printf("2 %d\n", i);
}