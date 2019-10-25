#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>
#include <string>

using namespace std;

int maxProfit1(vector<int>& prices) {
	int n = prices.size();
    int *dp = new int[n+2];
    int max=0;
    for(int i=0;i<=n;i++)
    	dp[i]=0;
    for(int i=1;i<n;i++){
    	max=0;
    	for(int j=i-1; j>=0; j--){
    		int temp = prices[i]-prices[j];
    		temp+=(j>2?dp[j-2]:0);
    		if(temp>max)
    			max = temp;
    		dp[i] = dp[i-1]>max?dp[i-1]:max;
    	}
    }
    max=0;
    for(int i=1;i<n;i++){
    	if(dp[i]>max)
    		max = dp[i];
    }
    return max;
}

int maxProfit(vector<int>& prices) {
	int hold=INT_MIN;
	int nth=0;
	int sell=0;
	int preSell=0;
	for(auto prc : prices){
		preSell = sell;
		sell = prc+hold;
		hold = max(hold, nth-prc);
		nth = max(nth, preSell);
	}
	return max(nth, sell);
}

int main(){
	vector<int> temp = {1,2,3,0,2};
	cout<<maxProfit(temp)<<endl;
	return 0;
}