#include <iostream>
#include <vector>
#include <map>
using std::pair, std::map, std::vector, std::endl, std::cout;

bool canJump(vector<int>& nums) {
    int size = nums.size();
    if(size == 0) return false;
    if(size == 1) return true;
    int lastIndex = 0; 

    for(int i = size-1; i >= 0; i--) {
        bool canReach = nums[i] + i >= lastIndex;
        if(canReach) lastIndex = i;
    }

    return !lastIndex;
}

int main() {
    vector<int> v1 = {2,3,1,1,4};
    vector<int> v2 = {3,2,1,0,4};

    cout << canJump(v1) << endl;
    cout << canJump(v2) << endl;

    return 0;
}