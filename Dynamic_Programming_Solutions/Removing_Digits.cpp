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
    int num = 0;
    cin >> num;

    // dp[num] steps required to make the number 0 using its digts
    vector<int> dp(num + 1, 1e9);
    dp[0] = 0;
    for(int i=1;i<=num;i++) {
        int temp = i;
        while(temp > 0) {
            int dig = temp % 10;
            if(i - dig >= 0) {
                dp[i] = min(dp[i], dp[i - dig] + 1);
            }
            temp /= 10;
        }
    }
    cout << dp[num] << endl;
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