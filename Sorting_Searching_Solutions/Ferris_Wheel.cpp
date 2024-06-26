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

void solve() {
    ll size = 0, max_weight = 0;
    cin >> size >> max_weight;
    vll arr(size);
    map<ll, ll> mp;
    for(auto &it:arr) {
        cin >> it;
    }
    sort(all(arr));
    int i = 0;
    int j = size - 1;
    ll count = 0;
    while(i <= j) {
        if(i!=j && arr[i] + arr[j] <= max_weight) {
            ++i;
            --j;
            ++count;
        } else {
            --j;
            ++count;
        }
    }
    cout << count << endl;
    
    
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