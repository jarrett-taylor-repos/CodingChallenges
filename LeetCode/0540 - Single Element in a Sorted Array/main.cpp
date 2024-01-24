#include <iostream>
#include <vector>
using namespace std;

#define AreEqual(a, b) (a == b)
#define AreNotEqual(a, b) (a != b)
#define EvenDiff(a, b) (((a - b) % 2) == 0)

int BinarySearch(vector<int> vect, int left, int right) {
    int mid = (left+right)/2;
    int midVal = vect[mid];
    bool isSingleElem = AreNotEqual(midVal, vect[mid-1]) && AreNotEqual(midVal, vect[mid+1]);
    if(isSingleElem) return midVal;

    //need to chekc if left or right side of tree, see which side is even and traversal the other ie 4-2 = 2 thus no odd single elem on that side 
    if(EvenDiff(right,mid)) return BinarySearch(vect, left, mid);
    return BinarySearch(vect, mid, right);
} 

int WhileSearch(vector<int> test, int left, int right) {
    while(left < right) { 
        int mid = (right + left)/2;
        if(AreEqual(test[mid], test[mid-1])) {
            EvenDiff(right, mid) ? right -= 2 : left +=1;
        } else if (AreEqual(test[mid], test[mid+1])) {
            EvenDiff(mid, left) ? left += 2 : right -=1;
        } else {
            return test[mid];
        }
    }
    return test[left];
}

int main() {
    vector<int> test = {1,1,2,3,3,4,4,8,8}; //output 2
    int left = 0;
    int right = test.size()-1;
    cout << BinarySearch(test, left, right) << endl;
    cout << WhileSearch(test, left, right) << endl;
}