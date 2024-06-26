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

void backtrack(string current, string remaining, set<string>& result) {
    if (remaining.length() == 0)
    {
        result.insert(current);
        return;
    }
    for (int i = 0; i < remaining.length(); i++)
    {
        backtrack(current + remaining[i], 
            remaining.substr(0, i) + remaining.substr(i + 1), result);
    }
}

void solve() {
    string input;
    cin >> input;

    set<string> result;
    backtrack("", input, result);

    cout << result.size() << endl;
    for (const string& str : result) {
        cout << str << endl;
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