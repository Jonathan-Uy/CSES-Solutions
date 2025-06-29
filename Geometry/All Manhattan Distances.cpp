#include <bits/stdc++.h>

using namespace std;
const int maxN = 2e5+1;

int N, x[maxN], y[maxN];
__int128 xcur, ycur, ans;

ostream& operator<<(ostream& o, const __int128& x) {
    if(x == numeric_limits<__int128>::min())
        return o << "-170141183460469231731687303715884105728";
    else if(x < 0)  return o << "-" << -x;
    else if(x < 10) return o << (char)(x + '0');
    else            return o << x / 10 << (char)(x % 10 + '0');
}

int main(){
    scanf("%d", &N);
    for(int i = 0; i < N; i++)
        scanf("%d %d", &x[i], &y[i]);

    sort(x, x+N);
    sort(y, y+N);

    xcur = ycur = ans = 0;
    for(int i = 1; i < N; i++){
        xcur += (__int128) (x[i] - x[i-1]) * i;
        ycur += (__int128) (y[i] - y[i-1]) * i;
        ans += xcur + ycur;
    }
    cout << ans << endl;
}