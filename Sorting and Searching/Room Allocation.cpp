#include <bits/stdc++.h>

using namespace std;
const int maxN = 2e5;

set<int> S;
int N, a, b, rooms, ans[maxN+1];
struct query {int type, time, id;} queries[2*maxN];

int main(){
    scanf("%d", &N);
    for(int i = 0; i < N; i++){
        S.insert(i+1);
        scanf("%d %d", &a, &b);
        queries[2*i] = {0, a, i+1};
        queries[2*i+1] = {1, b, i+1};
    }

    sort(queries, queries+2*N, [](query A, query B){
        if(A.id == B.id)    return A.type < B.type;
        return A.time == B.time ? A.type < B.type : A.time < B.time;
    });

    for(int i = 0; i < 2*N; i++){
        if(queries[i].type == 0){
            ans[queries[i].id] = *S.begin();
            S.erase(S.begin());
        } else if(queries[i].type == 1){
            S.insert(ans[queries[i].id]);
        }
    }

    for(int i = 1; i <= N; i++)
        rooms = max(rooms, ans[i]);

    printf("%d\n", rooms);
    for(int i = 1; i <= N; i++)
        printf("%d%c", ans[i], (" \n")[i==N]);
}
