#include <iostream>
#include <string>
using std::string, std::cout, std::endl;

string convert(string s, int numRows) {
    if(!numRows || !s.length()) return s;

    int len = s.length();
    string zigzag = "";
    zigzag.push_back(s[0]);
    for(int i = 0; i < numRows; i++) {
        int index = 0;
        int step;

        while(index < len){
            step = (numRows*2)-2;
            if(!i) {
                index += step;
                zigzag.push_back(s[index]);
            } else if((i+1) % numRows == 0) {
                zigzag.push_back(s[index+i]);
                index += step;
            } else {
                int zagIndex = index + step - i;
                if(index+i < len) zigzag.push_back(s[index+i]);
                if(zagIndex < len) zigzag.push_back(s[zagIndex]);
                index += step;
            }
        }
       //zigzag.push_back('\n');
    }

    return zigzag;
}

int main() {
    cout << convert("PAYPALISHIRING", 3) << endl;
    cout << convert("PAYPALISHIRING", 4) << endl;
    return 0;
}