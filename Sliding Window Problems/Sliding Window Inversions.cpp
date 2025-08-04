#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const int maxN = 2e5+5;

int N, K, a[maxN], ds[maxN];

void update(int idx, int val){
    for(int i = idx; i <= N; i += -i&i)
        ds[i] += val;
}

int query(int idx){
    int sum = 0;
    for(int i = idx; i > 0; i -= -i&i)
        sum += ds[i];
    return sum;
}

void compress_vals(){
    vector<int> vals;
    for(int i = 0; i < N; i++)
        vals.push_back(a[i]);
    sort(vals.begin(), vals.end());

    unordered_map<int,int> mp;
    mp.reserve(N);
    for(int i = 0; i < N; i++)
        if(mp.find(vals[i]) == mp.end())
            mp[vals[i]] = i+1;

    for(int i = 0; i < N; i++)
        a[i] = mp[a[i]];
}

int main(){
    scanf("%d %d", &N, &K);
    for(int i = 0; i < N; i++)
        scanf("%d", &a[i]);
    compress_vals();

    ll inversions = 0;
    for(int i = 0; i < K; i++){
        inversions += i - query(a[i]);
        update(a[i], 1);
    }

    printf("%lld%c", inversions, (" \n")[K==N]);
    for(int i = K; i < N; i++){
        inversions -= query(a[i-K]-1);
        update(a[i-K], -1);

        inversions += (K-1) - query(a[i]);
        update(a[i], 1);

        printf("%lld%c", inversions, (" \n")[i==N-1]);
    }
}