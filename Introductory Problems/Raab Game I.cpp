#include <bits/stdc++.h>

using namespace std;

int T;

int main(){
    scanf("%d", &T);
    for(int t = 0, n, a, b; t < T; t++){
        scanf("%d %d %d\n", &n, &a, &b);

        // Degenerate case: all ties
        if(a == 0 && b == 0){
            printf("YES\n");
            for(int i = 0; i < 2; i++)
                for(int j = 1; j <= n; j++)
                    printf("%d%c", j, (" \n")[j==n]);
            continue;
        }

        // Otherwise, each player must win at least once
        // and the total wins cannnot exceed n
        if(a + b > n || a == 0 || b == 0){
            printf("NO\n");
            continue;
        }

        // General case: trade wins then handle ties
        printf("YES\n");
        int ties = n - a - b;
        vector<int> xs(n+1);

        // Start with both players playing 1, 2, 3, ...
        // Cyclic shift a player by k to the right
        // in order to give them k wins
        // E.g. n = 5, shift b by k = 2
        // as = 1 2 3 4 5 (3 wins)
        // bs = 4 5 1 2 3 (2 wins)
        for(int i = 1; i <= a+b; i++){
            int pos = (i + b - 1) % (a + b) + 1;
            xs[pos] = i;
        }
        for(int i = a+b+1; i <= n; i++)
            xs[i] = i;

        // Print out solution
        for(int i = 1; i <= n; i++)
            printf("%d%c", i, (" \n")[i==n]);
        for(int i = 1; i <= n; i++)
            printf("%d%c", xs[i], (" \n")[i==n]);
    }
}
