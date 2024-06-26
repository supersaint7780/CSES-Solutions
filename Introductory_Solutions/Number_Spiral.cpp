#include <bits/stdc++.h>
using namespace std;

void solve(int row, int col) {
    long long temp = max(row, col);
    long long base = temp * temp;
    long long diagonalReference = base + temp + 1;
    int flag = (temp % 2 == 1) ? 1 : -1;
    long long ans = 0;
    if(col > row) {
        ans = diagonalReference - flag * (2 * temp - row - col);
    } else {
        ans = diagonalReference + flag * (2 * temp - row - col);
    }
    cout << ans << endl;
}

int main() {
    int testcases = 0;
    cin >> testcases;
    while(testcases--) {
        int row = 0;
        int col = 0;
        cin >> row >> col;
        solve(row-1, col-1);
    }
}