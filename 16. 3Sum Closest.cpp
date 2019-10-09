#include <iostream>
#include <vector>
#include <math.h>
#include <stdlib.h>
#include <algorithm>

using namespace std;

int threeSumClosest(vector<int>& nums, int target) {
	if(nums.size()<3)
		return -1;
	sort(nums.begin(), nums.end());
	int minimum = nums[0] + nums[1] + nums[2] - target;
	for(int i=0;i<nums.size()-2;i++){
		int left = i + 1;
		int right = nums.size()-1;
		int min = nums[i] + nums[left] + nums[left+1];
		int max = nums[i] + nums[right] + nums[right-1];
		if(min > target){
			cout<<1<<endl;
			if(abs(min-target) < abs(minimum))
				minimum = min-target;
			break;
		}
		else if(max < target){
			cout<<2<<endl;
			if(abs(max-target) < abs(minimum))
				minimum = max-target;
			continue;
		}
		else{
			cout<<3<<endl;
			while(left<right){
				int sum = nums[i] + nums[left] + nums[right];
				if(abs(sum-target)<abs(minimum))
					minimum = sum-target;
				if(sum < target)
					left++;
				else
					right--;
			}
		}
	}
	return minimum+target;
}

int main(){
	int a[4] = {-1, 2, 1, -4};
	vector<int> nums(a, a+4);
	cout<<threeSumClosest(nums, -5)<<endl;
	return 0;
}