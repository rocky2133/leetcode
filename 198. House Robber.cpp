#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int rob1(vector<int>& nums) {
	int num = nums.size();
	if(num==1)
		return nums[0];
	if(num==2)
		return nums[0]>nums[1]?nums[0]:nums[1];
    int *cnt = new int [num];
    for(int i=0;i<num;i++)
    	cnt[i]=0;
    cnt[0] = nums[0];
    cnt[1] = nums[1];
    for(int i=2;i<num;i++){
    	cnt[i] = max(cnt[i-2]+nums[i], cnt[i-1]);
    }
    return cnt[num-1];
}

int rob(vector<int>& nums){
	int pre1 = 0;
	int pre2 = 0;
	for(auto i=0;i<nums.size();i++){
		int curr = max(pre1, pre2+nums[i]);
		pre2 = pre1;
		pre1 = curr;
	}
	return pre1;
}

int main(){
	vector<int> temp = {2,7,9,3,1};
	cout<<rob(temp)<<endl;
	return 0;
}