#include <iostream>
#include <vector>

using namespace std;

int search(vector<int>& nums, int target) {
	int left = 0;
	int right = nums.size()-1;
	while(left<right){
		int mid = (left+right)/2;
		if((nums[left]<=target && target<=nums[mid])||(nums[mid]<nums[left] && nums[left]<=target)||(nums[mid]<nums[left] && nums[mid]>=target)){
			right=mid;
		}
		else{
			left=mid+1;
		}
	}
	return ((left==right)&&(nums[left]==target))?left:-1;
}

int main(){
	int a[10] = {5,1,3};
	vector<int>nums(a,a+3);
	cout<<search(nums, 3);
	return 0;
}