#include <bits/stdc++.h>

using namespace std;
const int maxN = 1e6+5;

int freq[26];
char S[maxN], ans[maxN];

bool possible(int current){
    int mode = 0, total = 0;
    for(int c = 0; c < 26; c++){
        if(freq[mode] < freq[c])
            mode = c;
        total += freq[c];
    }
    return (freq[mode] <= (total+1)/2) && (freq[current] <= total/2);
}

int main(){
    scanf(" %s", S);
    const int N = (int) strlen(S);
    for(int i = 0; i < N; i++)
        freq[(int) (S[i] - 'A')]++;

    int lastchar = -1;
    for(int i = 0; i < N; i++){
        bool filled = false;
        for(int c = 0; c < 26 && !filled; c++){
            if(freq[c] > 0 && c != lastchar){
                freq[c]--;
                if(possible(c)){
                    ans[i] = (char) (c + 'A');
                    lastchar = c;
                    filled = true;
                } else freq[c]++;
            }
        }

        if(!filled){
            printf("-1\n");
            return 0;
        }
    }

    for(int i = 0; i < N; i++)
        printf("%c", ans[i]);
    printf("\n");
}