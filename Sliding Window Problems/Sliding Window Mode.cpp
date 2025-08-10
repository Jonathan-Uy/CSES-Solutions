#include <bits/stdc++.h>

using namespace std;
const int maxN = 2e5;

int N, K, best_freq, best_val, a[maxN];
unordered_map<int,int> freqs;
unordered_map<int,set<int>> vals;

int main(){
    scanf("%d %d", &N, &K);
    for(int i = 0; i < N; i++)
        scanf("%d", &a[i]);

    for(int i = 0; i < K; i++)
        freqs[a[i]]++;

    for(int i = 0; i < K; i++){
        vals[freqs[a[i]]].insert(a[i]);
        if(freqs[a[i]] > best_freq || (freqs[a[i]] == best_freq && a[i] < best_val)){
            best_freq = freqs[a[i]];
            best_val = a[i];
        }
    }

    printf("%d%c", best_val, (" \n")[N==K]);
    for(int i = K; i < N; i++){
        vals[freqs[a[i-K]]].erase(a[i-K]);
        vals[--freqs[a[i-K]]].insert(a[i-K]);
        if(best_val == a[i-K]){
            for(int f = freqs[a[i-K]]+1; f > 0; f--){
                if(!vals[f].empty()){
                    best_freq = f;
                    best_val = *vals[f].begin();
                    break;
                }
            }
        }

        vals[freqs[a[i]]].erase(a[i]);
        vals[++freqs[a[i]]].insert(a[i]);
        if(freqs[a[i]] > best_freq || (freqs[a[i]] == best_freq && a[i] < best_val)){
            best_freq = freqs[a[i]];
            best_val = a[i];
        }

        printf("%d%c", best_val, (" \n")[i==N]);
    }
}