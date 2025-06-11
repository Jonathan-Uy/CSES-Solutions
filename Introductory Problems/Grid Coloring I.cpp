#include <bits/stdc++.h>

using namespace std;

int N, M;

const char cs[2][2] = {{'A', 'B'}, {'C', 'D'}};

int main(){
    scanf("%d %d", &N, &M);
    for(int i = 0; i < N; i++){
        for(int j = 0; j < M; j++){
            char c;
            scanf(" %c", &c);

            bool odd = (i+j)&1;
            bool small = c < 'C';
            printf("%c", cs[small][odd]);
        }
        printf("\n");
    }
}