#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int rob(vector<int>& nums){
	int pre1 = 0;
	int pre2 = 0;
	if(nums.size()==1)
		return nums[0];
	for(auto i=0;i<nums.size()-1;i++){
		int curr = max(pre1, pre2+nums[i]);
		pre2 = pre1;
		pre1 = curr;
	}
	int temp = pre1;
	pre1 = 0;
	pre2 = 0;
	for(auto i=nums.size()-1;i>0;i--){
		int curr = max(pre1, pre2+nums[i]);
		pre2 = pre1;
		pre1 = curr;
	}
	return max(pre1,temp);
}

int main(){
	vector<int> temp = {1,2,3,7};
	cout<<rob(temp)<<endl;
	return 0;
}