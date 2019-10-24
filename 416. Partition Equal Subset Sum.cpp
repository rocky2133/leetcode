#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>

using namespace std;

bool canPartition(vector<int>& nums) {
	int n=nums.size();
	if(n<2)
		return false;
    int sum=0;
    for(num:nums){
    	sum+=num;
    }
    cout<<sum<<endl;
    if(sum%2!=0)
    	return false;
    sum/=2;
    bool *dp = new bool[sum+1];
    for(int i=1;i<=sum;i++){
    	dp[i]=0;
    }
    dp[0] = 1;
    for(v:nums){
    	for(int j=sum;j>=v;j--){
    		dp[j]= dp[j] || dp[j-v];
    	}
    }
    cout<<dp[sum]<<endl;
    return dp[sum];
}

int main(){
	vector<int> temp = {17,58,41,75,61,70,52,7,38,11,40,58,44,45,4,81,67,54,79,80,15,3,14,16,9,66,69,41,72,37,28,3,33,90,56,12,72,49,35,22,49,27,49,82,41,77,100,82,18,95,24,51,37,2,34,82,70,53,73,32,90,98,81,22,73,76,79,40,27,62,45,96,36,15,63,28,54,88,63,37,58,9,62,98,93,72,99,53,91,29,61,31,11,42,20,35,50,68,10,86};
	cout<<canPartition(temp)<<endl;
	return 0;
}