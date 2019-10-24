#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <math.h>

using namespace std;

int combinationSum4(vector<int>& nums, int target) {
	if(nums.size()==0)
		return 0;
    int *dp = new int[target+1];
    for(int i=1; i<=target; i++)
    	dp[i]=0;
    dp[0]=1;
    sort(nums.begin(), nums.end());
    for(int i=1; i<=target; i++){
    	for(auto num:nums){
    		if(num>i)
    			break;
    		dp[i] += dp[i-num];
    	}
    }
    return dp[target];
}

int main(){
	vector<int> nums = {3, 33, 333};
	cout<<combinationSum4(nums, 10000)<<endl;
	return 0;
}