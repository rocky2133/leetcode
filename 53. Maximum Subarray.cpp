#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int maxSubArray(vector<int>& nums) {
	if(nums.size()==0)
		return 0;
    int sum = 0;
    int ans = nums[0];
    for(int i=0;i<nums.size();i++){
    	if(sum<0)
    		sum=nums[i];
    	else
    		sum+=nums[i];
    	ans=max(sum, ans);
    }
    return ans;
}

int main(){
	int a[20] = {-2,1,-3,4,-1,2,1,-5,4};
	vector<int> nums(a, a+9);
	cout<<maxSubArray(nums)<<endl;
	return 0;
}