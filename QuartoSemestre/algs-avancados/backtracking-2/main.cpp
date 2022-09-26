#include <bits/stdc++.h>
using namespace std;

int max_sum = 0;
const int board_size = 8;

void verify_sum(vector<int> placements, vector<vector<int>> chessboard) {
    int sum = 0;
    for (int i = 0; i < board_size; i++) {
        sum += chessboard[i][placements[i]];
    }
    if (sum > max_sum)
        max_sum = sum;
}

bool isValid(vector<int> placements) {
    int row = placements.size() - 1;
    for (int i = 0; i < row; i++) {
        int diff = (abs(placements[i] - placements[row]));
        if (diff == 0 || diff == row - i) {
            return false;
        }
    }
    return true;
}

void backtracking(int row, vector<int> placements, vector<vector<int>> chessboard) {
    if (row >= board_size) {
        verify_sum(placements, chessboard);
        return;
    }
    for (int col = 0; col < board_size; col++) {
        placements.push_back(col);
        if (isValid(placements))
            backtracking(row + 1, placements, chessboard);
        placements.pop_back();
    }
}

int main() {
    int tests;
    cin >> tests;

    while (tests--) {
        max_sum = 0;
        vector<vector<int>> chessboard(board_size, vector<int>(board_size));
        for (int i = 0; i < board_size; i++) {
            for (int j = 0; j < board_size; j++) {
                cin >> chessboard[i][j];
            }
        }
        vector<int> placements;
        backtracking(0, placements, chessboard);
        cout << right << setw(5) << max_sum << endl;
    }

    return 0;
}