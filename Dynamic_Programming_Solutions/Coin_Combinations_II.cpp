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
    int size = 0, sum = 0;
    cin >> size >> sum;
    vi arr(size);
    for(int i=0;i<size;i++) {
        cin >> arr[i];
    }

    vector<int> dp(sum + 1, 0);
    dp[0] = 1;
    // dp[w] indicates all ordered coin formation adding up to w
    for(int i=0;i<size;i++) {
        for(int j=1;j<=sum;j++) {
            if(j - arr[i] >= 0) {
                dp[j] = (dp[j] % MOD + dp[j - arr[i]] % MOD) % MOD;
            }
        }
    }
    cout << dp[sum] << endl;
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