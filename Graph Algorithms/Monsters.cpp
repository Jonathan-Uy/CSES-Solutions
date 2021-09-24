#include <bits/stdc++.h>

using namespace std;
const int maxN = 1000;
const int INF = 0x3f3f3f3f;

int h[] = {1, -1, 0, 0};
int v[] = {0, 0, 1, -1};
struct point { int x, y; };

int N, M, sx, sy;
bool vis[maxN][maxN];
char ans[maxN*maxN], c[maxN][maxN], p[maxN][maxN];
int d1[maxN][maxN], d2[maxN][maxN];
queue<point> Q;

bool inbounds(int x, int y){
    return 0 <= x && x < N && 0 <= y && y < M;
}

void printsolution(int x, int y){
    int D = d2[x][y];
    printf("YES\n%d\n", D);
    for(int i = D-1; i >= 0; i--){
        ans[i] = p[x][y];
        if(ans[i] == 'D')       x--;
        else if(ans[i] == 'U')  x++;
        else if(ans[i] == 'R')  y--;
        else if(ans[i] == 'L')  y++;
    }
    for(int i = 0; i < D; i++)
        printf("%c", ans[i]);
    printf("\n");
}

int main(){
    scanf("%d %d", &N, &M);
    for(int i = 0; i < N; i++){
        for(int j = 0; j < M; j++){
            scanf(" %c", &c[i][j]);
            if(c[i][j] == '#')  vis[i][j] = true;
            else if(c[i][j] == 'M'){
                vis[i][j] = true;
                Q.push({i, j});
            } else if(c[i][j] == 'A'){
                sx = i; sy = j;
            }
        }
    }

    while(!Q.empty()){
        point P = Q.front(); Q.pop();
        for(int i = 0; i < 4; i++){
            int x = P.x + h[i];
            int y = P.y + v[i];
            if(inbounds(x, y) && !vis[x][y]){
                d1[x][y] = d1[P.x][P.y] + 1;
                vis[x][y] = true;
                Q.push({x, y});
            }
        }
    }

    for(int i = 0; i < N; i++){
        for(int j = 0; j < M; j++){
            if(!vis[i][j])  d1[i][j] = INF;
            vis[i][j] = (c[i][j] == '#');
        }
    }

    vis[sx][sy] = true;
    Q.push({sx, sy});
    while(!Q.empty()){
        point P = Q.front(); Q.pop();
        for(int i = 0; i < 4; i++){
            int x = P.x + h[i];
            int y = P.y + v[i];
            if(inbounds(x, y) && !vis[x][y] && d2[P.x][P.y]+1 < d1[x][y]){
                if(i == 0)      p[x][y] = 'D';
                else if(i == 1) p[x][y] = 'U';
                else if(i == 2) p[x][y] = 'R';
                else if(i == 3) p[x][y] = 'L';
                d2[x][y] = d2[P.x][P.y] + 1;
                vis[x][y] = true;
                Q.push({x, y});
            }
        }
    }

    for(int i = 0; i < N; i++){
        if(c[i][0] != '#' && c[i][0] != 'M' && vis[i][0]){
            printsolution(i, 0);
            return 0;
        } else if(c[i][M-1] != '#' && c[i][M-1] != 'M' && vis[i][M-1]){
            printsolution(i, M-1);
            return 0;
        }
    }

    for(int i = 0; i < M; i++){
        if(c[0][i] != '#' && c[0][i] != 'M' && vis[0][i]){
            printsolution(0, i);
            return 0;
        } else if(c[N-1][i] != '#' && c[N-1][i] != 'M' && vis[N-1][i]){
            printsolution(N-1, i);
            return 0;
        }
    }

    printf("NO\n");
}
