#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>

using namespace std;

int change(int amount, vector<int>& coins) {
    int *dp = new int [amount+1];
    for(int i=1;i<=amount;i++){
    	dp[i]=0;
    }
    dp[0] = 1;
    for(auto val:coins){
    	for(int i=val; i<=amount; i++){
    		dp[i]+=dp[i-val];
    	}
    }
    return dp[amount];
}

int main(){
	vector<int> coins = {10};
	cout<<change(10, coins)<<endl;
	return 0;
}