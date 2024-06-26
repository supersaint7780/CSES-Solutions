#include <bits/stdc++.h>
using namespace std;

int main() {
    int n = 0;
    cin >> n;
    int ans = 0;
    for(int i=1;i<=n;i++) ans^=i;
    for(int i=0;i<n-1;i++) {
        int x = 0;
        cin >> x;
        ans^=x;
    }
    cout << ans << endl;
}