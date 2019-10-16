#include <iostream>
#include <vector>

using namespace std;

int findMin(vector<int>& nums) {
    int left = 0, right = nums.size()-1;
    if(nums[left]<nums[right])
    	return nums[left];
    while(left<right-1){
    	int mid = left+(right-left)/2;
    	if(nums[left]<nums[mid])
    		left = mid;
    	if(nums[right]>nums[mid])
    		right = mid;
    }
    return min(nums[left], nums[right]);
}

int main(){
	int a[20] = {1,2,3};
	vector<int> nums(a,a+3);
	cout<<findMin(nums)<<endl;
	return 0;
}