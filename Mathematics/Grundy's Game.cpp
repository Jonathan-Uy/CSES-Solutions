#include <bits/stdc++.h>

using namespace std;
const int maxN = 1e6+1;

/**
 * A036685
 * Retrivied from https://oeis.org/A036685
 */

int T, lose[42] = { 0, 1, 2, 4, 7, 10, 20, 23, 26, 50, 53, 270, 273, 276, 282, 285, 288, 316, 334, 337, 340, 346, 359, 362, 365, 386, 389, 392, 566, 630, 633, 636, 639, 673, 676, 682, 685, 923, 926, 929, 932, 1222 };
bool b[maxN];

void init(){
    for(int x : lose)
        b[x] = true;
}

int main(){
    init();
    scanf("%d", &T);
    for(int t = 0, N; t < T; t++){
        scanf("%d", &N);
        printf("%s\n", b[N] ? "second" : "first");
    }
}