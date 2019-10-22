#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int numberOfArithmeticSlices(vector<int>& A) {
	int n = A.size();
	if(n<3)
		return 0;
    int *dp = new int[n];
    dp[1] = 0;
    int add = 0;
    for(int i=2;i<n;i++){
    	if(A[i]-A[i-1]==A[i-1]-A[i-2]){
    		add++;
    		dp[i] = dp[i-1]+add;
    	}
    	else{
    		add=0;
    		dp[i] = dp[i-1];
    	}
    }
    return dp[n-1];
}

int main(){
	vector<int> A = {3, -1};
	cout<<numberOfArithmeticSlices(A);
	return 0;
}