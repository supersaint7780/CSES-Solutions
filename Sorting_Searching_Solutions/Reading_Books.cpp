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
    ll size = 0;
    cin >> size;
    vll arr(size);
    for(auto &it: arr) cin >> it;
    sort(all(arr));
    
    ll sum = 0;
    for(int i=0;i<size-1;i++) sum += arr[i];
    if(sum < arr[size - 1]) {
        cout << arr[size - 1] * 2 << endl;
    } else {
        cout << sum + arr[size - 1] << endl;
    }

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