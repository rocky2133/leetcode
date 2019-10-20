#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

void per(vector<vector<int> > &ans, vector<int>& nums, vector<int>& curr, bool *flag){
	if(curr.size()==nums.size()){
		ans.push_back(curr);
		return;
	}
	for(auto i=0;i<nums.size();i++){
		if(!flag[i]){
			if(i && nums[i-1]==nums[i] && !flag[i-1])
				continue;
			flag[i] = true;
			curr.push_back(nums[i]);
			per(ans, nums, curr, flag);
			curr.pop_back();
			flag[i] = false;
		}
	}
}

vector<vector<int> > permuteUnique(vector<int>& nums) {
    vector<vector<int> > ans;
    vector<int> temp;
    if(nums.size()==0)
    	return ans;
    sort(nums.begin(),nums.end());
    bool *flag = new bool[nums.size()];
    for(auto i=0;i<nums.size();i++)
    	flag[i] = false;
    per(ans, nums, temp, flag);
    return ans;
}

int main(){
	vector<int> nums={1,1,2};
	vector<vector<int> > ans = permuteUnique(nums);
	for(auto i:ans){
		for(auto j:i){
			cout<<j<<" ";
		}
		cout<<endl;
	}
	return 0;
}