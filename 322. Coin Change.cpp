#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>

using namespace std;

int coinChange(vector<int>& coins, int amount) {
    int *dp = new int [amount+1];
    for(int i=1;i<=amount;i++){
    	dp[i]=amount+1;
    }
    dp[0] = 0;
    for(auto val:coins){
    	for(int i=val; i<=amount; i++){
    		dp[i]=min(dp[i-val]+1, dp[i]);
    	}
    }
    return dp[amount]>amount?-1:dp[amount];
}

int main(){
	vector<int> coins = {2, 5};
	cout<<coinChange(coins, 6)<<endl;
	return 0;
}