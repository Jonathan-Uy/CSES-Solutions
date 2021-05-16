#include <bits/stdc++.h>

using namespace std;
const int maxN = 16;

int N;
bool b[maxN+1];

void print(){
    for(int i = N; i > 0; i--)
        printf("%d", b[i]);
    printf("\n");
}

int main(){
    scanf("%d", &N);

    print();
    for(int i = 1; i < (1<<N); i++){
        int LSB = __builtin_ffs(i);
        b[LSB] ^= 1;
        print();
    }
}
