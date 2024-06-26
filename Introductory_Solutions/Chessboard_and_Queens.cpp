#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

#define endl '\n'
#define MOD 1000000007
#define all(x) begin(x), end(x)

ll power_mod(ll base, ll power, ll mod) {
    ll result = 1;
    base = base % mod;
    while (power > 0) {
        if (power % 2 == 1) {
            result = (result * base) % mod;
        }
        base = (base * base) % mod;
        power = power / 2;
    }
    return result;
}

void place(
        int &boards, 
        vector<string> &board, 
        int col, 
        int n,
        vector<bool> &rowTrack, 
        vector<bool> &lowerDiagonal, 
        vector<bool> &upperDiagonal) {
        
        if(col == n) {
            ++boards;
            return;
        }
        
        
        for(int i=0;i<n;i++) {
            int row = i;
            if(rowTrack[i] == false 
               && lowerDiagonal[col+row] == false 
               && upperDiagonal[col-row + n - 1] == false 
               && board[i][col] != '*') {
                
                board[i][col] = 'Q';
                rowTrack[i] = true;
                lowerDiagonal[col+row] = true;
                upperDiagonal[col-row + n - 1] = true;
                
                place(
                    boards, 
                    board, 
                    col+1, 
                    n, 
                    rowTrack, 
                    lowerDiagonal, 
                    upperDiagonal);
                
                board[i][col] = '.';
                rowTrack[i] = false;
                lowerDiagonal[col+row] = false;
                upperDiagonal[col-row + n - 1] = false;
            }
            
        }
        
    }
    int totalNQueens(int n, vector<string> &board) {
        vector<bool> rowTrack(n, false);
        vector<bool> lowerDiagonal(2*n-1, false);
        vector<bool> upperDiagonal(2*n-1, false);
        int boards = 0;
        place(boards, board, 0, n, rowTrack, lowerDiagonal, upperDiagonal);
        return boards;
    }

void solve() {
    int size = 8;
    vector<string> board;
    for(int i=0;i<size;i++) {
        string temp;
        cin >> temp;
        board.push_back(temp);
    }
    cout << totalNQueens(size, board) << endl;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
     
    int testcases = 1;
    // cin >> testcases;
    while(testcases--) {
        solve();
    }
    return 0;
}