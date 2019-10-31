#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>
#include <string>
#include <map>

using namespace std;

int minMoves2(vector<int>& nums) {
	sort(nums.begin(), nums.end());
    int i=0;
    int j=nums.size()-1;
    int ans = 0;
    while(i<j){
    	ans += nums[j--]-nums[i++];
    }
    return ans;
}

int main(){
	vector<int> temp = {1};
	cout<<minMoves2(temp)<<endl;
	return 0;
}