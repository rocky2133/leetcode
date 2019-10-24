#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>

using namespace std;

int findTargetSumWays(vector<int>& nums, int S) {
    int sum=0;
    for(auto num:nums){
    	sum+=num;
    }
    if(sum<S || (sum+S)%2!=0)
    	return 0;
    int target = (sum+S)/2;
    int *dp = new int[target+1];
    for(int i=0;i<=target;i++)
    	dp[i]=0;
    dp[0] = 1;
    for(auto num:nums){
    	for(int j=target; j>=num; j--){
    		dp[j] += dp[j-num];
    	}
    }
    return dp[target];
}

int main(){

	return 0;
}