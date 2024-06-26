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
    ll n = 0, m = 0;
    cin >> n >> m;
    vll arr1(n);
    vll arr2(m);

    for(auto &it: arr1) cin >> it;
    for(auto &it: arr2) cin >> it;

    multiset<ll> st(all(arr1));

    for(auto &it: arr2) {
        auto ans = st.lower_bound(it);
        ll val = *ans;
        if(val == it) {
            cout << val << endl;
            st.erase(ans);
        } else {
            if(ans == st.begin()) {
                cout << -1 << endl;
            } else {
                auto prev = --ans;
                ll prev_val = *prev;
                cout << prev_val << endl;
                st.erase(prev);
            }
        }
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