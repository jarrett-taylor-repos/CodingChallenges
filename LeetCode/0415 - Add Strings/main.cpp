#include <iostream>
#include <string>
using namespace std;

int Adder(string num1, string num2, bool carryover, int i, int j) {
    int test1 = i >= 0 ? num1[i]-'0' : 0;
    int test2 = j >= 0 ? num2[j]-'0' : 0;
    int total = carryover ? test1+test2+1 : test1+test2;
    return total;
}

string AddStrings(string num1, string num2) { 
    int i = num1.size()-1;
    int j = num2.size()-1;
    int carryover = 0;
    string result = "";
    while(i >= 0 || j >= 0) {
        int adder = Adder(num1, num2, carryover, i, j);
        carryover = adder/10;
        int value = adder%10;
        string str_value = to_string(value);
        result.insert(0, str_value);
        j--, i--;
    }

    if(carryover) result.insert(0,"1");

    return result; 
}

int main() {
    string num1 = "11";
    string num2 = "123";

    cout << AddStrings(num1, num2); 
}