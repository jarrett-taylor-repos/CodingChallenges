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


/*
Given 
days = [7, 2, 6, 4, 5]
k = 8
where days[i] is the number of races in a day 
each race on days[i] represent its value in points 

k = the number of consecutive races you can do 

GOAL: return the maximum number of points you can achieve

Notes:
 - you can start on any race on any day and end on any race on any day 
 - after you reach days[n] the , days repeats

EX. 

days = [2, 3, 2]
k = 4

day 0            |           day 1         |          day 2
race 1 race 2    |   race 1 race 2 race 3  |  race 1  race 2

            2   +        1   + 2 +    3    =   8


return 8 , being the maximum number of points
*/