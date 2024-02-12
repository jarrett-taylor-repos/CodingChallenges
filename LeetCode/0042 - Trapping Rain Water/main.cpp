#include <iostream>
#include <string>
#include <vector>
using namespace std;

int Min(int a, int b) {
    if(a < b) return a;
    return b;
}

int trap(vector<int>& height) {
    int size = height.size();
    if(size <= 2) return 0;

    int trapped = 0;
    int leftMax = height[0];
    int rightMax = height[size-1];
    
    int i = 1;
    int j = size-2;

    while(i <= j) {
        int currHeight;
        if(leftMax < rightMax) {
            currHeight = height[i];
            if(currHeight >= leftMax) {
                leftMax = currHeight;
            } else {
                trapped += (leftMax - currHeight);
            }
            i++;
        } else {
            currHeight = height[j];
            if(currHeight >= rightMax) {
                rightMax = currHeight;
            } else {
                trapped += (rightMax - currHeight);
            }
            j--;
        }
    }

    return trapped;
}

int main() {
    vector<int> height = {0,1,0,2,1,0,1,3,2,1,2,1};

    cout << trap(height) << endl;

    return 0;
}