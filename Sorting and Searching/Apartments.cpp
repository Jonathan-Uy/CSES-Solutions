#include <bits/stdc++.h>

using namespace std;
const int maxN = 2e5+1;

int N, M, K, a[maxN], b[maxN];

int main(){
    scanf("%d %d %d", &N, &M, &K);
    for(int i = 0; i < N; i++)  scanf("%d", &a[i]);
    for(int i = 0; i < M; i++)  scanf("%d", &b[i]);

    sort(a, a+N);
    sort(b, b+M);

    int cnt = 0;
    int aptr = 0, bptr = 0;
    while(aptr < N){
        while(bptr < M && b[bptr] < a[aptr]-K)  bptr++;
        if(bptr < M && a[aptr]-K <= b[bptr] && b[bptr] <= a[aptr]+K){
            cnt++;
            aptr++;
            bptr++;
        } else aptr++;
    }
    printf("%d\n", cnt);
}
