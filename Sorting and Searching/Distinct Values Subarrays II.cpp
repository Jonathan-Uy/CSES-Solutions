#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const int maxN = 2e5+5;

int N, K, x[maxN];
map<int,int> freq;
ll ans;

int main(){
    scanf("%d %d", &N, &K);
    for(int i = 1; i <= N; i++)
        scanf("%d", &x[i]);

    int unique = 0;
    int r = 0;
    for(int l = 1; l <= N; l++){
        while(r < N && (freq[x[r+1]] >= 1 || unique < K)){
            r++;
            freq[x[r]]++;
            if(freq[x[r]] == 1)
                unique++;
        }

        ans += (r-l+1);

        freq[x[l]]--;
        if(!freq[x[l]])
            unique--;
    }

    printf("%lld\n", ans);
}
