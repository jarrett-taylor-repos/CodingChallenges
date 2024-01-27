#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int Max(int a, int b) {
    if(a < b) return b;
    return a;
}

int Min(int a, int b) {
    if(a < b) return a;
    return b;
}

int solution(vector<int> &A) {
    // Implement your solution here
    int size = A.size();
    if(size <= 2) return 1;

    //sort the array in assending order
    //use left and right pointers, make pointer closer to middle if its difference with next node and start is greater
    //once left reaches right, if lenght is odd, return min of difference else max 
    sort(A.begin(), A.end());

    int left = 0; 
    int right = size-1;
    int leftStartValue = A[left];
    int rightStartValue = A[right];

    int leftDiff = 0;
    int rightDiff = 0;

    //middle distance point is found
    //leftstart-currleft < r
    //(leftStartValue-A[left-1] > A[left-1] - rightStartValue) ||(A[right+1] - rightStartValue > leftStartValue-A[right+1])
    while(
        (leftStartValue-A[left-1] > A[left-1] - rightStartValue)
        ||
        (A[right+1] - rightStartValue > leftStartValue-A[right+1])
    ) {
        int leftNext = A[left+1];
        int rightNext = A[right-1];

        int leftDiff = leftNext-leftStartValue;
        int rightDiff = rightStartValue-rightNext;

        //move closer to middle
        (leftDiff < rightDiff) ? right-- : left++;
    }

    leftDiff = A[left]-leftStartValue;
    rightDiff = rightStartValue-A[right];

    if((size-left) == (size-right)) { //checks to see how they are split up
        if(size % 2 == 0) { //if even length, longest board needed to cover gap 
            return Max(leftDiff, rightDiff);
        }
        return Min(leftDiff, rightDiff);
    }
    return Max(leftDiff, rightDiff);
}

int main() {
    vector<int> a = {11,20,15};
    vector<int> b = {15, 20, 9, 11};
    vector<int> c = {0,44,32,30,42,18,34,16,35};
    vector<int> d = {9};
    cout << solution(a) << endl;
    cout << solution(b) << endl;
    cout << solution(c) << endl;
    //cout << solution(d) << endl;
    return 0;
}