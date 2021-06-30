#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const int maxN = 101;

int N, r[maxN];
double ans;

int f(int x){
    return x * (x-1) / 2;
}

int main(){
    scanf("%d", &N);
    for(int i = 0; i < N; i++){
        scanf("%d", &r[i]);
        for(int j = 0; j < i; j++){
            int tot = (r[j] <= r[i]) ? f(r[j]) : (f(r[i]) + (r[j]-r[i]) * r[i]);
            ans += (double) tot / (r[i] * r[j]);
        }
    }
    printf("%.6f\n", ans);
}