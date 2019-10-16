#include <iostream>
#include <vector>

using namespace std;

bool checkPossibility(vector<int>& nums) {
    nums.insert(nums.begin(),INT_MIN);
    int cnt = 0;
    for(int i=1;i<nums.size()-1;i++){
    	cout<<nums[i]<<", "<<nums[i+1]<<endl;
    	if(nums[i]>nums[i+1]){
    		if(nums[i+1]>=nums[i-1]){
    			if(cnt==0){
	    			cnt++;
	    		}
	    		else
	    			return false;
    		}
    		else{
    			if(cnt==0){
	    			cnt++;
	    			nums[i+1]=nums[i];
	    		}
	    		else
	    			return false;
    		}
    	}
    }
    return true;
}

int main(){
	int a[20] = {3,4,2,3};
	vector<int> nums(a,a+4);
	cout<<checkPossibility(nums)<<endl;
	return 0;
}