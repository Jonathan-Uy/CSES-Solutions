#include <bits/stdc++.h>

using namespace std;

const int N = 9;
const int x[] = {0, 1, 2, 3, 4, 5, 1, 2, 4, 5, 7, 8};
const int y[] = {3, 4, 5, 6, 7, 8, 0, 1, 3, 4, 6, 7};

unordered_map<string,int> dist;
queue<string> Q;
string perm;

void init(){
    perm = "123456789";

    dist[perm] = 1;
    Q.push(perm);
    while(!Q.empty()){
        perm = Q.front(); Q.pop();
        int d = dist[perm];
        for(int i = 0; i < 12; i++){
            swap(perm[x[i]], perm[y[i]]);
            if(!dist[perm]){
                dist[perm] = d+1;
                Q.push(perm);
            }
            swap(perm[x[i]], perm[y[i]]);
        }
    }
}

int main(){
    init();
    for(int i = 0; i < N; i++)
        scanf(" %c", &perm[i]);
    printf("%d\n", dist[perm]-1);
}
