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
	int tag = -1;
	for(int i=index+1;i<candidates.size();i++){
		// cout<<candidates[i]<<endl;
		if(candidates[i]+currsum<=target && tag != candidates[i]){
			curr.push_back(candidates[i]);
			currsum+=candidates[i];
			comb(ans, candidates, curr, currsum, i, target);
			currsum-=candidates[i];
			tag = curr[curr.size()-1];
			curr.pop_back();
		}
	}
}

vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
	vector<vector<int> > ans;
	vector<int> temp;
    if(candidates.size()==0)
    	return ans;
    sort(candidates.begin(),candidates.end(),greater<int>());
    int sum = 0;
    int index = -1;
    comb(ans, candidates, temp, sum, index, target);
    return ans;
}

int main(){
	vector<int> cand={5};
	vector<vector<int> > ans = combinationSum2(cand, 5);
	for(auto i:ans){
		for(auto j:i){
			cout<<j<<" ";
		}
		cout<<endl;
	}
	return 0;
}