#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using vi = vector<int>;
using vll = vector<ll>;
using pii = pair<int, int>;
using pll = pair<ll, ll>;

#define endl '\n'
#define MOD 1000000007
#define all(x) begin(x), end(x)
#define LONG_INF (ll) 1e18
#define INF (ll) 1e9 

bool canMakeTarget(ll time, vll &arr, ll target) {
    ll products = 0;
    for(auto it: arr) {
        products += time/it;
    }
    return (products >= target);
}

void solve() {
    ll size = 0, target = 0;
    cin >> size >> target;

    vll arr(size);
    ll min_val = INF;
    for(auto &it: arr) {
        cin >> it;
        min_val = min(min_val, it);
    }

    ll start = 1;
    ll end = min_val * target;
    while(start < end) {
        ll mid = (end - start)/2 + start;
        if(canMakeTarget(mid, arr, target)) {
            end = mid;
        } else {
            start = mid + 1;
        }
    }
    cout << end << endl;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
     
    int testcases = 1;
    // cin >> testcases;
    while(testcases--) {
        solve();
    }
    return 0;
}