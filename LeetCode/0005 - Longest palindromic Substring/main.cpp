#include <iostream>
#include <string>
using namespace std;


string longestPalindrome(string s) {  
    int length = s.length(); 
    if(length == 0) return "";
    if(length == 1) return s;

    int end = 1;
    int start = 0;
    int low = 0;
    int high = 0;

    for(int i = 0; i < length; i++) {
        low = i-1;
        high = i;

        while(low >= 0 && high < length && s[low] == s[high]) {
            int maxLength = high - low + 1;
            if(maxLength > end) {
                start = low;
                end = maxLength;
            }
            low--;
            high++;
        }

        low = i-1;
        high = i+1;

        while (low >= 0 && high < length && s[low] == s[high]) {
            int maxLength = high - low + 1;
            if (maxLength > end) {
                start = low;
                end = maxLength;
            }
            low--;
            high++;
        }
    }

    string ans = s.substr(start, end);

    return ans;
}

int main(){
    cout << longestPalindrome("babad") << endl;
    cout << longestPalindrome("cbbd") << endl;
    return 0;
}