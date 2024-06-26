#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int size = 0, sum = 0;
    cin >> size >> sum;
    vector<int> arr(size);

    for(int i=0;i<size;i++) cin >> arr[i];
    
    vector<vector<int>> dp(size + 1, vector<int>(sum + 1, 0));
    for(int i=1;i<=sum;i++) {
        dp[0][i] = 1e9;
    }

    for(int i=1;i<=size;i++) {
        for(int j=1;j<=sum;j++) {
            if(arr[i-1] > j) {
                dp[i][j] = dp[i-1][j]; 
            } else {
                dp[i][j] = min(dp[i][j-arr[i-1]] + 1, dp[i-1][j]);
            }
        }
    } 
    cout << ((dp[size][sum] == 1e9) ? -1 : dp[size][sum]) << endl;
}