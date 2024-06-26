#include <bits/stdc++.h>
using namespace std;

int main() {
    int n = 0;
    cin >> n;
    vector<int> nums;
    for(int i=0;i<n;i++) {
        int temp = 0;
        cin >> temp;
        nums.push_back(temp);
    }

    long long ans = 0;
    for(int i=1;i<n;i++) {
        if(nums[i] >= nums[i-1]) {
            continue;
        } else {
            ans += nums[i-1] - nums[i];
            nums[i] = nums[i-1];
        }
    }
    cout << ans << endl;
}