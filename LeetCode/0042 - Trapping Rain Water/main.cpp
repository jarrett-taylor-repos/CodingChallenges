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
    for(int i = 1; i < size-1; i++) {
        int currHeight = height[i];
        int leftMax = currHeight;
        int rightMax = currHeight;

        int index = i-1;
        while(index != -1) {
            int testValue = height[index];
            if(testValue >= leftMax) {
                leftMax = testValue;
            }
            index--;
        }

        index = i+1;
        while(index != size) {
            int testValue = height[index];
            if(testValue >= rightMax) {
                rightMax = testValue;
            }
            index++;
        }

        int maxAbleToStore = Min(leftMax, rightMax);
        int valueStored = maxAbleToStore - currHeight;
        trapped += valueStored;
    }

    return trapped;
}

int main() {
    vector<int> height = {0,1,0,2,1,0,1,3,2,1,2,1};

    cout << trap(height) << endl;

    return 0;
}