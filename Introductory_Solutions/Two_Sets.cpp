#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
    ll n = 0;
    cin >> n;
    ll sum = n * (n + 1)/2;
    if(sum & 1) {
        cout << "NO" << endl;
    } else {
        cout << "YES" << endl;
        unordered_set<int> s1;
        ll req = sum/2;
        ll start = n;
        while(req > 0) {
            if(req-start >= 0) {
                s1.insert(start);
                req -= start;
            }
            --start;
        }
        cout << s1.size() << endl;
        for(ll i=1;i<=n;i++) {
            if(s1.find(i) != s1.end()) {
                cout << i << " ";
            }
        }
        cout << endl;
        cout << (n - (ll)s1.size()) << endl;
        for(ll i=1;i<=n;i++) {
            if(s1.find(i) == s1.end()) {
                cout << i << " ";
            }
        }
        cout << endl;
    }
}