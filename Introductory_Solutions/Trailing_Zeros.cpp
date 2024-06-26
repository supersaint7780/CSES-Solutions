#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define MOD 1000000007;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int input = 0;
    cin >> input;
    int trailingZeroes = 0;
    for(int i=5;i<=input;i+=5) {
        int temp = i;
        while(temp > 0) {
            if(temp % 5 == 0) {
                ++trailingZeroes;
                temp/=5;
            } else {
                break;
            }
        }
    }
    cout << trailingZeroes << endl;
}