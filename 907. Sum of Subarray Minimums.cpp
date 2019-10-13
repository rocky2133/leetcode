#include <iostream>
#include <vector>
#include <stack>

using namespace std;

int sumSubarrayMins(vector<int>& A) {
	stack<int> stk;
	int nums = A.size();
	int *len = new int[nums];
	int ans = 0;
	for(int i=0;i<nums;i++){
		while(!stk.empty() && A[i]<A[stk.top()]){
			stk.pop();
		}
		if(stk.empty())
			len[i] = -1;
		else
			len[i] = stk.top();
		stk.push(i);
	}
	while(!stk.empty())
		stk.pop();
	for(int i=nums-1;i>=0;i--){
		while(!stk.empty() && A[i]<=A[stk.top()]){
			stk.pop();
		}

		if(stk.empty()){
			len[i] = (nums-i)*(i-len[i]);
		}
		else
			len[i] = (stk.top()-i)*(i-len[i]);
		// cout<<i<<" "<<len[i]<<endl;
		ans += A[i] * len[i];
		if(ans >= 1000000007)
			ans -= 1000000007;
		stk.push(i);
	}
	return ans;
}

int main(){
	int a[10] = {71,55,82,55};
	vector<int> num(a,a+4);
	cout<<sumSubarrayMins(num)<<endl;
	return 0;
}