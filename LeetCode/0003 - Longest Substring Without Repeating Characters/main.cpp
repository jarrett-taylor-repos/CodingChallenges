#include <iostream>
#include <string>
#include <set>
using namespace std;

int lengthOfLongestSubstring(string s) {
    //sliding windows algo
    //start at left most and move right until a repeat caharcter is found
    //save that value and then move left pointer to first instance of the repeated character
    if(s.length() < 2) return s.length();


    set<char> letters;

    int longest = 0;
    int i = 0;
    int j = 0;

    while(i < s.length()) {
        char c = s[i];
        while(letters.find(c) != letters.end()) {
            letters.erase(s[j]);
            j++;
        }
        letters.insert(c);
        int temp = i - j + 1;
        if(temp > longest) longest = temp;
        i++;
    }
    return longest;
}

int main() {
    string s = "pwwkew";
    cout << lengthOfLongestSubstring(s) << endl;
    return 0;
}