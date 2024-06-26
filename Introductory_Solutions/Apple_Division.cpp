#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

#define endl '\n'
#define MOD 1000000007
#define all(x) begin(x), end(x)

ll power_mod(ll base, ll power, ll mod) {
    ll result = 1;
    base = base % mod;
    while (power > 0) {
        if (power % 2 == 1) {
            result = (result * base) % mod;
        }
        base = (base * base) % mod;
        power = power / 2;
    }
    return result;
}

ll calculate(vector<ll> &arr, ll group1, ll sum, ll size) {
    if(size == 0) {
        ll group2 = sum - group1;
        return abs(group1 - group2);
    }

    ll chose = calculate(arr, group1 + arr[size-1], sum, size - 1);
    ll notChose = calculate(arr, group1, sum, size - 1);
    return min(chose, notChose);
}

void solve() {
    ll size = 0;
    cin >> size;
    vector<ll> arr(size);
    ll sum = 0;
    for(int i=0;i<size;i++) {
        cin >> arr[i];
        sum += arr[i];
    }
    ll min_val = calculate(arr, 0, sum, size);
    cout << min_val << endl;
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