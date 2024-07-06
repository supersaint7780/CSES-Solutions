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

ll helper(vll &arr, ll sum, vector<ll> &dp) {
    if(sum == 0) {
        return 1;
    }

    if(dp[sum] != -1) {
        return dp[sum];
    }

    ll choseSame = 0;
    for(int i=0;i<arr.size();i++) {
        if(sum - arr[i] >= 0) {
            choseSame += helper(arr, sum - arr[i], dp) % MOD;
        }
    }
    return dp[sum] = choseSame % MOD;
}

void solve() {
    ll size = 0, sum = 0;
    cin >> size >> sum;
    vll arr(size);
    for(auto &it: arr) {
        cin >> it;
    }

    vector<ll> dp(sum + 1, -1);
    cout << helper(arr, sum, dp) << endl;    
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