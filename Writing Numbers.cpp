#include <bits/stdc++.h>

// NOT DONE

using namespace std;

int times[10];

void write(int num){
	string S = to_string(num);
	for(char& c : S){
		times[(int) (c-'0')]++;
	}
}

bool check(int N){
	for(int d = 0; d <= 9; d++)
		if(times[d] > N)
			return false;
	return true;
}

int main(){
	for(int N = 1; N <= 100000; N++){
		for(int d = 0; d <= 9; d++)	times[d] = 0;
		
		int num = 0;
		while(check(N)){
			write(++num);
		}
		
		printf("%d: %d\n", N, num-1);
	}
}
