#include <iostream>
#include <vector>
using std::vector, std::cout, std::endl;

bool isBetween(int target, int low, int high) {
    return low < target && target < high; 
}

int getRowIndex(vector<vector<int>>& matrix, int target, int start, int end) {
    int numOfRows = matrix.size();
    if(!numOfRows) return -1;
    if(numOfRows == 1) return 0;
    if(numOfRows == 2) return (matrix[1][0] <= target) ? 1: 0;

    while(start < end) {
        int mid = start + (end - start)/2;
        int elem = matrix[mid][0];
        if(!mid) return 0;

        if(elem == target) return mid;

        int compareElem = elem < target ? matrix[mid+1][0] : matrix[mid-1][0];
        if(compareElem == target) return (elem < target) ? mid+1: mid-1;

        bool foundLow = isBetween(target, compareElem, elem);
        bool foundHigh = isBetween(target, elem, compareElem);

        if(foundLow) return mid-1;
        if(foundHigh) return mid;


        if(elem < target) {
            start = mid+1;
        } else {
            end = mid-1;
        }
    }

    if(start == end) return start;

    return -1;
}

bool columnSearch(vector<int> search, int target, int rowIndex) {
    if(!search.size()) return false;
    if(search.size()==1){
        return (search[0] == target);
    } else if (search.size()==2) {
        return search[0] == target || search[1] == target;
    }

    int start = 0;
    int end = search.size()-1;

    while(start < end) {
        int mid = start + (end - start)/2;
        int elem = search[mid];

        if(elem == target) return true;
        if(elem < target) {
            start = mid+1;
        } else {
            end = mid-1;
        }
    }

    if(start == end) return search[start] == target;

    return false;
}


bool searchMatrix(vector<vector<int>>& matrix, int target) {
    int matRows = matrix.size()-1;
    int matCols = matrix[0].size()-1;
    if(target < matrix[0][0] || target > matrix[matRows][matCols]) return false;

    int rowIndex = getRowIndex(matrix, target, 0, matrix.size()-1);
    if(rowIndex == -1) return false; 

    return columnSearch(matrix[rowIndex], target, rowIndex);
}

int main() {
    vector<vector<int>> m1 = {{1,3,5,7},{10,11,16,20},{23,30,34,60}};
    vector<vector<int>> m2 = {{1},{3},{5}};

    //cout << searchMatrix(m1, 3) << endl;
    //cout << searchMatrix(m1, 13) << endl;
    //cout << searchMatrix(m2, 5) << endl;
    cout << searchMatrix(m1, 24) << endl;
}