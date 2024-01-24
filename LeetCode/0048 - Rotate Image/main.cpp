#include <iostream>
#include <vector>
using namespace std;

void Print(vector<int> m) {
    int size = m.size();
    for(int i = 0; i < size; i++) {
        cout << m[i] << " ";
    }
    cout << endl;
}

void Print(vector<vector<int>> matrix) {
    int size = matrix.size();
    for(int i = 0; i < size; i++) {
        Print(matrix[i]);
    }
}

void Transpose(vector<vector<int>>& matrix) {
    int size = matrix.size();
    for(int i = 0; i < size; i++) {
        for(int j = i; j < size; j++) {
            if(i != j) {
                int temp = matrix[j][i];
                matrix[j][i] = matrix[i][j];
                matrix[i][j] = temp;
            }
        }
    }
}

void FlipHoriztonal(vector<vector<int>>& matrix) {
    //flip horizontally
    int size = matrix.size();
    for(int i = 0; i < size; i++) {
        for(int j = 0; j < size/2; j++) {
            int oppIndex = size-j-1;
            int temp = matrix[i][oppIndex];
            matrix[i][oppIndex] = matrix[i][j];
            matrix[i][j] = temp;
        }
    }
}

int main() {
    vector<vector<int>> matrix = {{1,2,3},{4,5,6},{7,8,9}};

    Transpose(matrix);
    FlipHoriztonal(matrix);

    Print(matrix);
}