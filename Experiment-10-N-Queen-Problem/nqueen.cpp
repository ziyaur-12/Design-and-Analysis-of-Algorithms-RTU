#include <iostream>
#include <cmath>
using namespace std;

int board[20], cnt;

bool place(int row, int col) {
    for (int i = 1; i < row; i++)
        if (board[i] == col || abs(board[i] - col) == abs(i - row))
            return false;
    return true;
}

void print(int n) {
    cout << "\nSolution " << ++cnt << ":\n";
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++)
            cout << (board[i] == j ? " Q " : " - ");
        cout << endl;
    }
}

void queen(int row, int n) {
    for (int col = 1; col <= n; col++) {
        if (place(row, col)) {
            board[row] = col;
            if (row == n) print(n);
            else queen(row + 1, n);
        }
    }
}

int main() {
    int n;
    cout << "Enter number of Queens: ";
    cin >> n;
    queen(1, n);
}
