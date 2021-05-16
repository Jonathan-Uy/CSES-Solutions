#include <bits/stdc++.h>

using namespace std;
const int maxX = 1e6;

int N, a, cnt, d[maxX+1];

int main(){
    scanf("%d", &N);
    for(int i = 0; i < N; i++){
        scanf("%d", &a);
        d[a]++;
    }
    for(int i = maxX; i >= 1; i--){
        cnt = 0;
        for(int j = i; j <= maxX; j += i)
            cnt += d[j];
        if(cnt >= 2){
            printf("%d\n", i);
            return 0;
        }
    }
}
