#include <iostream>
#include <string>
using std::string, std::cout, std::endl;

string convert(string s, int numRows) {
    if(!s.length() || numRows < 2) return s;

    int len = s.length();
    string zigzag = "";
    for(int i = 0; i < numRows; i++) {
        int index = 0;
        int step;

        while(index < len){
            step = (numRows*2)-2;
            if(!i) {
                zigzag.push_back(s[index]);
            } else if((i+1) % numRows == 0) {
                if(index+i < len) zigzag.push_back(s[index+i]);
            } else {
                int zagIndex = index + step - i;
                if(index+i < len) zigzag.push_back(s[index+i]);
                if(zagIndex < len) zigzag.push_back(s[zagIndex]);
            }
            index += step;
        }
    }

    return zigzag;
}

int main() {
    cout << convert("AB", 2) << endl;
    cout << convert("PAYPALISHIRING", 3) << endl;
    cout << convert("PAYPALISHIRING", 4) << endl;
    return 0;
}