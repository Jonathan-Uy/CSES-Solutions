#include <bits/stdc++.h>

using namespace std;

char S[1000001];
int N, odd, freq[26];

int main(){
    scanf("%s", S);
    N = (int) strlen(S);
    for(int i = 0; i < N; i++)
        freq[(int) (S[i]-'A')]++;

    odd = -1;
    for(int i = 0; i < 26; i++){
        if(freq[i]&1){
            if(odd != -1){
                printf("NO SOLUTION\n");
                return 0;
            } else {
                odd = i;
            }
        }
    }

    for(int i = 0; i < 26; i++)
        for(int j = 0; j < freq[i]/2; j++)
            printf("%c", (char) (i+'A'));
    if(odd != -1)
        printf("%c", (char) (odd+'A'));
    for(int i = 25; i >= 0; i--)
        for(int j = 0; j < freq[i]/2; j++)
            printf("%c", (char) (i+'A'));
}
