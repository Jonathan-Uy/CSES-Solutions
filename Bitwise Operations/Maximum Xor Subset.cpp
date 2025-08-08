#include <bits/stdc++.h>

using namespace std;
const int logX = 32;

int N, basis[logX];

void insert_vector(int mask){
    for(int i = logX-1; i >= 0; i--){
        if((mask&(1<<i)) == 0)  continue;
        if(!basis[i]){
            basis[i] = mask;
            return;
        }
        mask ^= basis[i];
    }
}

int main(){
    scanf("%d", &N);
    for(int i = 0, x; i < N; i++){
        scanf("%d", &x);
        insert_vector(x);
    }

    int ans = 0;
	for(int i = logX-1; i >= 0; i--){
		if(!basis[i])           continue;
		if((ans&(1<<i)) != 0)   continue;

		ans ^= basis[i];
	}
    printf("%d\n", ans);
}