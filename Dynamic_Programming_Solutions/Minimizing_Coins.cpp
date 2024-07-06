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

int helper(vi &arr, int index, int sum, vector<vi> &dp) {

    if(index >= arr.size()) {
        if(sum == 0) {
            return 0;
        } else {
            return 1e9;
        }
    }

    if(dp[index][sum] != -1) {
        return dp[index][sum];
    }

    int choseSame = 1e9;
    if(sum - arr[index] >= 0) {
        choseSame = 1 + helper(arr, index, sum - arr[index], dp);
    }
    int choseDiff = helper(arr, index + 1, sum, dp);
    return dp[index][sum] = min(choseDiff, choseSame);
}


void solve() {
    int size = 0, sum = 0;
    cin >> size >> sum;
    vi arr(size);
    for(auto &it: arr) {
        cin >> it;
    }   
    vector<vi> dp(size + 1, vi(sum + 1, 0));
    for(int i=0;i<=sum;i++) {
        dp[size][i] = 1e9;
    }
    dp[size][0] = 0;

    // dp[i][j] = minium number of coins required to make sum
    // j using all coins including and after index i

    // dp[size][0] means if we dont include any index
    // still we could make zero without using any coin

    for(int i=size - 1;i >= 0; i--) {
        for(int j=0;j<=sum;j++) {
            int choseSame = 1e9;
            if(j - arr[i] >= 0) {
                choseSame = 1 + dp[i][j - arr[i]];
            }
            int choseDiff = dp[i+1][j];
            dp[i][j] = min(choseDiff, choseSame);
        }
    }

    cout << (dp[0][sum] != 1e9 ? dp[0][sum] : -1) << endl; 
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