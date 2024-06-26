#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define MOD 1000000007

int main() {
    int input = 0;
    cin >> input;
    int size = 1 << input;
    string temp(input, '0');
    cout << temp << endl;
    for(int i=0;i<input;i++) {
        for(int j = input-1;j>=0;j--) {
            if(temp[j] == '1') break;
            temp[j] = '1';
            cout << temp << endl;
            temp[j] = '0';
        }
        temp[i] = '1';
    }
}