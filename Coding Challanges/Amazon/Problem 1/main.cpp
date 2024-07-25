#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);



/*
 * Complete the 'reduceGifts' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts following parameters:
 *  1. INTEGER_ARRAY prices
 *  2. INTEGER k
 *  3. INTEGER threshold
 */

//dynamic programming problem? seems like memoization would be the value of k and threshold 
//potential backtracking with compliment of threshold - current value
//then see if k-1 with (threshold - current value) can exceed -> check memoization 
//if can exceed, remove highest value in chain and add to tally
//remove highest value until threshold can't be exceeded

int reduceGifts(vector<int> prices, int k, int threshold) {
}

int main() {
    return 0;
}

/*
Given 
gifts = [9, 7, 6, 2, 7, 2]
k = 2
threshold = 13

return the minimum number of elements to remove from gifts, such that the sum of any K elements is less than or equal to threshold


9 + 7 > 13
remove 9 
7 + 7 > 14
remove 7 
7 + 6 = 13

2 is the answer after removeing 9 and 7 
*/