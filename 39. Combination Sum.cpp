#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

void comb(vector<vector<int> > &ans, vector<int>& candidates, vector<int> &curr, int &currsum, int &index, int &target){
	if(currsum == target){
		ans.push_back(curr);
		return;
	}
	for(int i=index;i<candidates.size();i++){
		// cout<<candidates[i]<<endl;
		if(candidates[i]+currsum<=target){
			curr.push_back(candidates[i]);
			currsum+=candidates[i];
			comb(ans, candidates, curr, currsum, i, target);
			currsum-=candidates[i];
			curr.pop_back();
		}
	}
}

vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
	vector<vector<int> > ans;
	vector<int> temp;
    if(candidates.size()==0)
    	return ans;
    sort(candidates.begin(),candidates.end(),greater<int>());
    int sum = 0;
    int index = 0;
    comb(ans, candidates, temp, sum, index, target);
    return ans;
}

int main(){
	vector<int> cand={9};
	vector<vector<int> > ans = combinationSum(cand, 8);
	for(auto i:ans){
		for(auto j:i){
			cout<<j<<" ";
		}
		cout<<endl;
	}
	return 0;
}