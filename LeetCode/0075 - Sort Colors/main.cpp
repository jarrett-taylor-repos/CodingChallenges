#include <iostream>
#include <vector>
#include <array>
using std::vector, std::cout, std::endl, std::swap;

void print(vector<int>& nums) {
    for(int i = 0; i < nums.size(); i++) {
        cout << nums[i];
        if(i+1 != nums.size()) cout << ", ";
    }
    cout << endl;
}

void sortColors(vector<int>& nums) {
    if(nums.size() < 2) return;
    int zeroIndex = 0;
    int twoIndex = nums.size()-1;

    int currIndex = 0;
    while(currIndex <= twoIndex) {
        int elem = nums[currIndex];
        if(!elem) {
            swap(nums[currIndex], nums[zeroIndex]);
            currIndex++;
            zeroIndex++;
        } else if(elem == 1) {
            currIndex++;
        } else {
            swap(nums[currIndex], nums[twoIndex]);
            twoIndex--;
        }
    }

    return;
}

int main() {
    vector<int> v1 = {2,0,2,1,1,0};
    vector<int> v2 = {2, 0};
    //sortColors(v1); print(v1);
    sortColors(v2); print(v2);
    return 0;
}