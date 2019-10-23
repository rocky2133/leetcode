#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>

using namespace std;

int numDecodings(string s) {
	if(s.length()<1)
		return s.length();
	if(s[0]=='0')
    	return 0;
    int *dp = new int[s.length()+1];
    dp[0] = 1;
    dp[1] = 1;
    for(int i=2;i<=s.length();i++){
    	if(s[i-1]=='0'){
    		if(s[i-2]=='0' || s[i-2]>'2')
    			return 0;
    		dp[i] = dp[i-2];
    	}
    	else if((s[i-2]=='1') || (s[i-2]=='2' && s[i-1]<='6')){
    		dp[i] = dp[i-1]+dp[i-2];
    	}
    	else 
    		dp[i] = dp[i-1];
    }
    return dp[s.length()];
}

int main(){
	cout<<numDecodings("17")<<endl;
	return 0;
}