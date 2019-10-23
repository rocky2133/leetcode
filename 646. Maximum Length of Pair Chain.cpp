#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>

using namespace std;

static bool mysort(const vector<int> &t1, const vector<int> &t2){
    if(t1[0]==t2[0])
        return t1[1]<t2[1];
    return t1[0]<t2[0];
}

int findLongestChain(vector<vector<int>>& nums) {
    if(nums.size()==0)
    	return 0;
    sort(nums.begin(), nums.end(), mysort);
    int *dp = new int[nums.size()+1];
    dp[0] = 1;
    for(int i=1;i<nums.size();i++){
    	dp[i]=1;
    	for(int j=0;j<i;j++){
	    	if(nums[i][0]>nums[j][1] && dp[j]>=dp[i])
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
	vector<vector<int> > nums = {{3,4},{2,3},{1,2}};
	cout<<findLongestChain(nums)<<endl;
	return 0;
}