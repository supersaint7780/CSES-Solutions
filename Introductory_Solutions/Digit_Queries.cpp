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


void solve() {
    ll query = 0;
    cin >> query;
    ll character_count = 1;
    ll number_of_numbers = 9;
    while(query > number_of_numbers * character_count) {
        query -= number_of_numbers * character_count;
        ++character_count;
        number_of_numbers *= 10;
    }
    ll start = pow(10, character_count - 1);
    ll expected_number 
        = start - (query % character_count == 0) + query/character_count;
    ll expected_number_digit_pos = (query - 1) % character_count;
    string expected_number_string = to_string(expected_number);
    cout << expected_number_string[expected_number_digit_pos] << endl;

}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
     
    int testcases;
    cin >> testcases;
    while(testcases--) {
        solve();
    }
    return 0;
}