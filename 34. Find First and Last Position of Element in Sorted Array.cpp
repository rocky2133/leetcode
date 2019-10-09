#include <iostream>
#include <vector>

using namespace std;

vector<int> searchRange(vector<int>& nums, int target) {
	int a[2] = {-1, -1};
	vector<int> ans(a, a+2);
	if(nums.size()==1){
		if(target==nums[0]){
			ans[0] = 0;
			ans[1] = 0;
		}
		return ans;
	}
	bool flag = true;
	for(int i=0;i<2;i++){
		int left = 0;
		int right = nums.size()-1;
		while(left<=right){
			int mid = (left+right)/2;
			if(nums[mid]>target)
				right = mid-1;
			else if(nums[mid]<target)
				left = mid+1;
			else{
				if(flag){
					if(mid>0 && nums[mid-1]!=nums[mid] || mid == 0){
						ans[0] = mid;
						break;
					}
					right = mid-1;
				}
				else{
					if(mid<nums.size()-1 && nums[mid+1]!=nums[mid] || mid == nums.size()-1){
						ans[1] = mid;
						break;
					}
					left = mid+1;
				}
			}
		}
		flag = false;
	}
	return ans;
}

int main(){
	int a[6] ={5,7,7,8,8,10};
	vector<int> nums(a, a+6);
	vector<int> ans = searchRange(nums, 6);
	for(int i=0;i<ans.size();i++)
		cout<<ans[i]<<" ";
	return 0;
}