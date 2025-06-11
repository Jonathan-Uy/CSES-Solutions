#include <bits/stdc++.h>

using namespace std;
typedef pair<int,int> pii;
const int maxN = 1e3+5;

const int M = 8;
const int h[M] = {2, 2, 1, -1, -2, -2, -1, 1};
const int v[M] = {-1, 1, 2, 2, 1, -1, -2, -2};

int N, dist[maxN][maxN];
bool vis[maxN][maxN];
queue<pii> Q;

bool in_bounds(int x, int y){
    return 0 <= x && x < N && 0 <= y && y < N;
}

int main(){
    scanf("%d", &N);

    Q.push({0, 0});
    vis[0][0] = true;
    while(!Q.empty()){
        pii P = Q.front();
        Q.pop();

        int x = P.first, y = P.second;
        for(int i = 0; i < M; i++){
            int dx = x + h[i], dy = y + v[i];
            if(in_bounds(dx, dy) && !vis[dx][dy]){
                dist[dx][dy] = dist[x][y] + 1;
                vis[dx][dy] = true;
                Q.push({dx, dy});
            }
        }
    }

    for(int i = 0; i < N; i++)
        for(int j = 0; j < N; j++)
            printf("%d%c", dist[i][j], (" \n")[j==N-1]);
}