#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <map>
#include <stack>
using namespace std;

int solution(vector<int> &T) {
    // Implement your solution here
    if(T.size() == 0) return 0;
    if(T.size() == 1) return T[0];

    queue<int> times;
    int currentTime = 0;
    int totalTime = 0;

    //need to push the first values into queue
    for(int i = 0; i < T.size(); i++) {
        int hours = T[i];
        if(T[i] == 1) {
            currentTime++;
            totalTime += currentTime;
        } else{
            times.push(T[i]-1);
            currentTime++;
        }
    }

    //now to use while loop to iterate over all remaning times
    while(!times.empty()) {
        //get top, if 1 pop
        //else decemrent and move to back of queue
        int top = times.front();
        times.pop();
        if(top == 1) {
            currentTime++;
            totalTime += currentTime;
        } else {
            times.push(top-1);
            currentTime++;
        }
    }

    return totalTime;
}

int main() {
    vector<int> T = {3, 1, 2};
    cout << solution(T) << endl;
    return 0;
}