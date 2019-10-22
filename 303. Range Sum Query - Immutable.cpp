#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> nums;
vector<int> sums;

void sum(){
	if(nums.size()==0)
		return;
	int sum=0;
	for(int i=0;i<nums.size();i++){
		sum+=nums[i];
		sums.push_back(sum);
	}
}

int sumRange(int i, int j) {
    if(i==0)
    	return sums[j];
    else
    	return sums[j]-sums[i-1];
}

int main(){
	nums = {-2, 0, 3, -5, 2, -1};
	sum();
	cout<<sumRange(0, 5);
	return 0;
}