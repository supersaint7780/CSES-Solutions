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
    vi arr(size);
    for(auto &it: arr) cin >> it;

    stack<int> st;
    vi ans(size);
    for(int i=size-1;i>=0;i--) {
        if(st.empty() || arr[st.top()] <= arr[i]) {
            st.push(i);
        } else {
            while(!st.empty() && arr[st.top()] > arr[i]) {
                ans[st.top()] = i + 1;
                st.pop();
            }
            st.push(i);
        }
    }

    while(!st.empty()) {
        ans[st.top()] = 0;
        st.pop();
    }
    for(auto it: ans) cout << it << " ";
    cout << endl;
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