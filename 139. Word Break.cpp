#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <math.h>

using namespace std;

bool equ(string &s, string& word, int start){
	for(int i=0; i<word.length(); i++){
		if(s[start+i]!=word[i])
			return false;
	}
	return true;
}

bool wordBreak(string s, vector<string>& wordDict) {
	int n=s.length();
    bool *dp = new bool[n+1];
    for(int i=1;i<=n;i++)
    	dp[i] = false;
    dp[0] = true;
    for(int i=1; i<=n;i++){
	    for(auto word:wordDict){
	    	int nw = word.length();
    		if(i>=nw && equ(s, word, i-nw)){
    			dp[i] = dp[i] || dp[i-nw];
    		}
    	}
    }
    return dp[n];
}

int main(){
	vector<string> temp = {"apple", "pen"};
	string s = "applepenapple";
	cout<<wordBreak(s, temp)<<endl;
	return 0;
}