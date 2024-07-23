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
 
int sumVect(vector<int> v) {
    int sum = 0;
    for(int i = 0 ; i < v.size(); i++) {
        sum += v[i];
    }
    return sum;
}

//dynamic programming problem? seems like memoization would be the value of k and threshold 
//potential backtracking with compliment of threshold - current value
//then see if k-1 with (threshold - current value) can exceed -> check memoization 
//if can exceed, remove highest value in chain and add to tally
//remove highest value until threshold can't be exceeded

int reduceGifts(vector<int> prices, int k, int threshold) {
}
int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string prices_count_temp;
    getline(cin, prices_count_temp);

    int prices_count = stoi(ltrim(rtrim(prices_count_temp)));

    vector<int> prices(prices_count);

    for (int i = 0; i < prices_count; i++) {
        string prices_item_temp;
        getline(cin, prices_item_temp);

        int prices_item = stoi(ltrim(rtrim(prices_item_temp)));

        prices[i] = prices_item;
    }

    string k_temp;
    getline(cin, k_temp);

    int k = stoi(ltrim(rtrim(k_temp)));

    string threshold_temp;
    getline(cin, threshold_temp);

    int threshold = stoi(ltrim(rtrim(threshold_temp)));

    int result = reduceGifts(prices, k, threshold);

    fout << result << "\n";

    fout.close();

    return 0;
}

string ltrim(const string &str) {
    string s(str);

    s.erase(
        s.begin(),
        find_if(s.begin(), s.end(), not1(ptr_fun<int, int>(isspace)))
    );

    return s;
}

string rtrim(const string &str) {
    string s(str);

    s.erase(
        find_if(s.rbegin(), s.rend(), not1(ptr_fun<int, int>(isspace))).base(),
        s.end()
    );

    return s;
}
