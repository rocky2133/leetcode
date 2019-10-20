#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void sub(vector<vector<int> > &ans, vector<int>& nums, vector<int> &curr, int &index, int &num){
	if(curr.size()==num){
		ans.push_back(curr);
		return;
	}
	int tag = 0;
	if(index+1<nums.size())
		tag = nums[index+1]+1;
	for(int i=index+1;i<nums.size();i++){
		if(nums[i] == tag)
			continue;
		curr.push_back(nums[i]);
		sub(ans, nums, curr, i, num);
		tag = curr[curr.size()-1];
		curr.pop_back();
	}
}

vector<vector<int> > subsetsWithDup(vector<int>& nums) {
    vector<vector<int> > ans;
    vector<int> temp;
    if(nums.size()==0){
    	ans.push_back(temp);
    	return ans;
    }
    sort(nums.begin(),nums.end());
    int index = -1;
    for(int i=0;i<=nums.size();i++)
    	sub(ans, nums, temp, index, i);
    return ans;
}

int main(){
	vector<int> nums = {};
	vector<vector<int> > ans = subsetsWithDup(nums);
	for(auto i:ans){
		for(auto j:i){
			cout<<j<<" ";
		}
		cout<<endl;
	}
	return 0;
}