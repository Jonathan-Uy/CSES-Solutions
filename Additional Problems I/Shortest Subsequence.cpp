#include <bits/stdc++.h>

using namespace std;
const int maxN = 1e6+5;

int N, cnt;
char S[maxN], ch[4] = {'A', 'C', 'G', 'T'};
bool has[4];
vector<int> segs;
map<char,int> mp;

void init(){
    mp['A'] = 0;
    mp['C'] = 1;
    mp['G'] = 2;
    mp['T'] = 3;
}

int main(){
    init();
    scanf(" %s", S);

    N = (int) strlen(S);
    for(int i = 0; i < N; i++){
        int c = mp[S[i]];
        if(!has[c]){
            has[c] = true;
            cnt++;
            if(cnt == 4){
                fill(has, has+4, false);
                segs.push_back(i);
                cnt = 0;
            }
        }
    }

    for(int i : segs)
        printf("%c", S[i]);
    for(int i = 0; i < 4; i++){
        if(!has[i]){
            printf("%c\n", ch[i]);
            return 0;
        }
    }
}