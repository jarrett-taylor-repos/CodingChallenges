#include <iostream>
#include <vector>
using namespace std;

int maxProfit(vector<int>& prices) {
    int size = prices.size();
    if(size < 2) return 0;

    int buyPrice = prices[0];
    int maxProfit = 0;
    for(int i = 1; i < size; i++) {
        if(buyPrice > prices[i]) buyPrice = prices[i];
        else if(prices[i] - buyPrice > maxProfit) maxProfit = prices[i] - buyPrice;
    }
    return maxProfit;
}

int main() {
    vector<int> prices = {7,5,1};
    cout << maxProfit(prices) << endl;
    return 0;
}