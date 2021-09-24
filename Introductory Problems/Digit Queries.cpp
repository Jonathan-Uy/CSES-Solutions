#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int Q;
ll K;

ll pow10(int x){
    ll res = 1;
    for(int i = 0; i < x; i++)
        res *= 10;
    return res;
}

int solve(ll N){
    if(N < 9)   return (int) N+1;

    int len = 1;
    while(9 * pow10(len-1) * len < N){
        N -= 9 * pow10(len-1) * len;
        len++;
    }

    string S = to_string(pow10(len-1) + N/len);
    return (int) (S[N%len] - '0');
}

int main(){
    scanf("%d", &Q);
    for(int q = 0; q < Q; q++){
        scanf("%lld", &K);
        printf("%d\n", solve(K-1));
    }
}