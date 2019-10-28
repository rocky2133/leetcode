#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>
#include <string>

using namespace std;

int smallestRangeII(vector<int>& A, int K) {
	int n=A.size();
	if(n<=1)
		return 0;
	sort(A.begin(), A.end());
	int ans = A[n-1]-A[0];
    for(int i=0; i<n-1; i++){
    	int right = max(A[i]+K, A[n-1]-K);
    	int left = min(A[i+1]-K, A[0]+K);
    	ans = min(ans, right-left);
    }
    return ans;
}

int main(){
	vector<int> temp = {2,3,4,5,5};
	cout<<smallestRangeII(temp, 1)<<endl;
	return 0;
}