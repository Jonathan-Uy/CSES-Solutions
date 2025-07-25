#include <bits/stdc++.h>

using namespace std;

int N;

int main(){
    scanf("%d", &N);
    if(N%4 == 1 || N%4 == 2)    printf("NO\n");
    else if(N%4 == 3){
        printf("YES\n");
        printf("%d\n", N/2);
        for(int i = 2; i <= N/2; i += 2)
            printf("%d %d ", i, N-i);
        printf("%d\n%d\n", N, N/2+1);
        for(int i = 1; i <= N/2; i += 2)
            printf("%d %d ", i, N-i);
    } else {
        printf("YES\n");
        printf("%d\n", N/2);
        for(int i = 2; i <= N/2; i += 2)
            printf("%d %d ", i, N-i+1);
        printf("\n%d\n", N/2);
        for(int i = 1; i <= N/2; i += 2)
            printf("%d %d ", i, N-i+1);
    }
}
