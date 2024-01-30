#include <iostream>
#include <vector>
using namespace std;

void Print(vector<int> vect) {
    for(int elem : vect) {
        cout << elem << " ";
    }
    cout << endl << endl;
} 

vector<int> binarySearch(vector<int>& nums, int target, int startIdx, int endIdx) {
    if(endIdx - startIdx == 1 && nums[startIdx] != target && nums[endIdx] != target) return {-1, -1};
    //binary search for element 
    int size = endIdx-startIdx + 1;
    int mid = size/2;
    if(nums[mid] > target) {//need first half of array (0, mid)
        return binarySearch(nums,target, startIdx, mid);
    } else if (nums[mid] < target) { //need second half of array //(mid, end)
        return binarySearch(nums,target, mid, endIdx);
    } else { // if nums[mid] == target
        vector<int> indexes;
        //check left side and see first index
        int index = mid;
        while(nums[index] == target && index >= 0) {
            index--;
        }
        indexes.push_back(index+1);

        //check right side and see last index
        index = mid;
        while(nums[index] == target && index < nums.size()) {
            index++;
        }
        indexes.push_back(index-1);

        return indexes;
    }
}


vector<int> searchRange(vector<int>& nums, int target) {
    if(nums.size() == 0 || target < nums[0] || target > nums[nums.size()-1]) return {-1, -1};

    if(nums.size() == 1) {
        if(nums[0] == target) return {0, 0};
        return {-1, -1};
    }
    
    return binarySearch(nums, target, 0, nums.size()-1);
}

int main(){
    vector<int> test = {5,7,7,8,8,10};
    int target = 10;

    vector<int> solution = searchRange(test, target);
    Print(solution);

    return 0;
}