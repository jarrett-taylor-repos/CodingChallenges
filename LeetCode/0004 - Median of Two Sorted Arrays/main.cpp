#include <iostream>
#include <vector>
using namespace std;

bool isEven(int a) {
    return a % 2 == 0;
}

double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
    //needs to be log(m+n)
    int n = nums1.size();
    int m = nums2.size();
    if(n > m) return findMedianSortedArrays(nums2, nums1);

    int left = 0;
    int right = n;
    int trueMid = (n+m+1)/2;

    while(left <= right) {
        int mid = (left+right)/2;
        int left1Size = mid;
        int left2Size = trueMid - mid;
        int left1 = (left1Size > 0) ? nums1[left1Size-1] : INT_MIN;
        int left2 = (left2Size > 0) ? nums2[left2Size-1] : INT_MIN;
        int right1 = (left1Size < n) ? nums1[left1Size] : INT_MAX;
        int right2 = (left2Size < m) ? nums2[left2Size] : INT_MAX;

        if(left1 <= right2 && left2 <= right1) {
            int maxvalue = max(left1, left2);
            if(!isEven(m+n)) return maxvalue;

            int minvalue = min(right1, right2);
            return (maxvalue+minvalue)/2.0;
        } else if (left1 > right2) {
            right = mid - 1;
        } else {
            left = mid + 1;
        }
    }

    return 0.0;
}

int main() {
    vector<int> nums1 = {1,3};
    vector<int> nums2 = {2};
    cout << findMedianSortedArrays(nums1, nums2) << endl;

    return 0;
}