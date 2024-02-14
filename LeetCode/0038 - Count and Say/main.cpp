#include <iostream>
#include <string>
using namespace std;

string numFromNum(string num) {
    if(num == "1") return "11";

    char curr = num[0];
    int numRepeats = 1;
    int index = 0;
    int len = num.length();

    string say = "";

    while(index < len) {
        if(curr == num[index+1] && index+1 < len){
            numRepeats++;
        } else {
            //add to string
            string temp = to_string(numRepeats) + curr;
            say.append(temp);

            //new num
            numRepeats = 1;
            curr = num[index+1];
        } 

        index++;
    }

    return say;
}

string countAndSay(int n) {
    string say = "1";
    if(n == 1) return say;

    for(int i = 1; i < n; i++) {
        say = numFromNum(say);
    }

    return say;
}

int main() {
    cout << countAndSay(4) << endl;

    return 0;
}