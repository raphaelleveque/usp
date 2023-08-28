#include <bits/stdc++.h>
using namespace std;

void print(vector<vector<int>> mat) {
    for (int i = 0; i < 8; ++i) {
        for (int j = 0; j < 8; ++j) {
            cout << mat[i][j] << " ";
        }
        cout << endl;
    }
}

bool backtrack(vector<vector<int>> mat, int i, int j, int count) {
    if (i >= 8 || j >= 8 || i < 0 || j < 0 || mat[i][j] != 0)
        return false;

    mat[i][j] = count;
    if (count == 64) {
        return true;
    }
    if (backtrack(mat, i-2, j-1, count+1)) return true;
    if (backtrack(mat, i-2, j+1, count+1)) return true;
    if (backtrack(mat, i-1, j+2, count+1)) return true;
    if (backtrack(mat, i+1, j+2, count+1)) return true;
    if (backtrack(mat, i+2, j-1, count+1)) return true;
    if (backtrack(mat, i+2, j+1, count+1)) return true;
    if (backtrack(mat, i-1, j-2, count+1)) return true;
    if (backtrack(mat, i+1, j-2, count+1)) return true;
    mat[i][j] = 0;
    return false;
}

int main() {
    int x, y;
    cin >> x >> y;
    x -=1;
    y -=1;
    vector< vector<int> >  mat ( 8, vector<int>(8, 0)  );
    backtrack(mat, y, x, 1);
    print(mat);


    return 0;
}
