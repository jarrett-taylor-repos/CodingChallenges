#include <iostream>
#include <vector>
#include <queue>
using namespace std;

vector<vector<int>> directions = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

bool InBounds(int x, int y, int rows, int cols) {
    if(x < 0 || y < 0) return false;
    if(x > rows || y > cols) return false;
    return true;
}

void fillWithWater(vector<vector<char>>& grid, int rows, int cols, int i, int j) {
    queue<int> q;
    //collpase 2d to 1d 
    //i * num of cols + j
    //i = index / num of cols; j = index % num of cols
    int index = i * cols + j;
    q.push(index);
    grid[i][j] = '0';

    while(!q.empty()) {
        int index = q.front();
        int row_i = index / cols;
        int col_j = index % cols;
        q.pop();

        for(vector<int> direction : directions) {
            int x = direction[0] + row_i;
            int y = direction[1] + col_j;
            if(InBounds(x, y, rows, cols) && grid[x][y] != '0') {
                grid[x][y] = '0';
                int temp = x * cols + y;
                q.push(temp);
            }
        }
    }
}

int numIslands(vector<vector<char>>& grid) {
    if(grid.size() == 0) return 0;

    int islands = 0;
    int rows = grid.size();
    int cols = grid[0].size();

    for(int i = 0; i < rows; i++) {
        for(int j= 0; j < cols; j++) {
            if(grid[i][j] == '1') {
                islands++;
                fillWithWater(grid, rows, cols, i, j);
            }
        }
    }
    return islands;
}

int main() {
    vector<vector<char>> grid = {
        {'1','1','1','1','0'},
        {'1','1','0','1','0'},
        {'1','1','0','0','0'},
        {'0','0','0','0','0'}
    };

    cout << numIslands(grid) << endl;

    return 0; 
}