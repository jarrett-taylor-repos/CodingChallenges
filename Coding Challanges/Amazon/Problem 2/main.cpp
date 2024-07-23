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


long sumOfOneDay(int day) {
    int sum = 0;
    for(int i = day; i > 0; i++) {
        sum+=i;
    }
    return sum;
}

long getMaximumPoints(vector<int> days, int k) {
    int daysSize = days.size();
    int totalPoints = 0;
    int currDayIdx = 0;
    int maxDay = days[currDayIdx];
    for(int i = 0; i < daysSize; i++) {
        int elem = days[i];
        if(maxDay < elem) {
            maxDay = elem;
            currDayIdx = i;
        }
    }
    
    
    if(maxDay > k) {
        for(int i = maxDay; i > maxDay-k; i--) {
           totalPoints+=i; 
        }
        return totalPoints;
    }
    
    //if k is larger than the maxDay
    totalPoints = sumOfOneDay(maxDay);
    k -= maxDay;
    
    while(k > 0) {
        //iterate over until no more k 
        //traverse(left or right) and decrement k (with wrap around)
        int leftPtr = currDayIdx - 1;
        if(currDayIdx - 1 >= 0) {
            currDayIdx--;
        } else {
            currDayIdx = daysSize;
        }
        
        int value = days[currDayIdx];
        
        if(value > k) {
            for(int i = value; i > value-k; i--) {
                totalPoints+=i; 
            }
            return totalPoints;
        } else {
            totalPoints += sumOfOneDay(value);
            k-= value;
        }
    }
    
    return totalPoints;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string days_count_temp;
    getline(cin, days_count_temp);

    int days_count = stoi(ltrim(rtrim(days_count_temp)));

    vector<int> days(days_count);

    for (int i = 0; i < days_count; i++) {
        string days_item_temp;
        getline(cin, days_item_temp);

        int days_item = stoi(ltrim(rtrim(days_item_temp)));

        days[i] = days_item;
    }

    string k_temp;
    getline(cin, k_temp);

    int k = stoi(ltrim(rtrim(k_temp)));

    long result = getMaximumPoints(days, k);

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
