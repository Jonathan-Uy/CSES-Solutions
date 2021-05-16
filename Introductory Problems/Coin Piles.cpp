#include <bits/stdc++.h>

using namespace std;

int T, a, b;

int main(){
    scanf("%d", &T);
    for(int t = 0; t < T; t++){
        scanf("%d %d", &a, &b);
        printf(((a+b)%3 != 0 || a > 2*b || b > 2*a) ? "NO\n" : "YES\n");
    }
}
