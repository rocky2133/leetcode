#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>
#include <string>

using namespace std;

int minSteps1(int n) {
    int *dp = new int[n+1];
    dp[1] = 0;
    for(int i=2;i<=n;i++){
    	int min = i;
    	for(int j=2;j<=i/2;j++){
    		int k = dp[j]+i/j;
    		if(i%j==0 && k<min){
    			min = k;
    		}
    	}
    	dp[i] = min;
    }
    return dp[n];
}

int minSteps(int n) {
	int ans = 0;
	for(int i=2;i<=n;i++){
		while(n%i==0){
			ans+=i;
			n/=i;
		}
	}
	return ans;
}

int main(){
	cout<<minSteps(3)<<endl;
	return 0;
}