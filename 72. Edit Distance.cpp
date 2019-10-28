#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>
#include <string>

using namespace std;

int minDistance(string word1, string word2) {
    int len1 = word1.length();
    int len2 = word2.length();
    int **dp = new int*[len1+1];
    for(int i=0;i<=len1;i++){
    	dp[i]=new int[len2+1];
    	dp[i][0]=i;
    	for(int j=1;j<=len2;j++){
    		dp[i][j]=0;
    	}
    }
    for(int i=0;i<=len2;i++){
    	dp[0][i]=i;
    }
    for(int i=1;i<=len1;i++){
    	for(int j=1;j<=len2;j++){
    		if(word1[i-1] != word2[j-1])
    			dp[i][j] = min(min(dp[i-1][j],dp[i][j-1]), dp[i-1][j-1])+1;
    		else
    			dp[i][j] = dp[i-1][j-1];
    	}
    }
    return dp[len1][len2];
}

int main(){
	cout<<minDistance("horse", "ros")<<endl;
	return 0;
}