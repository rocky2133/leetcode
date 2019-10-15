#include <iostream>
#include <vector>

using namespace std;

int maxProfit(vector<int>& prices) {
	int min = INT_MAX;
	int profit = 0;
    for(int i=0;i<prices.size();i++){
    	if(prices[i]>min){
    		profit = (prices[i]-min)>profit?(prices[i]-min):profit;
    	}
    	else
    		min = prices[i];
    }
    return profit;
}

int main(){
	// int a[20] = {7,1,5,3,6,4};
	// vector<int> price(a, a+6);
	// cout<<maxProfit(price)<<endl;
	return 0;
}