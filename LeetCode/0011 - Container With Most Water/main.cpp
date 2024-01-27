#include <iostream>
#include <vector>
using namespace std;

int Min(int a, int b) {
    if(a > b) return b;
    return a;
}

int maxArea(vector<int> height) {
    int size = height.size();
    if(size == 2) {
        if(height[0] == 0 || height[1] == 0) return 0;
        if(height[0] < height[1]) return height[0];
        return height[1];
    }

    int max = 0;
    //use left and right pointer
    //calcuate area and then move left pointer if right value is higher, esle move right pointer 
    int l = 0;
    int r = height.size()-1;
    while(l != r) {
        int area = (r-l) * Min(height[l], height[r]);
        if(area > max) max = area;

        (height[l] < height[r]) ? l++ : r--;
    }
    return max;
}

int main() {
    vector<int> height = {1,8,6,2,5,4,8,3,7};

    cout << maxArea(height) << endl;
    return 0;
}