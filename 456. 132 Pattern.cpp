#include <iostream>
#include <vector>
#include <stdlib.h>
#include <stack>

using namespace std;

bool find132pattern(vector<int>& nums) {
    int second = INT_MIN;
    stack<int> stk;
    for(int i=nums.size()-1;i>=0;i--){
    	if(nums[i] < second)
    		return true;
    	while(!stk.empty() && nums[i] > stk.top()){
    		second = stk.top();
    		stk.pop();
    	}
    	stk.push(nums[i]);
    }
    return false;
}

int main(){
	int a[10] = {-1, 3, 2, 0};
	vector<int> nums(a,a+4);
	cout<<find132pattern(nums)<<endl;
	return 0;
}