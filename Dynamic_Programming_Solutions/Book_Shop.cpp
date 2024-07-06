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

int helper(vi &price, vi &pages, int index, int money, vector<vi> &dp) {
    if(index == price.size()) {
        return 0;
    }

    if(dp[index][money] != -1) {
        return dp[index][money];
    }

    int notChoose = helper(price, pages, index + 1, money, dp);
    int choose = 0;
    if(money - price[index] >= 0) {
        choose = helper(price, pages, index + 1, money - price[index], dp) + pages[index];
    }
    return dp[index][money] = max(choose, notChoose);
}

void solve() {
    int size = 0, money = 0;
    cin >> size >> money;
    vi price(size);
    vi pages(size);

    for(auto &p: price) cin >> p;
    for(auto &p: pages) cin >> p;

    vi curr(money + 1, 0);
    vi next(money + 1, 0);
    for(int i=size-1;i>=0;i--) {
        for(int j=1;j<=money;j++) {
            int notChoose = next[j];
            int choose = 0;
            if(j - price[i] >= 0) {
                choose = next[j - price[i]] + pages[i];
            }
            curr[j] = max(notChoose, choose);
        }
        next = curr;
    }
    cout << curr[money] << endl;
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