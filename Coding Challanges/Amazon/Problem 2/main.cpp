#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);



/*
 * Complete the 'getMaximumPoints' function below.
 *
 * The function is expected to return a LONG_INTEGER.
 * The function accepts following parameters:
 *  1. INTEGER_ARRAY days
 *  2. INTEGER k
 */
 


//likely a sliding window question with maximizing an area

//start with highest number of days then move left or right dpeending which value is higher (i think this could be potentially faulty, maybe max sum between elements based on k should be driver of the question)
//if left and right are the same, go one more down the path (left -> left and right -> right) and choose higher value
//left right still needs back tracking for large numbers with large amount of elements 
long getMaximumPoints(vector<int> days, int k) {

}

int main() {

    return 0;
}