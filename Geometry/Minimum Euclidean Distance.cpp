#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<ll,ll> pll;
const int maxN = 2e5+1;

int N;
ll best;
bool isLeft[maxN];
pll P[maxN];

ll square(ll x){
    return x*x;
}

ll dist(pll A, pll B){
    ll dx = A.first-B.first;
    ll dy = A.second-B.second;
    return square(dx) + square(dy);
}

void solve(vector<int> PX, vector<int> PY){
    int len = PX.size();
    if(len == 1)  return;

    vector<int> LX, LY, RX, RY;
    for(int i = 0; i < len; i++){
        if(i < len/2){
            LX.push_back(PX[i]);
            isLeft[PX[i]] = true;
        } else {
            RX.push_back(PX[i]);
            isLeft[PX[i]] = false;
        }
    }

    for(int id : PY){
        if(isLeft[id])  LY.push_back(id);
        else            RY.push_back(id);
    }

    solve(LX, LY);
    solve(RX, RY);

    ll midX = P[LX.back()].first;
    vector<int> stripe;
    for(int id : PY)
        if(square(P[id].first-midX) < best)
            stripe.push_back(id);

    for(int i = 0; i < (int) stripe.size(); i++)
        for(int j = i+1; j < (int) stripe.size() && square(P[stripe[i]].second-P[stripe[j]].second) < best; j++)
            best = min(best, dist(P[stripe[i]], P[stripe[j]]));
}

int main(){
    scanf("%d", &N);
    vector<int> sortedX, sortedY;
    for(int i = 0, x, y; i < N; i++){
        scanf("%d %d", &x, &y);
        P[i] = {x, y};
        sortedX.push_back(i);
        sortedY.push_back(i);
    }
    sort(sortedX.begin(), sortedX.end(), [](int A, int B){
        return P[A].first < P[B].first;
    });
    sort(sortedY.begin(), sortedY.end(), [](int A, int B){
        return P[A].second < P[B].second;
    });

    best = LLONG_MAX;
    solve(sortedX, sortedY);
    printf("%lld\n", best);
}