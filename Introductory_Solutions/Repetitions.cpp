#include <bits/stdc++.h>
using namespace std;

int main() {
    string input;
    cin >> input;
    int count = 0;
    int ans = 0;
    char current = input[0];
    for(int i=0;i<input.size();i++) {
        if(input[i] == current) {
            ++count;
        } else {
            count = 1;
            current = input[i];
        }
        ans = max(ans, count);
    }
    cout << ans << endl;
}