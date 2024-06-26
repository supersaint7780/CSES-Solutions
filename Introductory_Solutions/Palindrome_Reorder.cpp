#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define MOD 1000000007

void solve() {

}


int main() {
    string input;
    cin >> input;
    int freq[26] = {0};
    for(char ch:input) {
        ++freq[ch-65];
    }
    cout << endl;
    int odd = 0;
    char oddOccurence = ' ';
    bool flag = true;
    for(int i=0;i<26;i++) {
        if(freq[i] & 1) ++odd;
        if(odd == 1 && flag) {
            oddOccurence = (char)(i + 'A');
            flag = false;
        }
        if(odd > 1) break;
    }
    if(odd > 1) {
        cout << "NO SOLUTION" << endl;
    } else {
        string half;
        for(int i=0;i<26;i++) {
            for(int j=0;j<freq[i]/2;j++) {
                half.push_back((char)(i + 'A')) ;
            }
        }
        string ans = half;
        reverse(half.begin(), half.end());
        if(odd == 1) {
            ans += oddOccurence + half;
        } else {
            ans += half;
        }
        cout << ans << endl;
    }
}