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

void tower_of_hanoi(int n, int source, int target, int auxiliary, vector<pair<int, int>>& moves) {
    if (n == 1) {
        moves.push_back({source, target});
        return;
    }
    tower_of_hanoi(n - 1, source, auxiliary, target, moves);
    moves.push_back({source, target});
    tower_of_hanoi(n - 1, auxiliary, target, source, moves);
}

void solve() {
    int n = 0;
    cin >> n;

    vector<pair<int, int>> moves;
    tower_of_hanoi(n, 1, 3, 2, moves);
    
    cout << moves.size() << endl; // Print the number of moves
    
    for (const auto& move : moves) {
        cout << move.first << " " << move.second << endl; // Print the sequence of moves
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