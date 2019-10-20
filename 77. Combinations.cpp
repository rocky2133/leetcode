#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

void per(vector<vector<int> > &ans, vector<int>& curr, bool *flag, int &n, int &k){
	if(curr.size()==k){
		ans.push_back(curr);
		return;
	}
	int st = 0;
	if(curr.size())
		st=curr[curr.size()-1];
	for(auto i=st+1;i<=n;i++){
		if(!flag[i]){
			flag[i] = true;
			curr.push_back(i);
			per(ans, curr, flag, n, k);
			curr.pop_back();
			flag[i] = false;
		}
	}
}

vector<vector<int> > combine(int n, int k) {
    vector<vector<int> > ans;
    vector<int> temp;
    if(n==0 || k>n)
    	return ans;
    bool *flag = new bool[n+1];
    for(auto i=0;i<n+1;i++)
    	flag[i] = false;
    per(ans, temp, flag, n, k);
    return ans;
}

int main(){
	vector<int> nums={1,1,2};
	vector<vector<int> > ans = combine(3, 3);
	for(auto i:ans){
		for(auto j:i){
			cout<<j<<" ";
		}
		cout<<endl;
	}
	return 0;
}