#include <bits/stdc++.h>
using namespace std;

const int MAX_WIDTH = 1005, MAX_HEIGHT = 1005, MOD = 1e9 + 7;
long long n_paths[MAX_WIDTH][MAX_HEIGHT];
const char WALL = '#';
char grid[MAX_WIDTH][MAX_HEIGHT];

int main(){
    int height, width;
    cin >> height >> width;
    for(int i = 0; i < height; i++)
        scanf("%s", grid[i+1] + 1);

    memset(n_paths, 0, sizeof(n_paths));

    for(int i = 1; i <= height; i++) {
        for(int j = 1; j <= width; j++) {
            if(grid[i][j] == WALL) continue;

            if(i == 1 && j == 1) n_paths[i][j] = 1;
            else n_paths[i][j] = (n_paths[i - 1][j] + n_paths[i][j - 1]) % MOD;
        }
    }
    cout << n_paths[height][width] << endl;
    return 0;
}