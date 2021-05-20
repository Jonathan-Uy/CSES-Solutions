#include <bits/stdc++.h>

using namespace std;
typedef array<int,3> triple;
const int N = 8;
const int h[] = {-2, -1, 1, 2, 2, 1, -1, -2};
const int v[] = {1, 2, 2, 1, -1, -2, -2, -1};

bool vis[N][N];
int ans[N][N], deg[N][N];

bool inBounds(int x, int y){
    return 0 <= x && x < N && 0 <= y && y < N;
}

void init(){
    for(int x = 0; x < N; x++){
        for(int y = 0; y < N; y++){
            for(int i = 0; i < N; i++){
                int dx = x + h[i];
                int dy = y + v[i];
                if(inBounds(dx, dy))
                    deg[x][y]++;
            }
        }
    }
}

void mark(int id, int x, int y){
    ans[x][y] = id;
    vis[x][y] = true;
    for(int i = 0; i < N; i++){
        int dx = x + h[i];
        int dy = y + v[i];
        if(inBounds(dx, dy) && !vis[dx][dy])
            deg[dx][dy]--;
    }
}

void unmark(int x, int y){
    ans[x][y] = -1;
    vis[x][y] = false;
    for(int i = 0; i < N; i++){
        int dx = x + h[i];
        int dy = y + v[i];
        if(inBounds(dx, dy) && !vis[dx][dy])
            deg[dx][dy]++;
    }
}

bool solve(int id, int x, int y){
    mark(id, x, y);
    if(id >= 64)    return true;

    vector<triple> options;
    for(int i = 0; i < N; i++){
        int dx = x + h[i];
        int dy = y + v[i];
        if(inBounds(dx, dy) && !vis[dx][dy])
            options.push_back({deg[dx][dy], dx, dy});
    }
    sort(options.begin(), options.end());

    for(triple T : options)
        if(solve(id+1, T[1], T[2]))
            return true;

    unmark(x, y);
    return false;
}

int main(){
    init();
    int x, y;
    scanf("%d %d", &x, &y);
    assert(solve(1, y-1, x-1));

    for(int i = 0; i < N; i++)
        for(int j = 0; j < N; j++)
            printf("%d%c", ans[i][j], (" \n")[j==N-1]);
}
