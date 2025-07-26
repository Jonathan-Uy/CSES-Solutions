#include <bits/stdc++.h>

using namespace std;
const int maxN = 2e5;

int N, K, x[maxN];
map<int,int> freq;

int main(){
    scanf("%d %d", &N, &K);
    for(int i = 0; i < N; i++)
        scanf("%d", &x[i]);

    int distinct = 0;
    for(int i = 0; i < K; i++){
        if(freq[x[i]] == 0)
            distinct++;
        freq[x[i]]++;
    }
    printf("%d%c", distinct, (" \n")[N==K]);

    for(int i = K; i < N; i++){
        if(freq[x[i-K]] == 1)
            distinct--;
        freq[x[i-K]]--;

        if(freq[x[i]] == 0)
            distinct++;
        freq[x[i]]++;

        printf("%d%c", distinct, (" \n")[i==N-1]);
    }
}