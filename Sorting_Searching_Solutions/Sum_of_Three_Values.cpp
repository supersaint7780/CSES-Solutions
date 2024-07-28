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
    for(auto &it: arr) cin >> it;

    vector<pii> arr_pair(size);
    for(int i=0;i<size;i++) {
        arr_pair[i] = {arr[i], i + 1};
    }
    sort(all(arr_pair));

    for(int i=0;i<size - 2;i++) {
        int required = sum - arr_pair[i].first;
        int j = i + 1;
        int k = size - 1;
        while(j < k) {
            int sum = arr_pair[j].first + arr_pair[k].first;
            if(sum == required) {
                cout << arr_pair[i].second << " " << arr_pair[j].second << " " << arr_pair[k].second << endl;
                return;
            } else if(sum < required) {
                ++j;
            } else {
                --k;
            }
        }
    }

    cout << "IMPOSSIBLE" << endl;
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