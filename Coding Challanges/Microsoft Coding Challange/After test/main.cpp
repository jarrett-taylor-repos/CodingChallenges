#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>
using namespace std;

int Max(int a, int b) {
    if(a < b) return b;
    return a;
}

int Min(int a, int b) {
    if(a < b) return a;
    return b;
}


int solution(vector<int> vect) {
    int size = vect.size();
    if(size <= 2) return 1;

    int min = vect[0];
    int max = vect[0];

    for(int i = 1; i < size; i++) {
        int elem = vect[i];
        if(elem < min) min = elem;
        if(elem > max) max = elem;
    }

    int diff = max - min;
    int maxLength = (diff/2) + 1;

    int numClosestToMaxLenght = max;
    int minDiff = maxLength;

    for(int i = 0; i < size; i++) {
        int elem = vect[i];
        int diffToMaxLength = abs(maxLength+min-elem); 
        if(diffToMaxLength < minDiff) {
            numClosestToMaxLenght = elem;
            minDiff = diffToMaxLength;
        }
    }

    return Min(abs(max-numClosestToMaxLenght), abs(min-numClosestToMaxLenght));
}

int main() {
    vector<int> a = {11,20,15};
    vector<int> b = {15, 20, 9, 11};
    vector<int> c = {0,44,32,30,42,18,34,16,35};
    vector<int> d = {9};
    cout << solution(a) << endl;
    cout << solution(b) << endl;
    cout << solution(c) << endl;
    cout << solution(d) << endl;
    return 0;
}