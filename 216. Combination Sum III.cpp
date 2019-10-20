#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void comb(vector<vector<int> > &ans, vector<int> &curr, int &currsum, int &k, int &target){
	if(curr.size()==k){
		if(currsum==target){
			ans.push_back(curr);
			return;
		}
		return;
	}
	int st = 9;
	if(curr.size())
		st = curr[curr.size()-1]-1;
	for(int i=st;i>0;i--){
		if(i+currsum<=target){
			curr.push_back(i);
			currsum+=i;
			comb(ans,curr,currsum,k,target);
			currsum-=i;
			curr.pop_back();
		}
	}
}

vector<vector<int> > combinationSum3(int k, int n) {
    vector<vector<int> > ans;
    vector<int> temp;
    if(n<1 || k<1)
    	return ans;
    int sum = 0;
    comb(ans, temp, sum, k, n);
    return ans;
}

int main(){
	vector<vector<int> > ans = combinationSum3(3, 9);
	for(auto i:ans){
		for(auto j:i){
			cout<<j<<" ";
		}
		cout<<endl;
	}
	return 0;
}