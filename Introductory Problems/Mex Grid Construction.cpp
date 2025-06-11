#include <bits/stdc++.h>

using namespace std;

int N;

int main(){
    scanf("%d", &N);
    for(int i = 0; i < N; i++)
        for(int j = 0; j < N; j++)
            printf("%d%c", i ^ j, (" \n")[j==N-1]);
}