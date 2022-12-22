#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const int maxN = 1e5;

int N, a[2][maxN];

int main(){
    scanf("%d", &N);
    for(int r = 0; r < 2; r++){
        for(int i = 0; i < N; i++){
            scanf("%d", &a[r][i]);
            a[r][i]--;
        }
    }

    ll ans = 0;
    int top = 0, bot = 0;
    for(int i = 0; i < N; i++){
        top += a[0][i];
        bot += a[1][i];

        if((top < 0 && bot > 0) || (top > 0 && bot < 0)){
            if(abs(top) < abs(bot)){
                ans += abs(top);
                bot += top;
                top = 0;
            } else {
                ans += abs(bot);
                top += bot;
                bot = 0;
            }
        }

        ans += abs(top + bot);
    }
    printf("%lld\n", ans);
}