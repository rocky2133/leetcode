#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>

using namespace std;

int lengthOfLIS(vector<int>& nums) {
    if(nums.size()==0)
    	return 0;
    int *dp = new int[nums.size()+1];
    dp[0] = 1;
    for(int i=1;i<nums.size();i++){
    	dp[i]=1;
    	for(int j=0;j<i;j++){
	    	if(nums[i]>nums[j] && dp[j]>=dp[i])
	    		dp[i] = dp[j]+1;
	    }
    }
    int max = 1;
    for(int i=1;i<nums.size();i++){
    	if(dp[i]>max)
    		max = dp[i];
    }
    return max;
}

int main(){
	vector<int> nums = {4,10,4,3,8,9};
	cout<<lengthOfLIS(nums)<<endl;
	return 0;
}