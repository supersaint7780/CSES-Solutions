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
    vector<string> grid(size);
    for(int i=0;i<size;i++) {
        cin >> grid[i];
    }

    if(grid[0][0] == '*' || grid[size - 1][size - 1] == '*') {
        cout << 0 << endl;
        return;
    }

    vector<vector<int>> dp(size, vector<int>(size, 0));
    for(int i=0;i<size;i++) {
        if(grid[i][0] != '*')
            dp[i][0] = 1;
        else
            break;
    }

    for(int i=0;i<size;i++) {
        if(grid[0][i] != '*')
            dp[0][i] = 1;
        else
            break;
    }

    dp[0][0] = 1;
    for(int i=1;i<size;i++) {
        for(int j=1;j<size;j++) {
            if(grid[i][j] != '*') {
                dp[i][j] = dp[i-1][j] % MOD + dp[i][j-1]%MOD;
                dp[i][j] %= MOD;
            }
        }
    }
    cout << dp[size - 1][size - 1] << endl;
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