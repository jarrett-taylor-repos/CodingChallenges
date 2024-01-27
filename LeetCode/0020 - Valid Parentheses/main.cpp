#include <iostream>
#include <string>
#include <stack>
#include <map>
using namespace std;

map<char, char> matchingBracket = { 
    {'}', '{'},
    {']', '['},
    {')', '('},
};

bool IsClosingChar(char c) {
    return (c == '}') || (c == ']') || (c==')');
}

bool IsCorrectParen(char c, char topChar) {
    return matchingBracket[c] == topChar;
}


bool isValid(string s) {
    if(s.size() % 2 != 0) return false;

    //stack to keep track of items
    stack<char> paren;       
    for(int i = 0; i < s.length(); i++) {
        char c = s[i];
        if(IsClosingChar(c)){
            if(paren.size() == 0) return false;
            char topChar = paren.top();
            if(IsCorrectParen(c, topChar)) {
                paren.pop();
            } else {
                return false;
            }

        } else {
            paren.push(c);
        }
    }
    return paren.size() == 0;
}

int main() {
    string s = ")[";

    cout << isValid(s) <<endl;

    return 0;
}