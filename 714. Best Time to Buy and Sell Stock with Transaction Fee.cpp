#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>
#include <string>

using namespace std;

int maxProfit(vector<int>& prices, int fee) {
	int n = prices.size();
    int nth = 0;
    int sell = 0;
    int preSell = 0;
    int hold = INT_MIN;
    for(auto prc:prices){
    	preSell = sell;
    	sell = hold+prc;
    	nth = max(nth, preSell);
    	hold = max(max(nth, sell)-prc-fee, hold);
    }
    return max(sell, nth);
}

int main(){
	vector<int> temp = {1, 3, 2, 8, 4, 9};
	cout<<maxProfit(temp, 2)<<endl;
	return 0;
}