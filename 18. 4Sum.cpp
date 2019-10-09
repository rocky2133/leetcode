#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector< vector<int> > fourSum(vector<int>& nums, int target) {
	vector< vector<int> > ans;
	if(nums.size()<4)
		return ans;
	sort(nums.begin(), nums.end());
	int sum = 0;
	int a = 0;
	int b = a+1;
	int c = b+1;
	int d = nums.size()-1;
	for(a=0;a<nums.size()-3;a++){
		if(a>0 && nums[a] == nums[a-1])
			continue;
		for(b=a+1;b<nums.size()-2;b++){
			if(b>a+1 && nums[b] == nums[b-1])
				continue;
			c=b+1;
			d=nums.size()-1;
			while(c<d){
				sum = nums[a] + nums[b] + nums[c] + nums[d];
				if(sum == target){
					int t[4] = {nums[a], nums[b], nums[c], nums[d]};
					vector<int> temp(t, t+4);
					ans.push_back(temp);
					while(c<d && nums[c+1]==nums[c])
						c++;
					while(c<d && nums[d-1]==nums[d])
						d--;
					c++;
					d--;
				}
				else if(sum < target){
					c++;
				}
				else{
					d--;
				}
			}
		}
	}
	return ans;
}

int main(){
	int a[8] = {-3,-2,-1,0,0,1,2,3};
	vector<int> nums(a, a+8);
	vector< vector<int> > ans = fourSum(nums, 0);
	for(int i=0;i<ans.size();i++){
		for(int j=0;j<ans[i].size();j++){
			cout<<ans[i][j]<<" ";
		}
		cout<<endl;
	}
	return 0;
}