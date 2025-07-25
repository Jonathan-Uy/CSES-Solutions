#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int N, x, d;
ll sum;
priority_queue<int, vector<int>, greater<int>> sticks;

int main(){
    scanf("%d %d", &x, &N);
    for(int i = 0; i < N; i++){
        scanf("%d", &d);
        sticks.push(d);
    }
    while(sticks.size() > 1){
        int a = sticks.top(); sticks.pop();
        int b = sticks.top(); sticks.pop();
        sticks.push(a+b);
        sum += a + b;
    }
    printf("%lld\n", sum);
}
