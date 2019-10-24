#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>

using namespace std;

int wiggleMaxLength(vector<int>& nums) {
    if(nums.size()<2)
    	return nums.size();
    int *dp = new int[nums.size()+1];
    int loc=0;
    while(loc<nums.size()-1 && nums[loc]==nums[loc+1]){
    	loc++;
    }
    if(loc==nums.size()-1)
    	return 1;
    dp[loc] = 1;
    dp[loc+1] = 2;
    bool sign = nums[loc]>nums[loc+1]?0:1;
 	// if sign = 0, last is negative, nums[m] > nums[n], current should be positive, if(nums[i]>nums[n])
 	// if sign = 1, last is positive, nums[m] < nums[n], current should be negative, if(nums[i]<nums[n])
    int comp = nums[loc+1];
    for(int i=loc+2;i<nums.size();i++){
    	if((!sign && nums[i]>comp) || (sign && nums[i]<comp)){
			dp[i] = dp[i-1]+1;
			sign = !sign;
		}
		else{
    		dp[i] = dp[i-1];
		}
    	comp = nums[i];
    }
    return dp[nums.size()-1];
}

int main(){
	vector<int> nums = {0,0};
	cout<<wiggleMaxLength(nums)<<endl;
	return 0;
}