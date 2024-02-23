#include <iostream>
#include <vector>
using std::vector, std::endl, std::cout;

int min(int a, int b) {
    if(a < b) return a;
    return b;
}

int max(int a, int b) {
    if(a < b) return b;
    return a;
}

int jump(vector<int>& nums) {
    int size = nums.size();
    if(size < 2) return size;

    int left = 0;
    int right = 0;
    int numJumps = 0;

    while(right < size-1) {
        int maxDistance = 0;
        for(int i = left; i < right+1; i++) {
            int currDistance = i + nums[i];
            maxDistance = max(maxDistance, currDistance);
        }
        left = right+1;
        right = maxDistance;
        numJumps++;
    }

    return numJumps;
}


int main() {
    vector<int> v1 = {2,3,1,1,4};
    vector<int> v2 = {2,3,0,1,4};

    cout << jump(v1) << endl;
    cout << jump(v2) << endl;
    return 0;
}