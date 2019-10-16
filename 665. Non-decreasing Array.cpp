#include <iostream>
#include <vector>

using namespace std;

bool checkPossibility(vector<int>& nums) {
    nums.insert(nums.begin(),INT_MIN);
    int cnt = 0;
    for(int i=1;i<nums.size()-1;i++){
    	if(nums[i]>nums[i+1]){
    		if(nums[i+1]<nums[i-1]){
	    		nums[i+1]=nums[i];
    		}
    		cnt++;
    	}
    }
    return cnt<=1;
}

int main(){
	int a[20] = {4,2,1};
	vector<int> nums(a,a+3);
	cout<<checkPossibility(nums)<<endl;
	return 0;
}