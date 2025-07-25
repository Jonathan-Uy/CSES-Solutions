#include <bits/stdc++.h>

using namespace std;

int N;

int main(){
    scanf("%d", &N);
    if(N == 1)      printf("1 ");
    else if(N <= 3) printf("NO SOLUTION\n");
    else {
        for(int i = 2; i <= N; i += 2)
            printf("%d ", i);
        for(int i = 1; i <= N; i += 2)
            printf("%d ", i);
    }
}
