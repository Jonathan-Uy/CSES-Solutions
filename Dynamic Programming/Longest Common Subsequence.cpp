#include <bits/stdc++.h>

using namespace std;
const int maxN = 1e3+1;

int N, M, a[maxN], b[maxN];
int len[maxN][maxN];
char ptr[maxN][maxN];

int main(){
    scanf("%d %d", &N, &M);
    for(int i = 1; i <= N; i++) scanf("%d", &a[i]);
    for(int i = 1; i <= M; i++) scanf("%d", &b[i]);

    for(int i = 1; i <= N; i++){
        for(int j = 1; j <= M; j++){
            if(len[i][j] <= len[i-1][j]){
                len[i][j] = len[i-1][j];
                ptr[i][j] = 'L';
            }
            if(len[i][j] <= len[i][j-1]){
                len[i][j] = len[i][j-1];
                ptr[i][j] = 'U';
            }
            if(a[i] == b[j] && len[i][j] <= len[i-1][j-1] + 1){
                len[i][j] = len[i-1][j-1] + 1;
                ptr[i][j] = 'D';
            }
        }
    }

    vector<int> ans;
    int i = N, j = M;
    while(i != 0 && j != 0){
        char dir = ptr[i][j];

        if(dir == 'L')      i--;
        else if(dir == 'U') j--;
        else if(dir == 'D'){
            ans.push_back(a[i]);
            i--; j--;
        }
    }
    reverse(ans.begin(), ans.end());

    int l = len[N][M];
    printf("%d\n", l);
    for(int i = 0; i < l; i++)
        printf("%d%c", ans[i], (" \n")[i==l-1]);
}