#include <iostream>
#include <string>
#include <vector>
using namespace std;


int firstUniqueChar(string s) {
    if(s.size() == 0) return -1;
    if(s.size() == 1) return 0;

    vector<int> freq(26);
    for(int i = 0; i < s.size(); i++) {
        int index = s[i] - 'a';
        freq[index]++;
    }

    for(int i = 0; i < s.size(); i++) {
        int index = s[i] - 'a';
        if(freq[index] == 1) return i;
    }

    return -1;
}

int main() {
    string s = "leetcode";
    string s2 = "loveleetcode";
    string s3 = "aabb";

    cout << firstUniqueChar(s) << endl;
    cout << firstUniqueChar(s2) << endl;
    cout << firstUniqueChar(s3) << endl;

    return 0;
}