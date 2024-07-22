#include <iostream>
#include <vector>
using std::vector, std::endl, std::cout;

void print(vector<int> vect) {
    for(int elem : vect) {
        cout << elem << " ";
    }
    cout << endl;
}


vector<int> spiralOrder(vector<vector<int>>& matrix) {
    
}

int main() {
    vector<vector<int>> m1 = {{1,2,3},{4,5,6},{7,8,9}};
    print(spiralOrder(m1));
}

/*
    Start with top row 
        -> turn matrix 90 degreess count clock wise 

*/