#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int maxN = 2e5+5;

int N, A, B;
pii cand[maxN];

multiset<int> initial_artist_set(){
    vector<int> all;
    for(int i = A; i < N; i++)
        all.push_back(cand[i].second);
    sort(all.begin(), all.end());

    reverse(all.begin(), all.end());
    multiset<int> best;
    for(int i = 0; i < B; i++)
        best.insert(all[i]);
    return best;
}

int main(){
    scanf("%d %d %d", &A, &B, &N);
    for(int i = 0, x, y; i < N; i++){
        scanf("%d %d", &x, &y);
        cand[i] = {x, y};
    }
    sort(cand, cand+N, [](const pii a, const pii b){
        return a.first == b.first ? a.second < b.second : a.first > b.first;
    });

    ll pref = 0;
    priority_queue<int> prefix_deltas;
    for(int i = 0; i < A; i++){
        pref += cand[i].first;
        prefix_deltas.push(cand[i].second - cand[i].first);
    }

    multiset<int> remaining_art = initial_artist_set();
    ll suf = accumulate(remaining_art.begin(), remaining_art.end(), 0LL);

    ll ans = pref + suf;
    for(int i = A; i < A+B; i++){
        const int x = cand[i].first;
        const int y = cand[i].second;
        pref += x;

        prefix_deltas.push(y - x);
        pref += prefix_deltas.top();
        prefix_deltas.pop();

        auto worst_artist = remaining_art.lower_bound(y);
        int art_value = *worst_artist;
        remaining_art.erase(worst_artist);
        suf -= art_value;

        ans = max(ans, pref + suf);
    }
    printf("%lld\n", ans);
}
