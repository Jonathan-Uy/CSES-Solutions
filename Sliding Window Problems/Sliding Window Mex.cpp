#include <bits/stdc++.h>

using namespace std;
const int maxN = 2e5;

int N, K, a[maxN];
set<int> mex_set;
unordered_map<int,int> freq;

int main(){
    scanf("%d %d", &N, &K);
    for(int i = 0; i < N; i++)
        scanf("%d", &a[i]);

    for(int i = 0; i <= N; i++)
        mex_set.insert(i);

    for(int i = 0; i < K; i++){
        freq[a[i]]++;
        if(freq[a[i]] == 1)
            mex_set.erase(a[i]);
    }

    printf("%d%c", *mex_set.begin(), (" \n")[N==K]);
    for(int i = K; i < N; i++) {
        freq[a[i-K]]--;
        if(freq[a[i-K]] == 0)
            mex_set.insert(a[i-K]);

        freq[a[i]]++;
        if(freq[a[i]] == 1)
            mex_set.erase(a[i]);

        printf("%d%c", *mex_set.begin(), (" \n")[i==N-1]);
    }
}