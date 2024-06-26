#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve() {
    int a = 0;
    int b = 0;
    cin >> a >> b;
    int x = (a + b)/3;
    if(min({x, a, b}) == x && max({2*x, a, b}) == 2 * x && (a+b)%3 == 0) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }
}

int main() {
    int testcases = 0;
    cin >> testcases;
    while(testcases--) {
        solve();
    }
}