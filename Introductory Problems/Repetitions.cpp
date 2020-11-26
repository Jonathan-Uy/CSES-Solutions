#include <bits/stdc++.h>

using namespace std;

char c[1000000];
string s;
int cur, best;

int main(){
	scanf(" %s", c);
	s = (string) c;
	cur = best = 1;
	for(int i = 1; i < (int) s.size(); i++){
		if(s[i] == s[i-1])	cur++;
		else 				cur = 1;
		best = max(best, cur);
	}
	printf("%d\n", best);
}
