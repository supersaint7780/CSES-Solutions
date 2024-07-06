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

ll helper(ll sum, vector<ll> &dp) {
    if(sum == 0) {
        return 1;
    }

    if(dp[sum] != -1) {
        return dp[sum];
    }

    ll ans = 0;
    for(int i=1;i<=6;i++) {
        if(sum - i >= 0) {
            ans += helper(sum - i, dp) % MOD;
        }
    }
    return dp[sum] = ans % MOD;
}

void solve() {
    ll sum = 0;
    cin >> sum;
    vector<ll> dp(sum + 1, 0);
    dp[0] = 1;
    for(ll i=1;i<=sum;i++) {
        ll ans = 0;
        for(ll j=1;j<=6;j++) {
            if(i - j >= 0) {
                ans += dp[i - j] % MOD;
            }
        }
        dp[i] = ans % MOD;
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