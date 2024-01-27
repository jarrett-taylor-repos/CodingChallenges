#include <iostream>
#include <vector>
using namespace std;

bool IsNegativeOrGreaterThan(int val, int size) {
    if(val <= 0) return true;
    if(val > size) return true;
    return false;
}


int firstMissingPositive(vector<int>& nums) {
    if(nums.size()== 0) return 1;

    //on first loop get rid of all values larger than nums.size() and all negatives
    int size = nums.size();
    bool hasOne = false;
    for(int i= 0; i < size; i++) {
        if(nums[i] == 1) hasOne = true;
        if(IsNegativeOrGreaterThan(nums[i], size)) nums[i] = 1;
    }

    if(!hasOne) return 1;

    //use values in array to make negatives
    for(int i = 0; i < size; i++) {
        int val = nums[i];
        if(val < 0) val *= -1;
        val--;
        if(nums[val] > 0) nums[val] = -nums[val];
    }

    //grab first number that is non negative and return index + 1
    for(int i = 0; i < size; i++) {
        if(nums[i] > 0) return i+1;
    }

    return size+1;
}

int main() {
    vector<int> nums = {1,2,0};
    cout << firstMissingPositive(nums) << endl;
    return 0;
}