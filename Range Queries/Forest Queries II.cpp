#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const int maxN = 1000;

int N, Q;
char c[maxN+1][maxN+1];
ll ds[maxN+1][maxN+1];

void update(int x, int y, ll val){
    for(int i = x; i <= N; i += -i&i)
        for(int j = y; j <= N; j += -j&j)
            ds[i][j] += val;
}

ll query(int x, int y){
    ll sum = 0;
    for(int i = x; i > 0; i -= -i&i)
        for(int j = y; j > 0; j -= -j&j)
            sum += ds[i][j];
    return sum;
}

int main(){
    scanf("%d %d", &N, &Q);
    for(int i = 1; i <= N; i++){
        for(int j = 1; j <= N; j++){
            scanf(" %c", &c[i][j]);
            if(c[i][j] == '*')
                update(i, j, 1);
        }
    }
    for(int q = 0, t, x1, y1, x2, y2; q < Q; q++){
        scanf("%d %d %d", &t, &x1, &y1);
        if(t == 1){
            if(c[x1][y1] == '*'){
                update(x1, y1, -1);
                c[x1][y1] = '.';
            } else if(c[x1][y1] == '.'){
                update(x1, y1, 1);
                c[x1][y1] = '*';
            }
        } else if(t == 2){
            scanf("%d %d", &x2, &y2);
            printf("%lld\n", query(x2, y2)-query(x2,y1-1)-query(x1-1,y2)+query(x1-1,y1-1));
        }
    }
}
