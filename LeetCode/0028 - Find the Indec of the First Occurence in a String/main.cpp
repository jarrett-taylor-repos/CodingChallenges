#include <iostream>
#include <string>
using namespace std;

int strStr(string haystack, string needle) {
    int haystackSize = haystack.size();
    int needleSize = needle.size();
    if(needleSize == 0 || haystackSize == 0 || haystackSize < needleSize) {
        return -1;
    }

    int i = 0;
    while(i < haystackSize) {
        for(int j = 0; j < needleSize; j++) {
            bool match = (needle[j] == haystack[i+j]);
            if(!match) {
                i++;
                break;
            } 
            if(match && j == needleSize-1) return i; 
        }
    }

    return -1;
}

int main() {
    string haystack = "sadbutsad";
    string needle = "sad";

    cout << strStr(haystack, needle) << endl;
    cout << strStr("leetcode", "leeto") << endl;
    cout << strStr("testertemp", "temp") << endl;

    return 0;
}