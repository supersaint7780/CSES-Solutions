#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define MOD 1000000007
int main() {
    ll input = 0;
    cin >> input;
    ll ans = 1;
    ll x = 2;
    while(input > 0) {
        if(input & 1) {
            ans = ((ans%MOD) * (x%MOD))%MOD;
        }
        x = ((x % MOD) * (x % MOD))%MOD;
        input/=2;
    }
    cout << ans << endl;
}