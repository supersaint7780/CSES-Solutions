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
    ll size = 0, k = 0;
    cin >> size >> k;
    vll arr(size);
    for(auto &it: arr) cin >> it;

    map<ll, ll> mp;
    mp[0] = 1;
    ll currSum = 0;
    ll count = 0;
    for(int i=0;i<size;i++) {
        currSum += arr[i];
        ll required = currSum - k;
        count += mp[required];
        mp[currSum]++;
    }
    cout << count << endl;
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