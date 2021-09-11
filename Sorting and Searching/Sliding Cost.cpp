#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const int maxN = 2e5+1;

int N, K, x[maxN];
ll losum, hisum;
multiset<int> lo, hi;

ll cost(){
    ll median = *lo.rbegin();
    ll locost = (median * lo.size()) - losum;
    ll hicost = hisum - (median * hi.size());
    return locost + hicost;
}

void lowToHigh(){
    ll val = *lo.rbegin();
    lo.erase(lo.lower_bound(val));
    hi.insert(val);
    losum -= val;
    hisum += val;
}

void highToLow(){
    ll val = *hi.begin();
    lo.insert(val);
    hi.erase(hi.lower_bound(val));
    losum += val;
    hisum -= val;
}

void adjust(){
    int tot = (int) (lo.size() + hi.size());
    if(lo.size() < (tot+1)/2)       highToLow();
    else if(lo.size() > (tot+1)/2)  lowToHigh();
}

void erase(ll val){
    ll median = *lo.rbegin();
    if(val > median){
        hi.erase(hi.lower_bound(val));
        hisum -= val;
    } else {
        lo.erase(lo.lower_bound(val));
        losum -= val;
    }
    adjust();
}

void insert(ll val){
    if(lo.size() == 0){
        lo.insert(val);
        losum += val;
        return;
    }

    ll median = *lo.rbegin();
    if(val > median){
        hi.insert(val);
        hisum += val;
    } else {
        lo.insert(val);
        losum += val;
    }
    adjust();
}

int main(){
    scanf("%d %d", &N, &K);
    for(int i = 0; i < K; i++){
        scanf("%d", &x[i]);
        insert(x[i]);
    }

    printf("%lld%c", cost(), (" \n")[K==N]);
    for(int i = K; i < N; i++){
        scanf("%d", &x[i]);
        insert(x[i]);
        erase(x[i-K]);
        printf("%lld%c", cost(), (" \n")[i==N-1]);
    }
}