#include <bits/stdc++.h>

using namespace std;
const int maxN = 2e5;

set<int> S;
set<int>::iterator f, c, b;
int N, X, a, best, ans[maxN];
struct light {int pos, id;} x[maxN+2];

int main(){
    scanf("%d %d", &X, &N);
    x[0] = {0, 0}; x[N+1] = {X, 1};
    S.insert(0); S.insert(X);
    for(int i = 0; i < N; i++){
        scanf("%d", &a);
        x[i+1] = {a, i+2};
        S.insert(a);
    }

    sort(x, x+maxN+2, [](light A, light B){
        return A.pos < B.pos;
    });
    for(int i = 1; i <= maxN+1; i++)
        best = max(best, x[i].pos - x[i-1].pos);

    sort(x, x+maxN+2, [](light A, light B){
        return A.id > B.id;
    });
    for(int i = 0; i < N; i++){
        ans[N-i-1] = best;
        c = S.find(x[i].pos);
        f = next(c, 1);
        b = next(c, -1);
        best = max(best, *f - *b);
        S.erase(c);
    }

    for(int i = 0; i < N; i++)
        printf("%d%c", ans[i], (" \n")[i==N]);
}
