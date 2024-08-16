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

void solve() {
    int size = 0;
    cin >> size;
    vector<pii> arr(size);
    for(int i=0;i<size;i++) {
        cin >> arr[i].first >> arr[i].second;
    }
    sort(all(arr));

    ll ans = 0;
    ll time = 0;
    for(int i=0;i<size;i++) {
        time += arr[i].first;
        ans += arr[i].second - time;
    }
    cout << ans << endl;
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