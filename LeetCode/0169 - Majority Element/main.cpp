#include <iostream>
#include <vector>
using namespace std;

int majorityElement(vector<int>& nums) {
    int currentValue = 0;
    int vote = 0;

    for(int i = 0; i < nums.size(); i++) {
        if(vote == 0) currentValue = nums[i];
        (nums[i] == currentValue) ? vote++ : vote--;
    }

    return currentValue;
}

int main() {
    vector<int> nums = {10,9,9,9,10};

    cout << majorityElement(nums) << endl;

    return 0;
}