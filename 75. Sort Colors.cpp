#include <iostream>
#include <vector>

using namespace std;

void swap(vector<int>& nums, int a, int b){
	int temp = nums[a];
	nums[a] = nums[b];
	nums[b] = temp;
}

void sortColors(vector<int>& nums) {
    int p0 = 0, p2 = nums.size()-1, curr = 0;
    while(curr<=p2){
    	if(nums[curr]==0)
    		swap(nums, p0++, curr++);
    	else if(nums[curr]==2)
    		swap(nums, curr, p2--);
    	else
    		curr++;
    	for(int i=0;i<nums.size();i++)
			cout<<nums[i]<<" ";
		cout<<endl;
    }
}

int main(){
	int a[20] = {1,2,0};
	vector<int> nums(a, a+3);
	sortColors(nums);
	return 0;
}